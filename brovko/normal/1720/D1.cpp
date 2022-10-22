#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int K = 300;

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

        vector <int> dp(n);
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;

            for(int j = i - 1; j >= i - K; j--)
                if(j >= 0 && (i ^ a[j]) < (a[i] ^ j))
                    dp[i] = max(dp[i], dp[j] + 1);

            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";
    }
}