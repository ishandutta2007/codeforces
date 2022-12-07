//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y)
{
    long long z=1ll*x*y;
    int l=0, r=2e9;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(1ll*mid*mid<=z) l=mid;
        else r=mid;
    }
    return (1ll*l*l==z);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mod=1e9+7;
    cin>>n;
    vector <pair <int, int> > gr;
    for(int a=0; a<n; a++)
    {
        int x, fo=0;
        cin>>x;
        for(int b=0; b<gr.size(); b++)
        {
            if(check(x, gr[b].first))
            {
                gr[b].second++, fo=1;
                break;
            }
        }
        if(fo==0) gr.push_back(make_pair(x, 1));
    }
    int ar[n], ar2[n], yk=0;
    for(int a=0; a<gr.size(); a++)
    {
        int st=yk+gr[a].second;
        for(yk; yk<st; yk++)
        {
            ar[yk]=a, ar2[yk]=gr[a].second;
        }
    }
    int dp[n][n+2], dp2[n][n+2];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=n+1; b++)
        {
            dp[a][b]=0, dp2[a][b]=0;
        }
    }
    dp[0][1]=1;
    for(int a=0; a<n; a++)
    {
        int ne=-1;
        if(a+1<n) ne=ar[a+1];
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<=n+1; c++)
            {
                if(dp[b][c]!=0)
                {
                    int d=a+1-b-c;
                    if(ar[a]==ne)
                    {
                        if(b>0) dp2[b-1][c]=(dp2[b-1][c]+1ll*b*dp[b][c])%mod;
                        if(c>0) dp2[b][c-1]=(dp2[b][c-1]+1ll*c*dp[b][c])%mod;
                        if(d>0) dp2[b][c]=(dp2[b][c]+1ll*d*dp[b][c])%mod;
                    }
                    else
                    {
                        int q=d-(ar2[a]-1);
                        int ins=d-q*2, out=q*2;
                        if(b>0) dp2[b-1+ins][c+2+out]=(dp2[b-1+ins][c+2+out]+1ll*b*dp[b][c])%mod;
                        if(c>0) dp2[b+ins][c+1+out]=(dp2[b+ins][c+1+out]+1ll*c*dp[b][c])%mod;
                        if(d>0) dp2[b+ins+1][c+out]=(dp2[b+ins+1][c+out]+1ll*d*dp[b][c])%mod;
                    }
                }
            }
        }
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<=n+1; c++)
            {
                dp[b][c]=dp2[b][c], dp2[b][c]=0;
            }
        }
    }
    cout<<dp[0][n+1];
}