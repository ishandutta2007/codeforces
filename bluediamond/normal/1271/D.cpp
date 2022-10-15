#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5000 + 7;
const int INF = (int) 1e9;
int n;
int m;
int k;
int a[N];
int b[N];
int c[N];
int mx[N];
vector<int> g[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b[0];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        b[i] += b[i - 1];
        mx[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> v >> u;
        mx[u] = max(mx[u], v);
    }
    for (int i = 1; i <= n; i++)
    {
        g[mx[i]].push_back(c[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (auto &profit : g[i])
        {
            for (int j = min(n, b[i]) - 1; j >= 0; j--)
            {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + profit);
            }
        }
        if (i + 1 <= n)
        {
            for (int j = 0; j <= n; j++)
            {
                if (b[i] - j >= a[i + 1])
                {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                }
            }
        }
    }
    int ans = -INF;
    for (int j = 0; j <= n; j++)
    {
        ans = max(ans, dp[n][j]);
    }
    if (ans < 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
}