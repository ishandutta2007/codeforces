#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 600 + 7;
const int INF = (int) 1e9;

struct hades {
  int to;
  int c;
};

struct flow
{
    int n;
    vector<pair<int, int>> edges;
    vector<vector<int>> g;
    vector<int> level;
    vector<int> pos;
    flow(int nn)
    {
        n = nn;
        pos.resize(n + 1);
        level.resize(n + 1);
        g.resize(n + 1);
        edges.clear();
    }
    void add(int a, int b, int c)
    {
        g[a].push_back((int) edges.size());
        g[b].push_back((int) edges.size() + 1);
        edges.push_back({b, c});
        edges.push_back({a, 0});
    }
    int dfs(int a, int pre)
    {
        if (a == n || pre == 0)
        {
            return pre;
        }
        while (pos[a] < (int) g[a].size())
        {
            int i = g[a][pos[a]];
            int b = edges[i].first;
            int c = edges[i].second;
            pos[a]++;
            if (c == 0 || level[b] != level[a] + 1)
            {
                continue;
            }
            int total = dfs(b, min(pre, c));
            if (total)
            {
                edges[i].second -= total;
                edges[i ^ 1].second += total;
                return total;
            }
        }
        return 0;
    }
    int get()
    {
        int sol = 0;
        while (1)
        {
            for (int i = 1; i <= n; i++)
            {
                level[i] = -1;
                pos[i] = 0;
            }
            level[1] = 0;
            queue<int> q;
            q.push(1);
            while (!q.empty())
            {
                int a = q.front();
                q.pop();
                for (auto &i : g[a])
                {
                    int b = edges[i].first;
                    int c = edges[i].second;
                    if (c && level[b] == -1)
                    {
                        level[b] = 1 + level[a];
                        q.push(b);
                    }
                }
            }
            if (level[n] == -1)
            {
                break;
            }
            while (1)
            {
                int x = dfs(1, INF);
                if (x)
                {
                    sol += x;
                }
                else
                {
                    break;
                }
            }
        }
        return sol;
    }
};

int n;
int m;
int number;
int k;
int cities[N];
int d[N][N];
int who[N];
int type;

bool ok1(int t)
{
    flow f(2 * n + 2);
    for (int i = 1; i <= n; i++)
    {
        if (cities[i])
        {
            f.add(1, 1 + i, cities[i]);
        }
    }
    for (int j = 1; j <= n; j++)
    {
        f.add(1 + n + j, 2 * n + 2, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] <= t)
            {
                f.add(1 + i, 1 + n + j, 1);
            }
        }
    }
    return f.get() >= k;
}

bool ok2(int t)
{
    flow f(n + number + 2);
    for (int i = 1; i <= number; i++)
    {
        f.add(1, 1 + i, 1);
    }
    for (int j = 1; j <= n; j++)
    {
        f.add(1 + number + j, n + number + 2, 1);
    }
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[who[i]][j] <= t)
            {
                f.add(1 + i, 1 + number + j, 1);
            }
        }
    }
    return f.get() >= k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> number >> k;
    for (int i = 1; i <= number; i++)
    {
        cin >> who[i];
        cities[who[i]]++;
    }
    int cnt_distinct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cities[i])
        {
            cnt_distinct++;
        }
    }
    if (cnt_distinct > number / 2)
    {
        type = 2;
    }
    else
    {
        type = 1;
    }
    type = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int l = 0, r = 1731312, sol = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        bool good;
        if (type == 1)
        {
            good = ok1(m);
        }
        else
        {
            good = ok2(m);
        }
        if (good)
        {
            sol = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << sol << "\n";
}