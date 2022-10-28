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
const int N=10005,NN=100005;
pair<ld,ld> wall[NN];
ld angle[N],lb[NN],ub[NN];
ll n,V;
ld cons;
ld findIt(ld x,ld y)
{
    auto eval=[&](ld x,ld p){
        return p*tan(x)*(1-p/(cons*sin(2*x)));
    };
    ll op=50;
    ld lo=0,hi=PI/4;
    while(lo<=hi)
    {
        ld mid=(lo+hi)/2.0;
        if(eval(mid,x)>=y)
            hi=mid-0.0000001;
        else 
            lo=mid+0.0000001;
    }
    return lo;
}
// binary search on doubles
map<ld,pair<ld,ld>> ans;
set<ld> pro;
int _runtimeTerror_()
{
    cin>>n>>V;
    cons = (V*V)/9.8;
    for(int i=0;i<n;++i)
    {
        cin>>angle[i];
        pro.insert(angle[i]);
    }
    ll m;
    cin>>m;
    for(int i=0;i<m;++i)
        cin>>wall[i].F>>wall[i].S;
    sort(wall,wall+m);
    auto eval=[&](ld an,ld x){
        return x*tan(an)*(1-x/cons/sin(2*an));
    };
    for(int i=0;i<m;++i)
    {
        vector<ld> v;
        if(wall[i].F>=cons)break;
        lb[i]=findIt(wall[i].F,0);
        ub[i]=findIt(wall[i].F,wall[i].S);
        auto it=pro.lower_bound(lb[i]);
        auto it2=pro.upper_bound(ub[i]);
        for(auto j=it;j!=it2;++j)
            ans[*j].S=eval(*j,wall[i].F),v.pb(*j),ans[*j].F=wall[i].F;
        for(auto j:v)
            pro.erase(j);
    }
    for(auto j:pro)
        ans[j].S=0,ans[j].F=cons*sin(j*2.0);
    cout<<fixed<<setprecision(20);
    for(int i=0;i<n;++i)
    {
        cout<<ans[angle[i]].F<<" "<<ans[angle[i]].S<<endl;
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