#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD=998244353;

int n, k, dp[1005][4][2005];

int add(int a, int b, int c, int d)
{
    return (a+b+c+d)%MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

   cin >> n >> k;
   dp[1][0][1]=1;
   dp[1][1][2]=1;
   dp[1][2][2]=1;
   dp[1][3][1]=1;
   for(int i=2;i<=n;i++)
        for(int j=1;j<=k;j++)
   {
       dp[i][0][j]=add(dp[i-1][0][j], dp[i-1][1][j], dp[i-1][2][j], dp[i-1][3][j-1]);
       dp[i][1][j]=add(dp[i-1][0][j-1], dp[i-1][1][j], dp[i-1][2][j-2], dp[i-1][3][j-1]);
       dp[i][2][j]=add(dp[i-1][0][j-1], dp[i-1][1][j-2], dp[i-1][2][j], dp[i-1][3][j-1]);
       dp[i][3][j]=add(dp[i-1][0][j-1], dp[i-1][1][j], dp[i-1][2][j], dp[i-1][3][j]);
   }
   cout << add(dp[n][0][k], dp[n][1][k], dp[n][2][k], dp[n][3][k]);
}