#include <stdio.h>
#define MAXN 108

int n, m;

unsigned char first_print = 1;
void try_print(int x)
{
    if (x <= m) {
        printf(first_print ? "%d" : " %d", x);
        first_print = 0;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for (i = 0; i < n; ++i) {
        try_print(i + i + n * 2 + 1);   // Left aisle
        try_print(i + i + 1);           // Left window
        try_print(i + i + n * 2 + 2);   // Right aisle
        try_print(i + i + 2);           // Right window
    }
    putchar('\n');
    return 0;
}