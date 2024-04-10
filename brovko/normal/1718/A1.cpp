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

        int dp[n + 1] = {};

        for(int i = 1; i <= n; i++)
            dp[i] = 1e9;

        for(int i = 1; i <= n; i++)
        {
            vector <int> b = a;

            dp[i] = dp[i - 1] + (bool)b[i - 1];
            int k = 0;

            for(int j = i - 2; j >= 0; j--)
            {
                b[j] ^= b[j + 1];
                k++;
                dp[i] = min(dp[i], dp[j] + (bool)b[j] + k);
            }
        }

//        for(int i = 0; i <= n; i++)
//            cout << dp[i] << ' ';
//
//        cout << "\n";

        cout << dp[n] << "\n";
    }
}