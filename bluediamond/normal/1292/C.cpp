#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3000 + 7;
const ll INF = (ll) 1e18;
int n;
int m;
vector<int> g[N];
ll dp[N][N];
int d[N][N];
int p[N][N];
int sub[N][N];

void dfs(int base, int i)
{
    sub[base][i] = 1;
    for (auto &j : g[i])
    {
        if (d[base][j] == -1)
        {
            p[base][j] = i;
            d[base][j] = 1 + d[base][i];
            dfs(base, j);
            sub[base][i] += sub[base][j];
        }
    }
}

struct prn
{
    int x;
    int y;
};

bool cmp(prn a, prn b)
{
    return d[a.x][a.y] < d[b.x][b.y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = -1;
            dp[i][j] = -(1LL << 60);
        }
        dp[i][i] = 0;
        d[i][i] = 0;
        dfs(i, i);
    }
    vector<prn> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            v.push_back({j, i});
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto &it : v)
    {
        int x = it.x;
        int y = it.y;
        int no1 = p[y][x];
        int no2 = p[x][y];
        dp[x][y] = dp[y][x] = sub[y][x] * (ll) sub[x][y] + max(dp[no1][y], dp[x][no2]);
    }
    ll sol = -INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sol = max(sol, dp[i][j]);
        }
    }
    cout << sol << "\n";
}