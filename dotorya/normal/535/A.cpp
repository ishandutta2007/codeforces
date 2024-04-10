#include <stdio.h>
char d[25][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char d2[12][20] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
int main() {
    int N;
    scanf("%d", &N);
    if(N <= 19) printf("%s", d[N]);
    else {
        printf("%s", d2[N/10]);
        if(N%10 != 0) printf("-%s", d[N%10]);
    }
    return 0;
}