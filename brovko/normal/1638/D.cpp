#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[1005][1005], used[1005][1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    vector <vector <int> > ans;

    queue <pair <int, int> > q;

    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m - 1; j++)
        {
            if(a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1])
            {
                q.push({i, j});
                used[i][j] = a[i][j];
            }
        }

    while(!q.empty())
    {
        pair <int, int> p = q.front();
        q.pop();

        int x = p.x, y = p.y;

        ans.pb({x, y, used[x][y]});

        a[x][y] = 0;
        a[x + 1][y + 1] = 0;
        a[x][y + 1] = 0;
        a[x + 1][y] = 0;

        for(int i = max(0, x - 1); i <= min(n - 2, x + 1); i++)
            for(int j = max(0, y - 1); j <= min(m - 2, y + 1); j++)
            {
                set <int> s;

                s.insert(a[i][j]);
                s.insert(a[i][j + 1]);
                s.insert(a[i + 1][j]);
                s.insert(a[i + 1][j + 1]);

                set <int> s1;
                s1.insert(max(1, (a[i][j] | a[i + 1][j] | a[i][j + 1] | a[i + 1][j + 1])));

                set <int> s2 = s1;

                s1.insert(0);

                if((s == s1 || s == s2) && used[i][j] == 0)
                {
                    used[i][j] = (*s1.rbegin());
                    q.push({i, j});

                    a[i][j] = 0;
                    a[i][j + 1] = 0;
                    a[i + 1][j] = 0;
                    a[i + 1][j + 1] = 0;
                }
            }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] > 0)
            {
                cout << -1;
                return 0;
            }

    cout << ans.size() << "\n";

    reverse(ans.begin(), ans.end());

    for(auto x:ans)
        cout << x[0] + 1 << ' ' << x[1] + 1 << ' ' << x[2] << "\n";
}