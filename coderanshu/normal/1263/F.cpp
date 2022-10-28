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

const int N = 2002;

vector<int> v[N][2];
int l[N][2],r[N][2];

int cnt[N];

int dp[N][2];

void dfs(int s,int p,int u)
{
    if(l[s][u] == 0)
    {
        assert(r[s][u] == 0);
        l[s][u] = 1e9,r[s][u] = -1;
    }
    for(auto &j:v[s][u])
    {
        if(j!=p)
        {
            dfs(j,s,u);
            amin(l[s][u],l[j][u]);
            amax(r[s][u],r[j][u]);
        }
    }
}

int _runtimeTerror_()
{
    int n,A,B;
    cin>>n;
    cin>>A;
    for(int i=2;i<=A;++i)
    {
        int p;
        cin>>p;
        v[p][0].pb(i);
    }    
    for(int i=1;i<=n;++i)
    {
        int x;cin>>x;
        l[x][0] = i,r[x][0] = i;
    }
    cin>>B;
    for(int i=2;i<=B;++i)
    {
        int p;
        cin>>p;
        v[p][1].pb(i);
    }    
    for(int i=1;i<=n;++i)
    {
        int x;cin>>x;
        l[x][1] = i,r[x][1] = i;
    }
    dfs(1,0,0);dfs(1,0,1);
    dp[0][0] = dp[0][1] = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cnt[j] = 0;
        for(int j=2;j<=A;++j)
            if(r[j][0]<=i)
                ++cnt[l[j][0]];
        int sum = 0;
        for(int j=i;j>=1;--j)
        {
            sum += cnt[j];
            amax(dp[i][0],dp[j-1][1] + sum);
        }
        sum = 0;
        for(int j=1;j<=n;++j)
            cnt[j] = 0;
        for(int j=2;j<=B;++j)
            if(r[j][1]<=i)
                ++cnt[l[j][1]];
        for(int j=i;j>=1;--j)
        {
            sum += cnt[j];
            amax(dp[i][1],dp[j-1][0] + sum);
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<"\n";
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