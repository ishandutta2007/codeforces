#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i % 2 == 0)
                v.pb({i, j});
            else v.pb({i, m - 1 - j});
        }
    }

    int x = 0;

    for(int i = 0; i < k - 1; i++)
    {
        cout << 2 << ' ' << v[x].x + 1 << ' ' << v[x].y + 1 << ' ' << v[x + 1].x + 1 << ' ' << v[x + 1].y + 1 << "\n";
        x += 2;
    }

    cout << n * m - x << ' ';

    for(; x < n * m; x++)
        cout << v[x].x + 1 << ' ' << v[x].y + 1 << ' ';
}