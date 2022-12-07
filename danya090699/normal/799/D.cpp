#include <bits/stdc++.h>
#define int long long
using namespace std;
bool comp(int a, int b){return (a>b);}
main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, h, w, n, q;
    cin>>a>>b>>h>>w>>n;
    int ra[n];
    for(int a=0; a<n; a++) cin>>ra[a];
    sort(ra, ra+n, comp);
    q=min(n, 1ll*40);
    if(a>b) swap(a, b);
    if(h>w) swap(h, w);
    int dp[q+1][a+1];
    for(int c=0; c<=q; c++) for(int d=0; d<=a; d++) dp[c][d]=0;
    dp[0][h]=w;
    for(int c=0; c<q; c++)
    {
        for(int d=1; d<=a; d++)
        {
            if(dp[c][d]!=0)
            {
                int ne1=d*ra[c], ne2=dp[c][d];
                if(ne1>ne2) swap(ne1, ne2);
                if(ne1>a) ne1=a;
                if(ne2>b) ne2=b;
                dp[c+1][ne1]=max(dp[c+1][ne1], ne2);
                ne1=dp[c][d]*ra[c], ne2=d;
                if(ne1>ne2) swap(ne1, ne2);
                if(ne1>a) ne1=a;
                if(ne2>b) ne2=b;
                dp[c+1][ne1]=max(dp[c+1][ne1], ne2);
            }
        }
    }
    bool fo=0;
    //cout<<dp[0][a]<<" ";
    for(int c=0; c<=q; c++)
    {
        if(dp[c][a]>=b)
        {
            cout<<c;
            fo=1;
            break;
        }
    }
    if(fo==0) cout<<-1;
}