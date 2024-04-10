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

        int k0 = 0, k1 = 0;

        for(int i = 0; i < n; i++)
            if(a[i] % 2 == 0)
                k0++;
            else k1++;

        int dp[k0 + 1][k1 + 1][2];

        dp[0][0][0] = (n % 2 == 0 ? 1 : -1);
        dp[0][0][1] = -dp[0][0][0];

        for(int i = 0; i <= k0; i++)
            for(int j = 0; j <= k1; j++)
                for(int s = 0; s < 2; s++)
                    if(i + j > 0)
                    {
                        dp[i][j][s] = -1;

                        if(i > 0)
                            dp[i][j][s] = max(dp[i][j][s], -dp[i - 1][j][s]);

                        if(j > 0)
                            dp[i][j][s] = max(dp[i][j][s], -dp[i][j - 1][(i + j) % 2 == n % 2 ? (s ^ 1) : s]);
                    }

//        cout << dp[0][0][0] << ' ' << dp[0][1][0] << ' ' << dp[1][1][0] << endl;

        cout << (dp[k0][k1][0] == 1 ? "Alice\n" : "Bob\n");
    }
}