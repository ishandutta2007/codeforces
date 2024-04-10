#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
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

#define runSieve
const int N=1000005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

const int NN = 200005,NNN = 500005;

int cnt[NNN];
bitset<NN> vis;
vector<int> v[NN];


int _runtimeTerror_()
{
    int n,Q;
    cin>>n>>Q;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        int k = a[i];
        while(k!=1 && !prime[k])
        {
            ll z=pf[k];
            while(k%z==0)k/=z;
            v[i].pb(z);
        }
        if(k!=1)
            v[i].pb(k);
    }
    int cur = 0;
    long long ans = 0;
    auto f = [&](int x)
    {
        int u = sz(v[x]);
        ll val = cur;
        vector<int> dp(1<<u,1);
        for(int i=1;i<(1<<u);++i)
        {
            int l = log2(i&-i);
            dp[i] = v[x][l]*dp[i-(i&-i)];
            val += popcount(i)&1?-cnt[dp[i]]:cnt[dp[i]];
        }
        return val;
    };
    auto add = [&](int x,bool add)
    {
        cur += add?1:-1;
        int u = sz(v[x]);
        vector<int> dp(1<<u,1);
        for(int i=1;i<(1<<u);++i)
        {
            int l = log2(i&-i);
            dp[i] = v[x][l]*dp[i-(i&-i)];
            cnt[dp[i]] += add?1:-1;
        }
    };
    for(int i=0;i<Q;++i)
    {
        int x;
        cin>>x;
        --x;
        if(vis[x])
        {
            add(x,0);
            ans -= f(x);
        }
        else
        {
            ans += f(x);
            add(x,1);
        }
        cout<<ans<<"\n";
        vis[x] = 1-vis[x];
    }
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