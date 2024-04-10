#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
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

const int N = 1000005;

bitset<N> dp,vis;
vector<int> v[N];

int cnt = 0;

void dfs(int s)
{
    ++cnt;
    vis[s] = 1;
    for(auto j:v[s])
        if(!vis[j])
            dfs(j);
}

int sz[N];

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        v[x].pb(i),v[i].pb(x);
    }
    int sum = 0,rem = 0;
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            cnt = 0;
            dfs(i);
            ++sz[cnt];
            sum += cnt/2;
            rem += cnt%2;
        }
    }
    dp[0] = 1;
    for(int i=1;i<=n;++i)
    {
        if(!sz[i])
            continue;
        int u = 1;
        while(u<=sz[i])
        {
            dp |= dp<<(u*i);
            sz[i] -= u;
            u <<= 1;
        }
        if(sz[i])
            dp |= dp<<(sz[i]*i);
    }
    int mi = dp[k]?k:k+1;
    cout<<mi<<" ";
    if(sum>=k)
    {
        cout<<2*k<<"\n";
        return 0;
    }
    int mx = 2*sum;
    k -= sum;
    mx += min(rem,k);
    cout<<mx<<"\n";
    return 0;
}

int main()
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