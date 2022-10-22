#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[2005], dp[2005][2005][3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        dp[i][i][a[i]]=1;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(a[j]==1)
            {
                dp[i][j][2]=dp[i][j-1][2];
                dp[i][j][1]=max(dp[i][j-1][1], dp[i][j-1][2])+1;
            }
            else
            {
                dp[i][j][1]=dp[i][j-1][1];
                dp[i][j][2]=dp[i][j-1][2]+1;
            }
        }

    int Max=0;
    int k1=0;
    for(int i=0;i<n;i++)
    {
        if(i>0 && a[i-1]==1)
            k1++;
        int k2=0;
        for(int j=n-1;j>=i;j--)
        {
            if(j<n-1 && a[j+1]==2)
                k2++;
            Max=max(Max, k1+k2+max(dp[i][j][1], dp[i][j][2]));
        }
    }
    cout << Max;
}