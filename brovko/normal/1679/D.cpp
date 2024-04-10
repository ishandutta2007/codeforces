#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int used[200005], d[200005];
vector <int> g[200005];
bool C;

void dfs(int v)
{
    used[v] = 1;
    d[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            dfs(to);
            d[v] = max(d[v], d[to] + 1);
        }
        else
        if(used[to] == 1)
        {
//            if(!C)
//                cout << "cycle " << to + 1 << endl;


            C = true;
        }
        else d[v] = max(d[v], d[to] + 1);
    }

    used[v] = 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    li k;

    cin >> n >> m >> k;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
    }

    int L = 0, R = 2e9;

    while(R - L > 1)
    {
        C = false;

        int M = (L + R) / 2;

        for(int i = 0; i < n; i++)
        {
            used[i] = (a[i] > M ? 2 : 0);
            d[i] = 0;
        }

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                dfs(i);

        int Max = 0;

        for(int i = 0; i < n; i++)
            Max = max(Max, d[i]);

        if(C || Max >= k)
            R = M;
        else L = M;
    }

    if(R == 2e9)
        cout << -1;
    else cout << R;
}