#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % MOD;
}

const int N = 1000 + 7;
int n, k, a[N];
int dp[N][N];

int compute(int x)
{
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
    }
    for (int c = 2; c <= k; c++)
    {
        int j = 0, pref = 0;
        for (int i = 1; i <= n; i++)
        {
            while (j + 1 <= i && a[j + 1] <= a[i] - x)
            {
                j++;
                pref = add(pref, dp[c - 1][j]);
            }
            dp[c][i] = pref;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = add(ans, dp[k][i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int ans = 0, x = 1;

    while (1)
    {
        int y = compute(x);
        ans = add(ans, y);
        if (y == 0)
        {
            break;
        }
        x++;
    }

    cout << ans << "\n";
}