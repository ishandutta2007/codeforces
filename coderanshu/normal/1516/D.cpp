// Har Har Mahadev
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
const int N=100005;
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

int dp[N][20];

int _runtimeTerror_()
{
    int n,Q;
    cin>>n>>Q;
    vector<int> a(n+1);
    map<int,int> last;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int cur = n;
    dp[n+1][0] = n+1;
    for(int i=n;i>=1;--i)
    {
        int k = a[i];
        while(k!=1 && !prime[k])
        {
            ll z=pf[k];
            if(last.count(z))
                amin(cur,last[z]-1);
            last[z] = i;
            while(k%z==0)k/=z;
        }
        if(k != 1 && last.count(k))
            amin(cur,last[k]-1);
        if(k != 1)
            last[k] = i;
        dp[i][0] = cur+1;
    }
    for(int j=1;j<=19;++j)
    {
        for(int i=1;i<=n+1;++i)
        {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    for(int i=0;i<Q;++i)
    {
        int l,r;
        cin>>l>>r;
        int ans = 0,cur = l;
        for(int j=19;j>=0;--j)
        {
            if(dp[cur][j] <= r)
            {
                cur = dp[cur][j];
                ans += (1<<j);
            }
        }
        ++ans;
        cout<<ans<<"\n";
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