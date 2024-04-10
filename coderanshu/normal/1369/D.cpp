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
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

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
const int N=2000005;
ll dp[N],pfx[N][3];
int _runtimeTerror_()
{
    ll n;
    cin>>n;
    cout<<pfx[n][n%3]*4%M<<'\n';
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
    int cnt[N];
    mem0(cnt);
    dp[3]=1;
    cnt[3]=1;
    for(int i=4;i<=N-3;++i)
    {
        dp[i]+=dp[i-1]+dp[i-2]*2;
        dp[i]%=M;
    }
    for(int i=1;i<=N-3;++i)
    {
        pfx[i][0]=pfx[i-1][0];
        pfx[i][1]=pfx[i-1][1];
        pfx[i][2]=pfx[i-1][2];
        pfx[i][i%3]+=dp[i];
        pfx[i][0]%=M;
        pfx[i][1]%=M;
        pfx[i][2]%=M;
    }
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}