#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 oidhfdoif

using namespace std;

int n, a[100005], dp[100005][100];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<70;j++)
        dp[i][j]=-1000000000;

    dp[0][a[0]+30]=a[0];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<70;j++)
            dp[i+1][max(j, a[i+1]+30)]=max(dp[i+1][max(j, a[i+1]+30)], dp[i][j]+a[i+1]);
        dp[i+1][a[i+1]+30]=max(dp[i+1][a[i+1]+30], a[i+1]);
    }

    int Max=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<70;j++)
        Max=max(Max, dp[i][j]-j+30);
    cout << Max;

    /*cout << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=5;j++)
            cout << dp[i][j+30] << ' ';
        cout << endl;
    }*/
}