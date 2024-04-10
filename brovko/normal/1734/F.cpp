#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 62;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        li n, m;
        cin >> n >> m;

        m--;

        li dp[N][2][2][2] = {};

        dp[0][0][0][0] = 1;

        for(int i = 0; i < N - 1; i++)
            for(int c = 0; c < 2; c++)
                for(int p = 0; p < 2; p++)
                    for(int cr = 0; cr < 2; cr++)
                    {
                        int nc = ((m & (1ll << i)) ? 0 : c);
                        int np = (((n >> i) & 1) ^ cr ^ p);
                        int ncr = (((n >> i) & 1) + cr >= 2);

                        dp[i + 1][nc][np][ncr] += dp[i][c][p][cr];

                        nc = ((m & (1ll << i)) ? c : 1);
                        ncr = (1 + ((n >> i) & 1) + cr >= 2);

                        dp[i + 1][nc][np][ncr] += dp[i][c][p][cr];

//                        if(dp[i][c][p][cr])
//                            cout << i << ' ' << c << ' ' << p << ' ' << cr << ' ' << dp[i][c][p][cr] << endl;
                    }

        cout << dp[N - 1][0][1][0] << "\n";
    }
}