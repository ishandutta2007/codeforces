#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, t, k, a[200005], p[200005], x, used[200005];
vector <int> v[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t >> k;

    for(int i = 1; i <= t; i++)
        {
            cin >> a[i];
            x += a[i] - 1;
        }

    x++;

    a[0] = 1;

    int d = 1;
    int y = 1;

    v[0].push_back(1);

    for(int i = 2; i <= n; i++)
    {
        v[d].push_back(i);

        if(y < a[d - 1] && x > k && used[v[d - 1][y - 1]])
        {
            y++;
            x--;
            p[i] = v[d - 1][y - 1];
            used[p[i]]++;
        }
        else
        {
            p[i] = v[d - 1][y - 1];
            used[p[i]]++;
        }

        if(v[d].size() == a[d])
        {
            d++;
            y = 1;
        }
    }

    if(x != k)
        cout << -1;
    else
    {
        cout << n << "\n";

        for(int i = 2; i <= n; i++)
            cout << p[i] << ' ' << i << "\n";
    }
}