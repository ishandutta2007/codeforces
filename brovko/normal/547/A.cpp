#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int m, h[2], a[2], x[2], y[2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> h[0] >> a[0] >> x[0] >> y[0] >> h[1] >> a[1] >> x[1] >> y[1];

    vector <int> v, u;

    for(int i = 1; i <= 5 * m; i++)
    {
        h[0] = (x[0] * h[0] + y[0]) % m;

        if(h[0] == a[0])
            v.pb(i);
            
        h[1] = (x[1] * h[1] + y[1]) % m;

        if(h[1] == a[1])
            u.pb(i);
            
        if(h[1] == a[1] && h[0] == a[0])
        {
            cout << i;
            return 0;
        }
    }

    if(v.size() < 2 || u.size() < 2)
    {
        cout << -1;
        return 0;
    }

    int r1 = v[0], r2 = u[0], A = v[1] - v[0], B = u[1] - u[0];

    for(int q2 = 0; q2 <= 5 * m; q2++)
    {
        if((B * q2 + r2 - r1) % A == 0)
        {
            cout << r2 + B * q2;
            return 0;
        }
    }

    cout << -1;
}