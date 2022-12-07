#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=1e9;
    cin>>n;
    int ar[n], ar2[n], dp[n+1], dp2[n+1];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    for(int a=0; a<=n; a++) dp[a]=inf, dp2[a]=inf;
    dp[n]=0;
    for(int i=0; i<60; i++)
    {
        int yk=0, pref[2]={0, 0}, suf[2]={0, 0};
        for(int a=0; a<n; a++)
        {
            if(ar[a]&(1ll<<i)) suf[1]++;
            else suf[0]++, ar2[yk]=ar[a], yk++;
        }
        for(int a=0; a<=n; a++)
        {
            if(dp[a]!=inf)
            {
                dp2[pref[0]]=min(dp2[pref[0]], dp[a]+pref[1]+suf[0]);
                dp2[pref[0]+pref[1]+suf[0]]=min(dp2[pref[0]+pref[1]+suf[0]], dp[a]+pref[0]+suf[1]);
            }
            if(a<n)
            {
                if(ar[a]&(1ll<<i))
                {
                    ar2[yk]=ar[a], yk++, pref[1]++, suf[1]--;
                }
                else pref[0]++, suf[0]--;
            }
        }
        for(int a=0; a<n; a++) ar[a]=ar2[a], dp[a]=dp2[a], dp2[a]=inf;
        dp[n]=dp2[n], dp2[n]=inf;
    }
    cout<<dp[n];

}