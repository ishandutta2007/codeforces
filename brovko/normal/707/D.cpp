#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, m, q, a[100005][3], b[1005][1005], r[1005], ans[100005], k, c[1005];
vector <int> g[100005];

void dfs(int v)
{
    ans[v] = k;

    for(auto to:g[v])
    {
        if(a[to][0] == 1)
        {
            int x = a[to][1];
            int y = a[to][2];

            if(r[x] == 0 && b[x][y] == 0)
            {
                c[x]++;
                k++;
                b[x][y] = 1;

                dfs(to);

                b[x][y] = 0;
                k--;
                c[x]--;
            }
            else if(r[x] == 1 && b[x][y] == 1)
            {
                c[x]++;
                k++;
                b[x][y] = 0;

                dfs(to);

                b[x][y] = 1;
                k--;
                c[x]--;
            }
            else dfs(to);
        }

        if(a[to][0] == 2)
        {
            int x = a[to][1];
            int y = a[to][2];

            if(r[x] == 0 && b[x][y] == 1)
            {
                c[x]--;
                k--;
                b[x][y] = 0;

                dfs(to);

                b[x][y] = 1;
                k++;
                c[x]++;
            }
            else if(r[x] == 1 && b[x][y] == 0)
            {
                c[x]--;
                k--;
                b[x][y] = 1;

                dfs(to);

                b[x][y] = 0;
                k++;
                c[x]++;
            }
            else dfs(to);
        }

        if(a[to][0] == 3)
        {
            int x = a[to][1];

            r[x] ^= 1;

            k += m - 2 * c[x];
            c[x] = m - c[x];

            dfs(to);

            r[x] ^= 1;

            k += m - 2 * c[x];
            c[x] = m - c[x];
        }

        if(a[to][0] == 4)
            dfs(to);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    for(int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;

        int x = 0, y = 0;

        if(t == 1 || t == 2)
            cin >> x >> y;
        else cin >> x;

        int z = i - 1;

        if(t == 4)
            z = x;

        g[z].push_back(i);

        a[i][0] = t;
        a[i][1] = x;
        a[i][2] = y;
    }

    dfs(0);

    for(int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
}