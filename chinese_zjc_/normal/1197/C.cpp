#include <cstdio>
#include <algorithm>
using namespace std;
int n, num[300001], s[300001], ans, k;
inline void rd(int &ddd)
{
    char tmp = getchar();
    ddd = 0;
    while ('0' > tmp && tmp < '9')
    {
        tmp = getchar();
    }
    while ('0' <= tmp && tmp <= '9')
    {
        ddd = (ddd << 3) + (ddd << 1) + (tmp ^ 48);
        tmp = getchar();
    }
}
int main()
{
    rd(n);
    rd(k);
    rd(num[1]);
    for (int i = 2; i <= n; ++i)
    {
        rd(num[i]);
        s[i] = num[i] - num[i - 1];
    }
    sort(s + 1, s + 1 + n);
    for (int i = 1; i < k; ++i)
    {
        ans += s[n - i + 1];
    }
    printf("%d", num[n] - num[1] - ans);
    return 0;
}