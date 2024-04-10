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
#define ld double

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

ld sy,a,b;
const int N=200005;
ll l[N],r[N],p[2*N];
ll n;
set<pair<ld,pair<bool,ll>>> s;
int _runtimeTerror_()
{
    cin>>sy>>a>>b;
    cin>>n;
    sy*=-1;
    for(int i=0;i<n;++i)
    {
        cin>>l[i]>>r[i];
        s.insert({l[i]*1.0,{true,2*i+2}});
        s.insert({r[i]*1.0,{false,2*i+3}});
    }
    p[0]=p[1]=0;
    for(int i=1;i<=n;++i)
    {
        p[i*2]=p[i*2-1]-l[i-1];
        p[i*2+1]=p[i*2]+r[i-1];
    }
    ll q;
    cin>>q;
    cout<<fixed<<setprecision(20);
    for(int i=0;i<q;++i)
    {
        ll xi,yi;
        cin>>xi>>yi;
        ld ans=0;
        ld right=(xi-b)*1.0*(sy)/(sy+yi)+b;
        ld left=a+(xi-a)*1.0*(sy)/(sy+yi);
        auto it1=s.upper_bound({right,{0,-1}});
        auto it2=s.lower_bound({left,{0,-1}});
        if(it2==s.end() || it1==s.begin())
        {
            cout<<"0\n";continue;
        }
        --it1;
        ans+=p[it1->S.S]-p[it2->S.S-1];
        if(!(it2->S.F))
            ans-=left;
        if(it1->S.F)
            ans+=right;
        ans*=(sy+yi)/yi;
        cout<<ans<<endl;

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
    cerr<<"\n"<<_time_;
    return 0;
}