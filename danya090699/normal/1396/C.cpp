#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, r1, r2, r3, d, an;
    cin>>n>>r1>>r2>>r3>>d;
    int dp[2]={0, inf}, dp2[2]={0, 0};
    for(int a=0; a<n; a++)
    {
        int q, d0 = (a==0) ? 0 : d;
        scanf("%lld", &q);
        int w0=r1*q+r3, w1=min(w0, min(r2, (q+1)*r1)+r1);

        if(a==n-1) an=dp[1]+w0;

        dp2[0]=min(dp[0]+w0, dp[1]+w1)+d0;
        dp2[1]=min(dp[0], dp[1])+w1+d0+d*2;

        dp[0]=dp2[0], dp[1]=dp2[1];
        dp2[0]=0, dp2[1]=0;



    }
    cout<<min(an, min(dp[0], dp[1]));
}