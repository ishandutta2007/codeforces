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

int _runtimeTerror_()
{
    int n,H;
    cin>>n>>H;
    vector<pii> v(n+1);
    ld ans = 0;
    for(int i=1;i<=n;++i)
        cin>>v[i].F>>v[i].S;

    int X = v[n].F,Y = v[n].S + H;
    auto dis = [&](pii a,pii b)
    {
        return sqrt(pow(a.F-b.F,2) + pow(a.S-b.S,2));
    };
    auto ccw = [&](pii a,pii b)
    {
        ll cr = (a.F-X)*1ll*(b.S-Y) - (b.F-X)*1ll*(a.S-Y);
        return cr<0;
    };
    ans += dis(v[n-1],v[n]);
    ld slope = 1.0*(Y-v[n-1].S)/(X-v[n-1].F);
    for(int i=n-2;i>=1;--i)
    {
        ld m = 1.0*(v[i+1].S-v[i].S)/(v[i+1].F-v[i].F);
        ld C = Y - slope*X;
        ld c = v[i].S - m * v[i].F;
        ld x = (C-c)/(m-slope);
        ld y = m*x + c;
        if(m == slope)
        {
            if(abs(c-C)<=1e-8)
            {
                ans += dis(v[i],v[i+1]);
            }
        }
        else
        {
            if(ccw(v[i],v[i+1]) || slope<m)
                continue;
            ld x = (C-c)/(m-slope);
            if(x>v[i+1].F)
                ans += dis(v[i],v[i+1]);
            else if(x>=v[i].F)
            {
                ld y = m*x + c;
                ans += sqrt(pow(v[i].F-x,2) + pow(v[i].S-y,2));
            }
        }
        amin(slope,1.0*(Y-v[i].S)/(X-v[i].F));
    }
    cout<<fixed<<setprecision(20);
    cout<<ans<<"\n";
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