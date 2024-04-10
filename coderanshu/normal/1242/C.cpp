#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define int long long
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 5002,K =17;

ll a[K][N];
int ni[K];
ll sum[K],Sum;
pii dp[1<<K];
bool pos[1<<K];
pii ans[K];

map<int,pii> mp;
bitset<K> vis;

void dfs(int i,ll val,int id,ll u,int msk)
{
    ll x = sum[i] - u;
    x = Sum - x;
    if(x == val)
    {
        dp[msk] = {id,val};
        pos[msk] = true;
        return ;
    }
    vis[i] = 1;
    if(!mp.count(x))
        return ;
    auto y = mp[x];
    if(vis[y.F])
        return ;
    msk |= (1<<y.F);
    dfs(y.F,val,id,x,msk);
}

void go_(int i,ll val,int id,ll u)
{
    ll x = sum[i] - u;
    x = Sum - x;
    if(x == val)
    {
        ans[id].F = val,ans[id].S = i;return ;
    }
    auto y = mp[x];
    ans[y.F].F = x,ans[y.F].S = i;
    go_(y.F,val,id,x);
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>ni[i];
        for(int j=0;j<ni[i];++j)
        {
            cin>>a[i][j];
            sum[i] += a[i][j];
            Sum += a[i][j];
            mp[a[i][j]] = {i,j};
        }
    }
    if(Sum % n)
    {
        cout<<"No\n";return 0;
    }
    Sum /= n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<ni[i];++j)
        {
            vis.reset();
            dfs(i,a[i][j],i,a[i][j],1<<i);
        }
    }
    vector<int> dp2(1<<n,false);
    dp2[0] = true;
    for(int i=1;i<(1<<n);++i)
    {
        for(int j = i;j;j = (j-1)&i)
        {
            if(pos[j] && dp2[i^j])
                dp2[i] = true;
        }
    }
    if(!dp2.back())
    {
        cout<<"No\n";return 0;
    }
    cout<<"Yes\n";
    int mask = (1<<n)-1;
    while(mask)
    {
        int msk = 0;
        for(int j=mask;j;j = (j-1)&mask)
        {
            if(pos[j] && dp2[mask^j])
                msk = j;
        }
        go_(dp[msk].F,dp[msk].S,dp[msk].F,dp[msk].S);
        mask ^= msk;

    }
    for(int i=0;i<n;++i)
        cout<<ans[i].F<<" "<<ans[i].S+1<<"\n";
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}