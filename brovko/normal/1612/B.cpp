#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b;

        if(a - b > 1)
        {
            cout << "-1\n";
            continue;
        }

        vector <int> l, r;

        for(int i = 1; i < a; i++)
            r.pb(i);

        for(int i = b + 1; i <= n; i++)
            l.pb(i);

        if(a < b)
        {
            l.pb(a);
            r.pb(b);
        }

        for(int i = a + 1; i < b; i++)
        {
            if(l.size() < r.size())
                l.pb(i);
            else r.pb(i);
        }

        if(l.size() != r.size())
            cout << "-1\n";
        else
        {
            for(auto x:l)
                cout << x << ' ';

            for(auto x:r)
                cout << x << ' ';

            cout << "\n";
        }
    }
}