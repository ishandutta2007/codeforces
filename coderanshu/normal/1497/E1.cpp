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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

#define runSieve
const int N=10000005;
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

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1,0),dp(n+1,0);
    map<vector<int>,int> last;
    int r = 1;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        int k = a[i];
        vector<int> pr;
        while(k!=1 && !prime[k])
        {
            ll z=pf[k],cnt = 0;
            while(k%z==0)k/=z,++cnt;
            if(cnt&1)
                pr.pb(z);
        }
        if(k!=1)
            pr.pb(k);
        sort(all(pr));
        if(last.count(pr))
            amax(r,last[pr]+1);
        last[pr] = i;
        dp[i] = dp[r-1]+1;
    }
    cout<<dp[n]<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}