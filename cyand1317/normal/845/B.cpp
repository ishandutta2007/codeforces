#include <cstdio>
#include <algorithm>

int n;

int check(int m)
{
    int n = ::n;
    int ret = 0;
    for (int i = 0; i < 6; ++i) {
        if (n % 10 != m % 10) ++ret;
        n /= 10; m /= 10;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);

    int ans = 114514;
    for (int m = 0; m <= 999999; ++m)
        if (m % 10 + m / 10 % 10 + m / 100 % 10 == m / 1000 % 10 + m / 10000 % 10 + m / 100000)
            ans = std::min(ans, check(m));

    printf("%d\n", ans);
    return 0;
}