#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 7;
const int INF = (int) 1e9;
int n;
int m;
int p;
int a[N][N];
vector<pair<int, int>> pos[N * N];
int dp[N][N];

int __dist(int r1, int c1, int r2, int c2)
{
    return abs(r2 - r1) + abs(c2 - c1);
}

void t1(int x)
{
    for (auto &it : pos[x])
    {
        int r1 = it.first;
        int c1 = it.second;
        for (auto &it2 : pos[x - 1])
        {
            int r2 = it2.first;
            int c2 = it2.second;
            dp[r1][c1] = min(dp[r1][c1], dp[r2][c2] + __dist(r1, c1, r2, c2));
        }
    }
}

struct T
{
    int r;
    int c;
    int dp;
};

bool operator < (T a, T b)
{
    return a.dp < b.dp;
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int dist[N][N];

bool inside(int r, int c)
{
    return (1 <= r && 1 <= c && r <= n && c <= m);
}

void t2(int x)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dist[i][j] = -1;
        }
    }
    vector<T> ant;
    for (auto &it : pos[x - 1])
    {
        int r = it.first;
        int c = it.second;
        ant.push_back({r, c, dp[r][c]});
        dist[r][c] = dp[r][c];
    }
    sort(ant.begin(), ant.end());
    queue<T> q;
    int poss = 0, sz = (int) ant.size();
    q.push(ant[0]);
    poss++;
    while (!q.empty() || poss < sz)
    {
        T it;
        if (q.empty() || (poss < sz && ant[poss].dp < q.front().dp))
        {
            it = ant[poss];
            poss++;
        }
        else
        {
            it = q.front();
            q.pop();
        }
        int r = it.r;
        int c = it.c;
        for (int k = 0; k < 4; k++)
        {
            int rn = r + dr[k];
            int cn = c + dc[k];
            if (inside(rn, cn) && dist[rn][cn] == -1)
            {
                dist[rn][cn] = 1 + dist[r][c];
                q.push({rn, cn, dist[rn][cn]});
            }
        }
    }
    for (auto &it : pos[x])
    {
        int r = it.first;
        int c = it.second;
        dp[r][c] = dist[r][c];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            pos[a[i][j]].push_back({i, j});
            dp[i][j] = INF;
        }
    }
    for (auto &it : pos[1])
    {
        dp[it.first][it.second] = __dist(1, 1, it.first, it.second);
    }
    for (int x = 2; x <= p; x++)
    {
        int a = (int) pos[x - 1].size();
        int b = (int) pos[x].size();
        if (a * b <= n * m)
        {
            t1(x);
        }
        else
        {
            t2(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == p)
            {
                cout << dp[i][j] << "\n";
                return 0;
            }
        }
    }
}