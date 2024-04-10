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
int pf[N];
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

int ans[N];
ll sum[N];

int _runtimeTerror_()
{
    int c;
    cin>>c;
    cout<<(ans[c] <= 1e7?ans[c]:-1)<<"\n";
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
    ans[1] = 1;
    sum[1] = 1;
    for(int i=2;i<=1e7;++i)
        ans[i] = 1e9;
    for(int i=2;i<=1e7;++i)
    {
        if(prime[i])
            amin(ans[i+1],i),sum[i] = i+1;
        else
        {
            int u = pf[i];
            ll val = 1;
            int cur = i;
            ll f = 1;
            while(cur % u == 0)
            {
                cur /= u;
                f *= u;
                val += f;
            }
            sum[i] = val * sum[cur];
            if(sum[i] <= 1e7)
                amin(ans[sum[i]],i);
        }
    }
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}