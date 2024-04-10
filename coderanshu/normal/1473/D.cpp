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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> p(n+1,0),mn(n+1,0),mx(n+1,0),smn(n+3,0),smx(n+3,0),sf(n+3,0);
    int cnt = 0;
    for(int i=0;i<n;++i)
    {
        cnt += s[i]=='+'?1:-1;
        p[i+1] = cnt;
        mn[i+1] = min(mn[i],cnt);
        mx[i+1] = max(mx[i],cnt);
    }
    cnt = 0;
    for(int i=n-1;i>=0;--i)
    {
        cnt += s[i]=='+'?1:-1;
        sf[i+1] = cnt;
        smn[i+1] = min(smn[i+2],cnt);
        smx[i+1] = max(smx[i+2],cnt);
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int min = mn[l-1];
        int max = mx[l-1];
        int cur = p[l-1];
        // cout<<cur<<"\n";
        // cout<<min<<" "<<max<<"\n";
        int t1 = smn[r+1],t2 = smx[r+1];
        swap(t1,t2);
        t1 *= -1,t2 *= -1;
        t1 += sf[r+1];
        t2 += sf[r+1];
        // cout<<t1<<" "<<t2<<"\n";
        amin(min,cur+t1);
        amax(max,cur+t2);
        cout<<(max-min+1)<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}