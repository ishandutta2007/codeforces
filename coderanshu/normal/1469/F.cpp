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

const int N = 400001;

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
fenwick<ll> fenw;

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    ll possible = 1;
    fenw.build(400000);
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        possible += a[i]-2;
    }
    if(possible<k)
    {
        cout<<"-1\n";return 0;
    }
    sort(all(a),greater<int>());
    fenw.update(1,1);
    fenw.update(2,-1);
    int cur = 0;
    ll t = 0;
    for(int i=1;i<N;++i)
    {
        // if(fenw.get(i) == 0)
        //     continue;
        // while(fenw.get(cur) == 0)
        //     ++cur;
        t += fenw.get(i);
        if(t>=k)
        {
            cout<<i-1<<"\n";return 0;
        }
        t += fenw.get(i+1);
        if(t>=k)
        {
            cout<<i<<"\n";return 0;
        }
        t -= fenw.get(i+1);
        t -= fenw.get(i);
        while(fenw.get(i) && cur<n)
        {
            fenw.update(i,-1);
            fenw.update(i+1,1);
            int l = a[cur]/2;
            int r = a[cur]-l-1;
            fenw.update(i+2,2);
            fenw.update(i+l+2,-1);
            fenw.update(i+r+2,-1);
            ++cur;
        }
        t += fenw.get(i);
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