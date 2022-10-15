#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=16+5;
const ll M=10000+5;

ll n,m;
ll v[N][M];
ll mi[N][N];

ll ans=0;

bool viz[N];
ll st[N];

void bkt(ll strat)
{
    if(strat==n)
    {
        ll a=st[1];
        ll b=st[n];
        ll cur=(1LL<<60);
        for(ll j=1;j<=n;j++)
        {
            cout<<st[j]<<" ";
        }
        cout<<"\n";
     //   cout<<cur<<"\n";
        ans=max(ans,cur);
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            if(viz[i]==0)
            {
                viz[i]=1;
                st[strat+1]=i;
                bkt(strat+1);
                viz[i]=0;
            }
        }
    }
}

ll dp[16][16][(1<<16)]; /// dp[st][dr][mask]
bool valid[16][16][(1<<16)];

void calc(ll st,ll dr,ll mask)
{
 //   cout<<st<<" "<<dr<<"\n";
    if(valid[st][dr][mask]==1) return;
    valid[st][dr][mask]=1;
    ll cnt=0;
    for(ll ant=0;ant<n;ant++)
    {
        if(mask&(1<<ant))
        {
            cnt++;
        }
    }
    for(ll ant=0;ant<n;ant++)
    {
        if(mask&(1<<ant) && ant!=dr)
        {
            if(cnt!=2 && ant==st) continue;
            calc(st,ant,mask-(1<<dr));
            dp[st][dr][mask]=max(dp[st][dr][mask],min(dp[st][ant][mask-(1<<dr)],mi[ant+1][dr+1]));
        }
    }
}

int32_t main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ll i=0;i<N;i++)
    {
        for(ll j=0;j<N;j++)
        {
            mi[i][j]=(1LL<<60);
        }
    }
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            for(ll k=1;k<=m;k++)
            {
                mi[i][j]=min(mi[i][j],abs(v[i][k]-v[j][k]));
                /**if(i==1 && j==2)
                {
                    cout<<k<<" : "<<v[i][k]<<" , "<<v[j][k]<<"\n";
                }**/
            }
        }
    }
    for(ll st=1;st<=n;st++)
    {
        dp[st-1][st-1][(1<<(st-1))]=(1LL<<60);
        valid[st-1][st-1][(1<<(st-1))]=1;
    }
    ll ans=0LL;
    for(ll st=1;st<=n;st++)
    {
        for(ll dr=1;dr<=n;dr++)
        {
            if(n>1 && dr==st) continue;
            calc(st-1,dr-1,(1<<n)-1);
            ll cur=dp[st-1][dr-1][(1<<n)-1];
          ///  cout<<cur<<" : ";
            for(ll k=2;k<=m;k++)
            {
                cur=min(cur,abs(v[dr][k-1]-v[st][k]));
            }
            ans=max(ans,cur);
            ///cout<<st-1<<" "<<dr-1<<" : "<<dp[st-1][dr-1][(1<<n)-1]<<"\n";
            if(dp[st-1][dr-1][(1<<n)-1]>=5)
            {
             //   cout<<st-1<<" "<<dr-1<<"\n";
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**

655 360 000
100 000 000
**/