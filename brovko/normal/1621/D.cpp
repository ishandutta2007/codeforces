#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a[505][505];

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

        for(int i = 0; i < 2 * n; i++)
            for(int j = 0; j < 2 * n; j++)
                cin >> a[i][j];

        int ans = 0;

        for(int i = n; i < 2 * n; i++)
            for(int j = n; j < 2 * n; j++)
            {
                ans += a[i][j];
                a[i][j] = 0;
            }

        int m = 2 * n;
        int N = m * m;
        vector <vector <int> > g[N];

        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                if(i < n || j < n)
                {
                    int li = (i + m - 1) % m;
                    int ri = (i + 1) % m;
                    int lj = (j + m - 1) % m;
                    int rj = (j + 1) % m;

                    int x = i * m + j;

                    g[x].pb({a[li][j], i, j, li, j});
                    g[x].pb({a[ri][j], i, j, ri, j});
                    g[x].pb({a[i][lj], i, j, i, lj});
                    g[x].pb({a[i][rj], i, j, i, rj});
                }

            set <pair <int, int> > q;

            int d[N];

            d[0] = 0;

            for(int i = 1; i < N; i++)
                d[i] = 1e18;

            for(int i = 0; i < N; i++)
                q.insert({d[i], i});

            int used[N] = {0};

            while(!q.empty())
            {
                pair <int, int> p = (*q.begin());
                q.erase(p);

                int v = p.y;
                used[v] = 1;

                for(auto e:g[v])
                {
                    int to = e[3] * m + e[4];

                    if(used[to] == 0)
                    {
                        q.erase({d[to], to});
                        d[to] = min(d[to], d[v] + e[0]);
                        q.insert({d[to], to});
                    }
                }
            }

//        for(int i = 0; i < m; i++)
//        {
//            for(int j = 0; j < m; j++)
//                cout << d[i * m + j] << ' ';
//
//            cout << endl;
//        }

        cout << min({d[N - 1], d[n * m + n], d[n * m + m - 1], d[(m - 1) * m + n]}) + ans << "\n";
    }
}

/*
1
4
0 0 0 0 9 9 9 9
0 0 0 0 1 1 1 9
0 0 0 0 1 9 1 9
0 0 0 0 9 1 1 9
9 1 1 9 1 2 3 4
9 1 2 1 1 2 3 4
9 1 1 9 1 2 3 4
9 9 1 9 1 2 3 4

*/