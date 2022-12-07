#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, s, m, k;
    cin>>n>>s>>m>>k;
    m=min(m, n);
    int ar[n], rr[n+1];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<=n; a++) rr[a]=a;
    for(int a=0; a<s; a++)
    {
        int l, r;
        cin>>l>>r;
        rr[l-1]=max(rr[l-1], r);
    }
    for(int a=1; a<=n; a++) rr[a]=max(rr[a], rr[a-1]);

    int lg=0, rg=inf;
    while(rg-lg>1)
    {
        int mid=(lg+rg)>>1;
        int dp[n+1][n+1];
        for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=-1;
        dp[0][0]=0;
        for(int a=0; a<n; a++)
        {
            int q=0;
            for(int b=a; b<rr[a]; b++) if(ar[b]<=mid) q++;
            for(int b=0; b<=n; b++)
            {
                if(dp[a][b]!=-1)
                {
                    dp[a+1][b]=max(dp[a+1][b], dp[a][b]);
                    if(rr[a]>a) dp[rr[a]][b+1]=max(dp[rr[a]][b+1], dp[a][b]+q);
                }
            }
        }
        bool ok=0;
        for(int a=0; a<=m; a++) if(dp[n][a]>=k) ok=1;
        if(ok) rg=mid;
        else lg=mid;
    }
    if(rg!=inf) cout<<rg;
    else cout<<-1;
}