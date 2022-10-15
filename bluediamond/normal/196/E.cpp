#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const ll INF = (ll) 1e18;
int n;
int m;
vector<pair<int, int>> g[N];
ll dist[N];
int par[N];
int t[N];

int root(int x)
{
    if (t[x] == x)
    {
        return x;
    }
    else
    {
        return t[x] = root(t[x]);
    }
}

void unite(int x, int y)
{
    t[root(x)] = root(y);
}

struct T
{
    int x;
    ll d;
};

bool operator < (T a, T b)
{
    return a.d > b.d;
}

struct edge
{
    int x;
    int y;
    ll d;
};

bool operator < (edge a, edge b)
{
    return a.d < b.d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = i;
        dist[i] = INF;
    }
    priority_queue<T> pq;
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int portal;
        cin >> portal;
        dist[portal] = 0;
        par[portal] = portal;
        pq.push({portal, 0});
    }
    while (!pq.empty())
    {
        int x = pq.top().x;
        ll d = pq.top().d;
        pq.pop();
        if (d != dist[x])
        {
            continue;
        }
        for (auto &it : g[x])
        {
            int y = it.first;
            ll dy = dist[x] + it.second;
            if (dy < dist[y])
            {
                dist[y] = dy;
                par[y] = par[x];
                pq.push({y, dy});
            }
        }
    }
    vector<edge> e;
    for (int i = 1; i <= n; i++)
    {
        for (auto &it : g[i])
        {
            int j = it.first;
            int c = it.second;
            if (par[i] != par[j])
            {
                e.push_back({par[i], par[j], c + dist[i] + dist[j]});
            }
        }
    }
    ll sol = dist[1];
    sort(e.begin(), e.end());
    for (auto &it : e)
    {
        if (root(it.x) != root(it.y))
        {
            unite(it.x, it.y);
            sol += it.d;
        }
    }
    cout << sol << "\n";
    return 0;
}