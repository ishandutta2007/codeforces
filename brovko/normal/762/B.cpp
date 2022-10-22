#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, b, c, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> n;

    vector <int> v, u;

    for(int i = 0; i < n; i++)
    {
        int x;
        string s;

        cin >> x >> s;

        if(s == "USB")
            v.pb(x);
        else u.pb(x);
    }

    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    vector <int> ps;
    ps.pb(0);

    for(int i = 0; i < u.size(); i++)
        ps.pb(ps[i] + u[i]);

    int k = 0, s = 0, sa = 0;

    for(int i = 0; i <= v.size(); i++)
        if(i <= a + c)
        {
            int y = i, z = min((int)u.size(), c - max(0ll, y - a) + b);

            if(make_pair(y + z, -(sa + ps[z])) > make_pair(k, -s))
            {
                k = y + z;
                s = sa + ps[z];
            }

            if(i < v.size())
                sa += v[i];
        }

    cout << k << ' ' << s;
}