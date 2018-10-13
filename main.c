/*
 * This program reads the amount of values the user chooses and then
 * it prints how many numbers are duplicate.
 * For example if the user enters he following 10 numbers:
 * [5,4,8,2,5,5,4,3,9,3] the program would inform that there are
 * 3 duplicated numbers, 3, 4 and 5.
 */

#include <stdio.h>
#include <stdlib.h>

// The compare function for the qsort function.
int Compare (const void * a, const void * b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    // Declaration of variables
    int n;
    int dup = 0;
    int count;

    printf("How many values you want to enter?");
    scanf("%d", &n);

    // Declaration of array.
    int numbers[n];

    // Storing of every value.
    for(int i = 0; i < n; i++){
        printf("%d:", i+1);
        scanf("%d", &numbers[i]);
    }

    // Sorting function
    qsort(numbers, n, sizeof(int), Compare);

    // After sorting we count for every number how many are there.
    // If there is more than one of the same number, count increments and
    // we skip in the first for all those numbers.
    for(int i = 0; i < n; i+=count+1){
        count = 0;
        for(int j = i + 1; j < n; j++){
            if(numbers[i] == numbers[j]){
                count++;
            }
        }
        if(count > 0){
            dup++;
        }
    }

    printf("The amount of numbers that are duplicate is: %d.", dup);

    return 0;
}
