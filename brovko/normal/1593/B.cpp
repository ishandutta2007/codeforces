#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> v;

        while(n)
        {
            v.pb(n % 10);
            n /= 10;
        }

        int x = 0;

        while(x < v.size() && v[x] != 0)
            x++;

        x++;

        while(x < v.size() && v[x] != 5 && v[x] != 0)
            x++;

        int ans = x;

        x = 0;

        while(x < v.size() && v[x] != 5)
            x++;

        x++;

        while(x < v.size() && v[x] != 2 && v[x] != 7)
            x++;

        ans = min(ans, x);

        cout << ans - 1 << "\n";
    }
}