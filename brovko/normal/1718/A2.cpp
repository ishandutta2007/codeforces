#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;


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

        vector <int> p(n + 1);

        for(int i = 0; i < n; i++)
            p[i + 1] = (p[i] ^ a[i]);

        map <int, int> mp;

        vector <int> last(n + 1, -1);

        for(int i = 0; i < n + 1; i++)
        {
            if(mp.count(p[i]))
                last[i] = mp[p[i]];

            mp[p[i]] = i;
        }

//        cout << "last ";
//
//        for(int i = 0; i <= n; i++)
//            cout << last[i] << ' ';
//
//        cout << "\n";

        vector <int> dp(n + 1);

        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];

            if(last[i] != -1)
                dp[i] = max(dp[i], (last[i] == 0 ? 0 : dp[last[i]]) + 1);
        }

//        cout << "dp ";
//
//        for(int i = 0; i <= n; i++)
//            cout << dp[i] << ' ';
//
//        cout << "\n";

        cout << n - dp[n] << "\n";
    }
}