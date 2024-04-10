#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[200005], m, b[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> b[i];

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
        v.pb({a[i], 1});

    for(int i = 0; i < m; i++)
        v.pb({b[i], -1});

    sort(v.begin(), v.end());

    int x = 3 * n, y = 3 * m;
    int p = x, q = y;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].y == 1)
            p--;
        else q--;

        if((i + 1 == v.size() || v[i].x != v[i + 1].x) && p - q > x - y)
        {
            x = p;
            y = q;
        }
    }

    cout << x << ":" << y;
}