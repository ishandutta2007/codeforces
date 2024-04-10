#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <pair <int, int> > v;

        for(int i = 1; i < n; i++)
        {
            v.pb({a[i] - a[i - 1], i + 1});
        }

        sort(v.rbegin(), v.rend());

        cout << 1 << ' ';

        for(int i = 0; i < n - 1; i++)
            cout << v[i].s << ' ';

        cout << "\n";
    }
}