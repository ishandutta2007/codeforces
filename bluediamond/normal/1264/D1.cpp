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

const int N = 2000 + 7;
int n;
string s;
int p[N];
int dp[N][N];
int cnt[N];

bool o(int i)
{
    return s[i - 1] != ')';
}

bool c(int i)
{
    return s[i - 1] != '(';
}

int val(int l, int r)
{
    return p[cnt[r] - cnt[l - 1]];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = (int) s.size();
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = mul(2, p[i - 1]);
        cnt[i] = cnt[i - 1] + (s[i - 1] == '?');
    }
    for (int l = n; l >= 1; l--)
    {
        for (int r = l + 1; r <= n; r++)
        {
            if (o(l) && c(r))
            {
                dp[l][r] = add(dp[l + 1][r - 1], val(l + 1, r - 1));
            }
            if (c(l))
            {
                dp[l][r] = add(dp[l][r], dp[l + 1][r]);
            }
            if (o(r))
            {
                dp[l][r] = add(dp[l][r], dp[l][r - 1]);
                if (c(l))
                {
                    dp[l][r] = add(dp[l][r], -dp[l + 1][r - 1]);
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}