#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3500 + 7;
const int INF = (int) 1e9;
int n, p, k, a[N], dp[N][N]; /// max for l...r

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

       /// freopen ("input", "r", stdin);

        int t;
        cin >> t;

        while (t--)
        {
                cin >> n >> p >> k;
                for (int i = 1; i <= n; i++)
                        cin >> a[i];

                for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= n; j++)
                                dp[i][j] = -INF;

                int lee = n - p + 1;
                for (int l = 1; l + lee - 1 <= n; l++)
                {
                        int r = l + lee - 1;
                        dp[l][r] = max(a[l], a[r]);
                }

                for (int len = lee + 1; len <= n; len++)
                {
                      //  cout << ": " << len << "\n";
                        bool c = (n - k + 1 <= len);
                        for (int l = 1; l + len - 1 <= n; l++)
                        {
                                int r = l + len - 1;
                                if (c)
                                {
                                        dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                                }
                                else
                                {
                                        dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
                                }
                        }
                }
               // cout << dp[]
                cout << dp[1][n] << "\n";
        }

}