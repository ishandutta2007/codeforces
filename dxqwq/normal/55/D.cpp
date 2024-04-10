//zhouAKngyang AK IOI!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, mod;
int len, num[20], dp[20][2521][52], mp[2521], tot = 0;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int dfs(int now, int sum, int mask, int limit)
{
    if (now < 1)
    {
        return sum % mask == 0 ? 1 : 0;
    }
    if (!limit && dp[now][sum][mp[mask]] != -1)
        return dp[now][sum][mp[mask]];
    int mx = limit ? num[now] : 9;
    int ans = 0;
    for (int i = 0; i <= mx; ++i)
    {
        ans += dfs(now - 1, (sum * 10 + i) % 2520, i == 0 ? mask : (i * mask / __gcd(i, mask)), limit & (i == mx));
    }
    if (!limit)
        dp[now][sum][mp[mask]] = ans;
    return ans;
}
int solve(int n)
{
    len = 0;
    while (n)
    {
        num[++len] = n % 10;
        n /= 10;
    }
    
    return dfs(len, 0, 1, 1);
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    int T;
    for (int i = 1; i <= 2520; ++i)
    {
        if (2520 % i == 0)
            mp[i] = ++tot;
    }
    T = read();
    while (T--)
    {
        int a, b;
        a = read();
        b = read();
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}