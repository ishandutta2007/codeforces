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

const int N = 200005;
template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};
// call fenw.build(n);

fenwick<int> fenw;

int _runtimeTerror_()
{
    int n,t;
    cin>>n>>t;
    fenw.build(n);
    vector<int> have(n+1,-1);
    auto ask = [&](int l,int r)
    {
        assert(l == 1);
        if(have[r] != -1)
        {
            return fenw.get(r) + have[r];
        }
        cout<<"? ";
        cout<<l<<" "<<r<<"\n"<<flush;
        int x;
        cin>>x;
        int u = fenw.get(r);
        fenw.update(r,-u);
        fenw.update(r+1,u);
        have[r] = x;
        return x;
    };
    for(int i=1;i<=t;++i)
    {
        int k;
        cin>>k;
        int lo = 1,hi = n,ans = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            int u = ask(1,mid);
            int z = (mid - u);
            if(z >= k)
                ans = mid,hi = mid-1;
            else
                lo = mid+1;
        }
        cout<<"! "<<ans<<"\n"<<flush;
        fenw.update(ans,1);
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