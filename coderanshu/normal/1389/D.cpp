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

int _runtimeTerror_(int tt)
{
    ll n,k;
    cin>>n>>k;
    pll a,b;

    cin>>a.F>>a.S>>b.F>>b.S;
    bool isect=false;
    if(a.F>b.F)
        swap(a,b);
    if(b.F<=a.S)
        isect=true;
    ll ans=0;
    if(isect)
    {
        if(b.S<=a.S)
        {
            ans=b.S-b.F;
        }
        else
            ans=a.S-b.F;
        ans*=n;
    }
    if(ans>=k)
    {
        cout<<"0\n";return 0;
    }
    ll one=0;
    if(isect)
    {
        if(b.S<=a.S)
            one=(a.S-a.F)-(b.S-b.F);
        else
            one=b.S-a.F-(a.S-b.F);
    }
    one*=n;
    if(ans+one>=k)
    {
        cout<<(k-ans)<<"\n";
        return 0;
    }
    ll moves=one;
    ans+=one;
    ll r=k-ans;
    if(!isect)
        assert(ans==0);
    ll notisect=b.F-a.S;
    ll tot=b.S-a.F;
    bool made=false;
    for(int i=1;i<=n;++i)
    {
        if(r==0)break;
        if(!isect)
        {
            if(notisect<=r)
            {
                made=true;
                moves+=notisect;
                moves+=min(r,tot);
                r-=min(r,tot);
            }
        }
    }
    if(!isect && !made && r!=0)
    {
        moves+=notisect;
        moves+=min(r,tot);
        r-=min(r,tot);
    }
    moves+=2*r;
    cout<<moves<<"\n";
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
    int tt=0;
    while(TESTS--)
        _runtimeTerror_(++tt);
    return 0;
}