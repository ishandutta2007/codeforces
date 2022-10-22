#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int get(int* f, int r)
{
    int ans = -1e18;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans = max(ans, f[r]);

    return ans;
}

void upd(int* f, int y, int i, int d)
{
    for(; i < y; i = (i | i + 1))
        f[i] = max(f[i], d);
}

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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> ps(n + 1);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        vector <int> v;

        for(int i = 0; i <= n; i++)
            v.pb(ps[i]);

        sort(v.begin(), v.end());

        map <int, int> m;
        int y = -1;

        for(int i = 0; i <= n; i++)
        {
            if(i == 0 || v[i] != v[i - 1])
                y++;

            m[v[i]] = y;
        }

        y++;

        for(int i = 0; i <= n; i++)
            ps[i] = m[ps[i]];
//
//        for(int i = 0; i <= n; i++)
//            cout << ps[i] << ' ';
//
//        cout << endl;

        vector <int> dp(y);

        for(int i = 0; i < y; i++)
            dp[i] = -1e18;

        dp[ps[0]] = 0;

        int f[y];

        for(int i = 0; i < y; i++)
            f[i] = -1e18;

        upd(f, y, ps[0], 0);

        for(int i = 1; i <= n; i++)
        {
            dp[ps[i]] = max(dp[ps[i - 1]] - 1 + (a[i - 1] == 0 ? 0 : a[i - 1] > 0 ? 1 : -1), get(f, ps[i] - 1));

            upd(f, y, ps[i], dp[ps[i]]);

//            cout << "! " << ps[i - 1] << ' ' << dp[ps[i - 1]] << endl;

//            cout << max(dp[ps[i - 1]] - 2, get(f, ps[i] - 1)) << ' ' << dp[ps[i - 1]] - 2 << ' ' << get(f, ps[i] - 1) << endl;
        }

        cout << dp[ps[n]] + n << "\n";
    }
}