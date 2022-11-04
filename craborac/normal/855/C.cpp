#include <bits/stdc++.h>

using namespace std;

const long long mod = (long long)1e9 + 7;
long long k, m, x;
long long dp[(int)1e5 + 10][11][3];
vector<int> mas[(int)1e5 + 10];
int used[(int)1e5 + 10];

void dfs(int v)
{
    used[v] = 1;
    dp[v][0][0] = k - 1;
    dp[v][1][1] = 1;
    dp[v][0][2] = m - k;
    for (int u: mas[v])
    {
        if (used[u] == 0)
        {
            dfs(u);
            long long ne[11][3];
            for (int i = 0; i < 11; i++)
                for (int j = 0; j < 3; j++)
                    ne[i][j] = 0;
            for (int a = 0; a <= x; a++)
            {
                for (int b = 0; a + b <= x; b++)
                {
                    ne[a + b][0] = (ne[a + b][0] + dp[v][a][0] * (dp[u][b][0] + dp[u][b][1] + dp[u][b][2])) % mod;
                    ne[a + b][1] = (ne[a + b][1] + dp[v][a][1] * dp[u][b][0]) % mod;
                    ne[a + b][2] = (ne[a + b][2] + dp[v][a][2] * (dp[u][b][0] + dp[u][b][2])) % mod;
                }
            }
            for (int i = 0; i < 11; i++)
                for (int j = 0; j < 3; j++)
                    dp[v][i][j] = ne[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mas[a].push_back(b);
        mas[b].push_back(a);
    }
    cin >> k >> x;
    dfs(0);
    long long ans = 0;
    for (int i = 0; i <= x; i++)
    {
        ans = (ans + dp[0][i][0] + dp[0][i][1] + dp[0][i][2]) % mod;
    }
    cout << ans << endl;
    return 0;
}