#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 2e5 + 5;

int used[N], c[N], d[N], p[N];
vector <pair <int, int> > g[N];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to.f] == 0)
        {
            p[to.f] = to.s;
            d[to.f] = d[v] + 1;
            dfs(to.f);
            c[to.s] = 1;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            g[i].clear();
        }

        for(int i = 0; i < m; i++)
            c[i] = 0;

        vector <int> U(m), V(m);

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            U[i] = u;
            V[i] = v;

            g[u].pb({v, i});
            g[v].pb({u, i});
        }

        dfs(0);

        int mx = -1;
        set <int> st;
        int k = 0;

        for(int i = 0; i < m; i++)
            if(c[i] == 0)
            {
                if(mx == -1 || max(d[U[i]], d[V[i]]) > max(d[U[mx]], d[V[mx]]))
                    mx = i;

                st.insert(U[i]);
                st.insert(V[i]);
                k++;
            }

        if(k == 3 && st.size() == 3)
        {
            int v = U[mx];

            if(d[V[mx]] > d[v])
                v = V[mx];

            c[mx] = 1;
            c[p[v]] = 0;
        }

        for(int i = 0; i < m; i++)
            cout << c[i];

        cout << "\n";
    }
}