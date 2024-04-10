#include <cstdio>
typedef long long int64;

int64 n, s;

int ds(int64 x)
{
    int ans = 0;
    for (; x; x /= 10) ans += x % 10;
    return ans;
}

int main()
{
    scanf("%I64d%I64d", &n, &s);

    int64 ans = 0;
    int64 x;
    if (s > n) { puts("0"); return 0; }
    for (x = s; x <= s + 200 && x <= n; ++x)
        if (x - ds(x) >= s) ++ans;
    ans += (n - x + 1);
    printf("%I64d\n", ans);

    return 0;
}