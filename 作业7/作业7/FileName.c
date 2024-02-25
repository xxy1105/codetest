#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_strcmp(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2) {
            return 1;
        }
        else if (*str1 < *str2) {
            return -1;
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    }
    else if (*str1 == '\0') {
        return -1;
    }
    else {
        return 1;
    }
}

void my_strcpy(char* dest, char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void sortDays(char days[7][5], int length) {
    int i, j;
    char temp[5];

    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (my_strcmp(days[j], days[j + 1]) > 0) {
                my_strcpy(temp, days[j]);
                my_strcpy(days[j], days[j + 1]);
                my_strcpy(days[j + 1], temp);
            }
        }
    }
}

void printDays(char days[7][5], int length, const char* prompt) {
    printf("%s\n", prompt);
    for (int i = 0; i < length; i++) {
        printf("%s\n", days[i]);
    }
}

int main() {
    char days[7][5] = { "周日", "周一", "周二", "周三", "周四", "周五", "周六" };

    printDays(days, 7, "排序前：");

    sortDays(days, 7);

    printDays(days, 7, "排序后：");

    return 0;
}