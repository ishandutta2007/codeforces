#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int MOD = 998244353;
const int N = 200005;
const int Q = 700;

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int dp[N][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

//    cout << 1 << endl;

    dp[0][0] = 1;

    vector <int> ans(n + 1);

    for(int j = 1; j < Q; j++)
    {
        for(int i = k + j - 1; i <= n; i++)
            dp[i][1] = add(dp[i - (k + j - 1)][0], dp[i - (k + j - 1)][1]);

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = dp[i][1];
            dp[i][1] = 0;
            ans[i] = add(ans[i], dp[i][0]);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}