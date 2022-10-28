#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
vector<ll> v[300005];
bool vis[300005];
void dfs(ll s,ll nv)
{
    if(s==nv)
        return ;
    vis[s]=true;
    for(auto j:v[s])
    {
        if(!vis[j])
            dfs(j,nv);
    }
}
int _runtimeTerror_()
{
    ll n,x,y,u,w,i;
    cin>>n>>x>>y;
    for(i=0;i<n-1;++i)
    {
        cin>>u>>w;
        v[u].pb(w);v[w].pb(u);
    }
    memf(vis);
    dfs(x,y);
    ll ans=1,count=0;
    for(i=1;i<=n;++i)
    {
        if(!vis[i])count++;
    }
    ans*=count;
    memf(vis);
    dfs(y,x);
    count=0;
    for(i=1;i<=n;++i)
    {
        if(!vis[i])count++;
    }
    ans*=count;
    cout<<(n*(n-1))-ans<<endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int tests=1;
    //cin>>tests;
    while(tests--)
        _runtimeTerror_();
    return 0;
}