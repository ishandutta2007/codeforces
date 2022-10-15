#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 77;
const int S = 7777;
int n;
int r;
int f[N];
int s[N];
ld p[N];
ld dp[N][S];

ld evaluate(ld e)
{
    for (int j = 0; j < S; j++)
    {
        if (j <= r)
        {
            dp[n + 1][j] = 0;
        }
        else
        {
            dp[n + 1][j] = e;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < S - 100; j++)
        {
            dp[i][j] = (dp[i + 1][j + f[i]] + f[i]) * p[i] + (dp[i + 1][j + s[i]] + s[i]) * (1.0 - p[i]);
            if (i > 1)
            {
                dp[i][j] = min(dp[i][j], e);
            }
        }
    }
    return dp[1][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i] >> s[i] >> p[i];
        p[i] *= 0.01;
    }
    ld l = 0, r = (ld) 1e9;
    for (int i = 1; i <= 200; i++)
    {
        ld m = (l + r) * 0.5;
        if (evaluate(m) > m)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << fixed << setprecision(9) << l << "\n";
}