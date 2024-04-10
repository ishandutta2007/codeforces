#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 4001;
const int T = 86400;

int dp[N][N],t[N],d[N],n,k;

int obr(int last,int t,int d)
{
    return max(t,last)+d;
}

int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> t[i] >> d[i];
    for (int i=0; i<=k; i++)
        dp[0][i]=1;
    for (int i=1; i<=n; i++)
    {
        dp[i][0]=obr(dp[i-1][0],t[i],d[i]);
        for (int j=1; j<=k; j++)
            dp[i][j]=min(dp[i-1][j-1],obr(dp[i-1][j],t[i],d[i]));
    }
    int ans=0;
    for (int i=T; i>=1; i--)
    {
        int x=1;
        while (x<=n && t[x]<=i)x++;
        ans = max(ans, i-dp[x-1][k]+1);
    }
    cout << ans << endl;
    return 0;
}