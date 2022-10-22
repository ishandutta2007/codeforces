#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int n, used[200005];
vector <int> g[200005];
set <int> st;

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            if(g[to].size() <= 2)
                dfs(to);
            else st.insert(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n == 1)
        {
            cout << "0\n";
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            used[i] = 0;
        }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb(v);
            g[v].pb(u);
        }

        int v = -1;

        for(int i = 0; i < n; i++)
            if(g[i].size() > 2)
                v = i;

        if(v == -1)
        {
            cout << "1\n";
            continue;
        }

        st.clear();
        int k = 0;

        for(int i = 0; i < n; i++)
            if(g[i].size() == 1)
                k++, dfs(i);

        cout << k - st.size() << "\n";
    }
}

/*
1
10
1 2
2 3
3 4
4 7
4 8
4 10
1 9
1 5
1 6

*/