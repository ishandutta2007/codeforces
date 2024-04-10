#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        bool a[n][n][n];

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    char c;
                    cin >> c;

                    a[i][j][k] = c - '0';
                }
            }

        int comp[n][n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                comp[i][j] = -1;

            for(int j = 0; j < n; j++)
                if(comp[i][j] == -1)
                {
                    comp[i][j] = j;

                    for(int k = j + 1; k < n; k++)
                        if(a[j][k][i])
                            comp[i][k] = j;
                }
        }

        int kc[n][n], diam[n];

        for(int i = 0; i < n; i++)
        {
            diam[i] = 0;

            for(int j = 0; j < n; j++)
                kc[i][j] = 0;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                kc[i][comp[i][j]]++;

                if(kc[i][comp[i][j]] == 1)
                    diam[i]++;
            }

//        for(int i = 0; i < n; i++)
//            cout << diam[i] << ' ';
//
//        cout << endl;

//        for(int i = 0; i < n; i++)
//            cout << comp[1][i] << ' ';
//
//        cout << endl;

        for(int i = 0; i < n - 2; i++)
        {
            int v = 0;

            for(int j = 0; j < n; j++)
                if(diam[j] > diam[v])
                    v = j;

            diam[v] = -1e9;

            for(int j = 0; j < n; j++)
            {
                kc[j][comp[j][v]]--;

                if(kc[j][comp[j][v]] == 0)
                    diam[j]--;
            }
        }

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(diam[i] > -1e8)
                v.pb(i);

        queue <int> q;

        vector <int> used(n);
        vector <int> g[n];

        g[v[0]].pb(v[1]);
        g[v[1]].pb(v[0]);

        used[v[0]] = 1;
        used[v[1]] = 1;

        q.push(v[0]);
        q.push(v[1]);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            for(int i = 0; i < n; i++)
                if(a[min(i, g[v][0])][max(i, g[v][0])][v] && used[i] == 0)
                {
                    used[i] = 1;
                    g[v].pb(i);
                    g[i].pb(v);

                    q.push(i);
                }
        }

        int d[n][n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                d[i][j] = 1e9;

            d[i][i] = 0;

            vector <int> used(n);
            used[i] = 1;

            queue <int> q;
            q.push(i);

            while(!q.empty())
            {
                int v = q.front();
                q.pop();

                for(auto to:g[v])
                    if(used[to] == 0)
                    {
                        used[to] = 1;
                        q.push(to);
                        d[i][to] = d[i][v] + 1;
                    }
            }
        }

        bool F = 1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d[i][j] > 1e8)
                    F = 0;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                for(int k = 0; k < n; k++)
                    if(a[i][j][k] != (d[i][k] == d[j][k]))
                        F = 0;

        if(!F)
        {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        for(int i = 0; i < n; i++)
            for(auto x:g[i])
                if(x < i)
                    cout << x + 1 << ' ' << i + 1 << "\n";
    }
}