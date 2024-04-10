#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, r[2005], c[2005];
ld dp[2005][2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        r[x]++;
        c[y]++;
    }

    int kr = 0, kc = 0;

    for(int i = 0; i < n; i++)
        kr += (r[i] == 0);

    for(int i = 0; i < n; i++)
        kc += (c[i] == 0);

    for(int i = 0; i <= kr; i++)
        for(int j = 0; j <= kc; j++)
        {
            if(i == 0 && j == 0)
                dp[i][j] = 0;
            else
            {
                if(i > 0)
                    dp[i][j] += (1 + dp[i - 1][j]) * (ld)i / n * (ld)(n - j) / n;

                if(j > 0)
                    dp[i][j] += (1 + dp[i][j - 1]) * (ld)j / n * (ld)(n - i) / n;

                if(i > 0 && j > 0)
                    dp[i][j] += (1 + dp[i - 1][j - 1]) * (ld)i / n * (ld)j / n;

                ld p = (1 - (ld)(n - i) / n * (ld)(n - j) / n);

//                cout << "p = " << p << endl;

                if(p < 0.9999999)
                {
                    dp[i][j] /= p;
                    dp[i][j] += (ld)1 / p - 1;
                }
            }
        }
//
//    cout << kr << ' ' << kc << endl;
//
//    for(int i = 0; i <= kr; i++)
//    {
//        for(int j = 0; j <= kc; j++)
//            cout << dp[i][j] << ' ';
//
//        cout << endl;
//    }

    cout << setprecision(20) << dp[kr][kc];
}