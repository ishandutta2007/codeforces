#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, k;
	cin>>n>>m>>k;
    int su[n][m+1];
    for(int a=0; a<n; a++)
    {
        su[a][0]=0;
        for(int b=1; b<=m; b++)
        {
            scanf("%d", &su[a][b]);
            su[a][b]+=su[a][b-1];
        }
    }
    int dp[n][m-k+1];
    for(int a=0; a<=m-k; a++) dp[0][a]=su[0][a+k]-su[0][a];
    for(int a=1; a<n; a++)
    {
        int pref[m-k+1], pref2[m-k+1], suf[m-k+1], suf2[m-k+1];
        for(int b=0; b<=m-k; b++)
        {
            pref[b]=dp[a-1][b]+su[a][b+k]-su[a][b];
            pref2[b]=dp[a-1][b]+su[a][b+k];
            if(b)
            {
                pref[b]=max(pref[b], pref[b-1]);
                pref2[b]=max(pref2[b], pref2[b-1]);
            }
        }
        for(int b=m-k; b>=0; b--)
        {
            suf[b]=dp[a-1][b]+su[a][b+k]-su[a][b];
            suf2[b]=dp[a-1][b]+su[a][m]-su[a][b];
            if(b+1<=m-k)
            {
                suf[b]=max(suf[b], suf[b+1]);
                suf2[b]=max(suf2[b], suf2[b+1]);
            }
        }
        for(int b=0; b<=m-k; b++)
        {
            dp[a][b]=0;
            if(b>=k) dp[a][b]=max(dp[a][b], pref[b-k]+su[a][b+k]-su[a][b]);
            if(b+k<=m-k) dp[a][b]=max(dp[a][b], suf[b+k]+su[a][b+k]-su[a][b]);
            dp[a][b]=max(dp[a][b], pref2[min(b+k, m-k)]-su[a][b]);
            dp[a][b]=max(dp[a][b], suf2[max(b-k, 0)]-(su[a][m]-su[a][b+k]));
        }
    }
    int an=0;
    for(int a=0; a<=m-k; a++) an=max(an, dp[n-1][a]);
    cout<<an;
}