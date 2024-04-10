#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, k, s[100005], y[100005], d[100005], U[300005], V[300005], W[300005], p[100005], siz[100005], used[100005];
vector <pair <int, int> > g[100005];

//int get(int x)
//{
//    if(x == p[x])
//        return x;
//
//    p[x] = get(p[x]);
//
//    return p[x];
//}
//
//void unite(int x, int y)
//{
//    x = get(x);
//    y = get(y);
//
//    if(x == y)
//        return;
//
//    if(siz[x] > siz[y])
//        swap(x, y);
//
//    p[x] = y;
//    siz[y] += siz[x];
//}

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

        U[i] = u;
        V[i] = v;
        W[i] = w;

        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    for(int i = 0; i < k; i++)
    {
        cin >> s[i] >> y[i];
        s[i]--;

        g[0].pb({s[i], y[i]});
        g[s[i]].pb({0, y[i]});
    }

    d[0] = 0;

    for(int i = 1; i < n; i++)
        d[i] = 1e18;

    set <pair <int, int> > q;

    for(int i = 0; i < n; i++)
    {
        q.insert({d[i], i});
    }

    for(int i = 0; i < n; i++)
    {
        int v = (*q.begin()).y;
        q.erase({d[v], v});

        for(auto to:g[v])
            if(d[to.x] > d[v] + to.y)
            {
                q.erase({d[to.x], to.x});
                d[to.x] = d[v] + to.y;
                q.insert({d[to.x], to.x});
            }
    }

//    for(int i = 0; i < n; i++)
//    {
//        p[i] = i;
//        siz[i] = 1;
//    }

    for(int i = 0; i < m; i++)
    {
        if(d[U[i]] == d[V[i]] + W[i])
            used[U[i]] = 1;

        if(d[V[i]] == d[U[i]] + W[i])
            used[V[i]] = 1;
    }

    int ans = 0;

    for(int i = 1; i < n; i++)
        if(used[i] == 0)
            ans++;

    cout << k - ans;
}