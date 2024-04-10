#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int Q = 300;

int n, m, c[100005], used[100005], tin[100005], tout[100005], T, a[300005], k[100005], ans[100005], kge[100005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    a[T] = v;
    tin[v] = T++;

    for(auto to:g[v])
    {
        if(used[to] == 0)
            dfs(to);
    }

    tout[v] = T;
}

bool comp(vector <int> i, vector <int> j)
{
    return (make_pair(tin[i[1]] / Q, tout[i[1]]) < make_pair(tin[j[1]] / Q, tout[j[1]]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> c[i];

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);

    vector <vector <int> > q;

    for(int i = 0; i < m; i++)
    {
        int v, k;
        cin >> v >> k;

        v--;

        q.pb({i, v, k});
    }

    sort(q.begin(), q.end(), comp);

    int l = 0, r = 0;

//    for(int i = 0; i < T; i++)
//        cout << a[i] << ' ';
//
//    cout << endl;

    for(auto x:q)
    {
//        cout << "query " << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << tin[x[1]] << ' ' << tout[x[1]] << endl;

        while(r < tout[x[1]])
        {
            k[c[a[r]]]++;
            kge[k[c[a[r]]]]++;
            r++;
        }

        while(l > tin[x[1]])
        {
            l--;
            k[c[a[l]]]++;
            kge[k[c[a[l]]]]++;
        }

        while(r > tout[x[1]])
        {
            r--;
            kge[k[c[a[r]]]]--;
            k[c[a[r]]]--;
        }

        while(l < tin[x[1]])
        {
            kge[k[c[a[l]]]]--;
            k[c[a[l]]]--;
            l++;
        }

        ans[x[0]] = kge[x[2]];
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}