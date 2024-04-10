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
    int n,k;
    cin >> n >> k;
    int off = 0;
    vector<int> s;
    for(int i=0;i<n;++i)
        s.push_back(i);
    auto Xor = [&](int a,int b)
    {
        ll ans = 0,cur = 1;
        while(a || b)
        {
            int x = a % k,y = b % k;
            ans += (x + y) % k * cur;
            cur *= k;
            a /= k,b /= k;
        }
        return ans;
    };
    auto negXor = [&](int b,int a)
    {
        ll ans = 0,cur = 1;
        while(a || b)
        {
            int x = a % k,y = b % k;
            ans += (x - y + k) % k * cur;
            cur *= k;
            a /= k,b /= k;
        }
        return ans;
    };
    int it = 0;
    while(true)
    {
        int cur = s.back();
        s.pop_back();
        // debug(cur,off);
        if(it % 2 == 0)
            cout << Xor(cur,off) << "\n" << flush;
        else
            cout << negXor(cur, off) << "\n" << flush;
        int r;
        cin >> r;
        if(r == 1)
            break;
        if(it % 2 == 0)
            off = negXor(off, Xor(cur,off));
        else
            off = negXor(off, negXor(cur,off));
        ++it;
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