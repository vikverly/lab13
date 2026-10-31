/*
Студент: Черных Виктория Александровна
Группа: ПИ-1-1
Лабораторная работа 13
*/

#include <stdio.h>

// Функция поиска минимума и максимума за один проход
int min_max(const int a[], int n, int *lo, int *hi) {
    if (n <= 0) {
        return 0; // Отказ, выходные переменные не изменяются
    }
    
    int min_val = a[0];
    int max_val = a[0];
    
    for (int i = 1; i < n; i++) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }
    
    *lo = min_val;
    *hi = max_val;
    return 1; // Успех
}

int main(void) {
    // Тест 1 из методички (n = 3)
    int arr1[] = {4, -2, 7};
    int lo1 = 99, hi1 = 99;
    int res1 = min_max(arr1, 3, &lo1, &hi1);
    printf("Test 1 (n=3): Status=%d, lo=%d, hi=%d (Expected: Status=1, lo=-2, hi=7)\n", res1, lo1, hi1);

    // Тест 2 из методички (n = 1)
    int arr2[] = {4};
    int lo2 = 99, hi2 = 99;
    int res2 = min_max(arr2, 1, &lo2, &hi2);
    printf("Test 2 (n=1): Status=%d, lo=%d, hi=%d (Expected: Status=1, lo=4, hi=4)\n", res2, lo2, hi2);

    // Тест 3 из методички (n = 0)
    int arr3[] = {0};
    int lo3 = 99, hi3 = 99;
    int res3 = min_max(arr3, 0, &lo3, &hi3);
    printf("Test 3 (n=0): Status=%d, lo=%d, hi=%d (Expected: Status=0, lo=99, hi=99)\n", res3, lo3, hi3);

    // Собственный тест на границу (массив из одинаковых отрицательных чисел)
    int arr4[] = {-5, -5, -5};
    int lo4 = 99, hi4 = 99;
    int res4 = min_max(arr4, 3, &lo4, &hi4);
    printf("Custom Test (equal negative): Status=%d, lo=%d, hi=%d (Expected: Status=1, lo=-5, hi=-5)\n", res4, lo4, hi4);

    return 0;
}
