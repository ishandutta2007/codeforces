#include <cstdio>

int iao_year(int n, int dig)
{
    int pw = 1, sum = 0;
    for (int i = 0; i < dig; ++i) {
        pw *= 10;
        sum += pw;
    }
    int lwb = 1989 + sum - pw,
        upb = 1989 + sum;
    if (n >= lwb % pw) return lwb / pw * pw + n;
    else return upb / pw * pw + n;
}

int main()
{
    int t, n, dig;
    char ch;
    scanf("%d", &t); getchar();
    do {
        for (int i = 0; i < 4; ++i) getchar();
        n = 0; dig = 0;
        while ((ch = getchar()) >= '0' && ch <= '9') {
            n = n * 10 + ch - '0';
            ++dig;
        }
        printf("%d\n", iao_year(n, dig));
    } while (--t);
    return 0;
}