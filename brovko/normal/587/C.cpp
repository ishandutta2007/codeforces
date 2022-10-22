#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, q, used[100005], p[100005], tin[100005], tout[100005], T, up[100005][20];
vector <int> g[100005], Min[100005][20], Min0[100005];

void dfs(int v)
{
    used[v] = 1;
    tin[v] = ++T;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            p[to] = v;
            dfs(to);
        }
    }

    tout[v] = ++T;
}

bool is_anc(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

void unite(vector <int> &a, vector <int> b)
{
//    for(auto x:b)
//        a.pb(x);
//
//    sort(a.begin(), a.end());

    vector <int> c(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    a = c;

    vector <int> v;

    for(int i = 0; i < a.size(); i++)
        if(i == 0 || a[i] != a[i - 1])
            v.pb(a[i]);

    while(v.size() > 10)
        v.pop_back();

    a = v;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        x--;

        Min[x][0].pb(i + 1);
    }

    for(int i = 0; i < n; i++)
    {
        sort(Min[i][0].begin(), Min[i][0].end());

        while(Min[i][0].size() > 10)
            Min[i][0].pop_back();
    }

    dfs(0);

    for(int i = 0; i < n; i++)
        Min0[i] = Min[i][0];

    for(int i = 1; i < n; i++)
    {
        up[i][0] = p[i];

        unite(Min[i][0], Min0[p[i]]);
    }

    for(int j = 1; j < 20; j++)
        for(int i = 0; i < n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];

            unite(Min[i][j], Min[i][j - 1]);
            unite(Min[i][j], Min[up[i][j - 1]][j - 1]);
        }

//    for(auto x:Min[4][0])
//        cout << x << ' ';
//
//    cout << endl;

    while(q--)
    {
        int v, u, a;
        cin >> v >> u >> a;

        v--;
        u--;

        vector <int> mins;

        for(int j = 19; j >= 0; j--)
            if(!is_anc(up[u][j], v))
            {
                unite(mins, Min[u][j]);
                u = up[u][j];
            }

//        cout << "mins ";
//
//        for(auto x:mins)
//            cout << x << ' ';
//
//        cout << endl;

        for(int j = 19; j >= 0; j--)
            if(!is_anc(up[v][j], u))
            {
                unite(mins, Min[v][j]);
                v = up[v][j];
            }

//        cout << "mins2 ";

//        for(auto x:mins)
//            cout << x << ' ';
//
//        cout << endl;
//
//        cout << "!" << u << ' ' << v << endl;

        if(!is_anc(u, v))
            unite(mins, Min[u][0]);

        unite(mins, Min0[u]);
        unite(mins, Min0[v]);

        while(mins.size() > a)
            mins.pop_back();

        cout << mins.size() << ' ';

        for(auto x:mins)
            cout << x << ' ';

        cout << "\n";
    }
}