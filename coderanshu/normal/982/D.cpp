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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<pii> a(n);
    vector<int> b(n+1);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].F;
        b[i+1] = a[i].F;
        a[i].S = i+1;
    }
    sort(a.begin(),a.end());
    vector<int> p(n+1),siz(n+1,1);
    iota(all(p),0);
    function<int(int)> parent = [&](int i)
    {
        return p[i] == i?i:parent(p[i]);
    };
    function<int(int,int)> merge = [&](int x,int y)
    {
        x = parent(x),y = parent(y);
        if(siz[x] > siz[y])
            swap(x,y);
        siz[y] += siz[x];
        p[x] = y;
        return siz[y];
    };
    multiset<int> A;
    auto add = [&](int i,int cur)
    {
        if(i > 1 && b[i-1] <= cur)
        {
            A.erase(A.find(siz[parent(i-1)]));
            merge(i,i-1);
        }
        if(i < n && b[i+1] <= cur)
        {
            A.erase(A.find(siz[parent(i+1)]));
            merge(i,i+1);
        }
        A.insert(siz[parent(i)]);
    };
    auto good = [&]()
    {
        if(A.empty())
            return true;
        if(*A.begin() == *A.rbegin())
            return true;
        return false;
    };
    int ans = a[0].F,val = 0;
    add(a[0].S,a[0].F);
    for(int i=1;i<n;++i)
    {
        if(good())
        {
            if(A.size() > val)
            {
                val = A.size();
                ans = a[i-1].F+1;
            }
            else if(A.size() == val)
                amin(ans,a[i-1].F+1);
        }
        add(a[i].S,a[i].F);
    }
    if(n == 1)
    {
        cout<<a[n-1].F+1<<"\n";
        return 0;
    }
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