#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, m, a[105][105], used[105][105], used2[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        vector <pair <int, pair <int, int> > > v;

        for(int i = 0; i < 105; i++)
            for(int j = 0; j < 105; j++)
        {
            used[i][j] = -1;
            used2[i][j] = -1;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];

                v.push_back({a[i][j], {i, j}});
            }

        sort(v.begin(), v.end());

        int k = 0;

        for(int i = 0; i < m; i++)
        {
            k++;

            used[v[i].y.x][k] = v[i].y.y;
            used2[v[i].y.x][v[i].y.y] = k;
        }

        for(int i = 0; i < n; i++)
        {
            k = 1;

            for(int j = 0; j < m; j++)
            {
                if(used2[i][j] > -1)
                    used[i][used2[i][j]] = j;
                else
                {
                    while(used[i][k] > -1)
                        k++;

                    used[i][k] = j;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= m; j++)
                cout << a[i][used[i][j]] << ' ';

            cout << "\n";
        }
    }
}