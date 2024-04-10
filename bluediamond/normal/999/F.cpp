#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


const ll N=500;
const ll K=10;
const ll VMAX=100000;

ll n,k;
ll v[N*K+5];
ll f[N+5],s[K+5];
ll ap[VMAX+5],caut[VMAX+5];

ll dp[N+5][N*K+5]; /// dp[sum][cate]

ll ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(ll i=1;i<=n*k;i++)
    {
        cin>>v[i];
        ap[v[i]]++;
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>f[i];
        caut[f[i]]++;
    }
    for(ll i=1;i<=k;i++)
        cin>>s[i];
    for(ll x=1;x<=VMAX;x++)
    {
        if(ap[x]==0 || caut[x]==0)
            continue;
        ll cnt=min(ap[x],caut[x]*k);
        dp[0][0]=0;
        ll bst=0;
        for(ll cate=1;cate<=caut[x];cate++)
        {
            for(ll lst=1;lst<=k;lst++)
                for(ll sum=lst;sum<=min(cnt,cate*k);sum++)
                {
                    dp[cate][sum]=max(dp[cate][sum],dp[cate-1][sum-lst]+s[lst]);
                }
            bst=max(bst,dp[cate][cnt]);
        }
        ans+=bst;
     ///   cout<<x<<" : "<<caut[x]<<" , "<<cnt<<" ,, "<<dp[caut[x]][cnt]<<"\n";
        for(ll i=1;i<=caut[x];i++)
            for(ll j=0;j<=min(cnt,i*k);j++)
                dp[i][j]=0;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/