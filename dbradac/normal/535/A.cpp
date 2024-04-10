#include <cstdio>

char jed[10][20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char des[10][20] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
char teen[10][20] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

int main()
{
    int n, j, s;

    scanf("%d", &n);

    j = n % 10;
    s = n / 10;

    if (n >= 10 && n < 20)
        printf("%s\n", teen[n-10]);
    else if (!(n % 10))
        printf("%s\n", des[n/10]);
    else if (n < 10)
        printf("%s\n", jed[n]);
    else
        printf("%s-%s\n", des[s], jed[j]);

    return 0;
}