#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int g[305][305];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector <int> a(k);
    vector <int> used(n);

    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i]--;

        used[a[i]] = 1;
    }

    if(k == n)
    {
        cout << -1;
        return 0;
    }

    int i = a[0], j = a[1], v = 0;

    while(used[v])
        v++;

    for(int x = 0; x < n; x++)
    {
        if(v != x && g[x][v] == 0)
        {
            m--;
            g[x][v] = 1;
            g[v][x] = 1;
        }
    }

    for(int x = 0; x < n; x++)
        for(int y = 0; y < x; y++)
            if(m > 0 && g[x][y] == 0 && (x != i && y != i || !used[x] || !used[y]))
            {
                m--;
                g[x][y] = 1;
                g[y][x] = 1;
            }

    if(m > 0)
        cout << -1;
    else
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(g[i][j])
                    cout << j + 1 << ' ' << i + 1 << "\n";
    }
}