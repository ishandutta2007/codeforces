#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

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
        int n, a, b;
        cin >> n >> a >> b;

        vector <int> x(n);

        for(int i = 0; i < n; i++)
            cin >> x[i];

        vector <int> d(n);

        for(int i = 0; i < n; i++)
            d[i] = x[i] - (i == 0 ? 0 : x[i - 1]);

        vector <li> ps(n + 1);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + d[i];

        li ans = 1e18;

        vector <li> pps(n + 2);

        for(int i = 0; i <= n; i++)
            pps[i + 1] = pps[i] + ps[i];

        for(int i = 0; i <= n; i++)
            ans = min(ans, b * (pps[n + 1] - pps[i] - ps[i] * (n + 1 - i)) + ps[i] * (a + b));

        cout << ans << "\n";
    }
}