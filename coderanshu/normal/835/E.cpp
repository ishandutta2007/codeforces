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
    int n,x,y;
    cin>>n>>x>>y;
    auto query = [&](vector<int> &x)
    {
        cout << "? " << sz(x) << " ";
        for(auto i:x)
            cout << i << " ";
        cout << "\n" << flush;
        int tmp;
        cin >> tmp;
        return tmp;
    };
    auto get = [&](vector<int> &a)
    {
        int n = sz(a);
        int ans = -1;
        int lo = 0,hi = n-1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            vector<int> t(a.begin(),a.begin()+mid+1);
            int u = query(t);
            if(u == y || u == (x ^ y))
                ans = mid,hi = mid - 1;
            else
                lo = mid + 1;
        }
        assert(ans != -1);
        return a[ans];
    };
    int good = 0,pos = -1;
    for(int i=0;i<10;++i)
    {
        vector<int> a;
        for(int j=1;j<=n;++j)
            if(j&(1<<i))
                a.push_back(j);
        if(a.empty())
            break;
        int t = query(a);
        if(t == y || t == (x ^ y))
        {
            good |= (1<<i);
            if(pos == -1)
                pos = get(a);
        }
    }
    assert(pos != -1);
    good ^= pos;
    if(pos > good)
        swap(pos,good);
    cout << "! " << pos << " " << good << "\n" << flush;
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