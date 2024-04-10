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
int pow_n[N];
vector<int> divs[N];
int lpf[N],mobius[N];

void _lpf_()
{
    lpf[1]=1;
    for(int i=2;i<=N-2;++i)
    {
        if(!lpf[i])
        {
            for(int j=i;j<=N-2;j+=i)
            {
                if(!lpf[j])
                    lpf[j]=i;
            }
        }
    }
}
void Mobius()
{
    mobius[1]=1;
    for(int i=2;i<=N-2;++i)
    {
        if(lpf[i/lpf[i]]==lpf[i])
            mobius[i]=0;
        else 
            mobius[i]=-1*mobius[i/lpf[i]];
    }
}
 
int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<=k;++i)
        pow_n[i]=power(i,n,M);
    ll ans=0,val=1;
    for(int i=2;i<=k;++i)
    {
        for(auto j:divs[i])
        {
            val+=(pow_n[i/j]-pow_n[(i-1)/j])*mobius[j];
            val+=M;
            val%=M;
        }
        ans+=val^i;
        ans%=M;
    }  
    cout<<ans<<endl;
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
    for(int i=1;i<=2e6;++i)
    {
        for(int j=i;j<=2e6;j+=i)
            divs[j].pb(i);
    }
    int TESTS=1;
    //cin>>TESTS;
    _lpf_();
    Mobius();
    while(TESTS--)
        _runtimeTerror_();
    cerr<<"\n"<<_time_;
    return 0;
}