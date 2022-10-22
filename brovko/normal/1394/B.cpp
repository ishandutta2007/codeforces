#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int p = 31;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int MOD3 = 998244353;

int n, m, k, pow1[200005], pow2[200005], pow3[200005], pow4[200005], h[15][15][4], x[4], s[4], ans;
vector <pair <int, int> > g[200005];

void rec(int d)
{
    if(d == k + 1)
    {
        if(x[0] == s[0] && x[1] == s[1] && x[2] == s[2] && x[3] == s[3])
            ans++;

        return;
    }

    for(int i = 0; i < d; i++)
    {
        x[0] = (x[0] + h[d][i][0]) % MOD1;
        x[1] = (x[1] + h[d][i][1]) % MOD2;
        x[2] = (x[2] + h[d][i][2]) % MOD3;
        x[3] = (x[3] + h[d][i][3]);

        rec(d + 1);

        x[0] = (x[0] + MOD1 - h[d][i][0]) % MOD1;
        x[1] = (x[1] + MOD2 - h[d][i][1]) % MOD2;
        x[2] = (x[2] + MOD3 - h[d][i][2]) % MOD3;
        x[3] = (x[3] - h[d][i][3]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        g[u].push_back({w, v});
    }

    for(int i = 0; i < n; i++)
        sort(g[i].begin(), g[i].end());

    pow1[0] = 1;
    pow2[0] = 1;
    pow3[0] = 1;
    pow4[0] = 1;

    for(int i = 1; i < n; i++)
    {
        pow1[i] = pow1[i - 1] * p % MOD1;
        pow2[i] = pow2[i - 1] * p % MOD2;
        pow3[i] = pow3[i - 1] * p % MOD3;
        pow4[i] = pow4[i - 1] * p;
    }

    for(int i = 0; i < n; i++)
    {
        s[0] = (s[0] + pow1[i]) % MOD1;
        s[1] = (s[1] + pow2[i]) % MOD2;
        s[2] = (s[2] + pow3[i]) % MOD3;
        s[3] = (s[3] + pow4[i]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            h[g[i].size()][j][0] = (h[g[i].size()][j][0] + pow1[g[i][j].second]) % MOD1;
            h[g[i].size()][j][1] = (h[g[i].size()][j][1] + pow2[g[i][j].second]) % MOD2;
            h[g[i].size()][j][2] = (h[g[i].size()][j][2] + pow3[g[i][j].second]) % MOD3;
            h[g[i].size()][j][3] = (h[g[i].size()][j][3] + pow4[g[i][j].second]);
        }
    }

    rec(1);
    cout << ans;
}