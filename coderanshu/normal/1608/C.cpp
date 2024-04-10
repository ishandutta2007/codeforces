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
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for(int i=1;i<=n;++i) {
        cin >> b[i];
    }
    vector<int> f(n);
    iota(all(f),1);
    sort(all(f), [&](int x,int y) {
        return a[x] < a[y];
    });
    string ans(n,'0');
    ll mn = INF;
    vector<ll> pmax(n, -INF);
    pmax[0] = b[f[0]];
    for(int i=1;i<n;++i) {
        pmax[i] = max(pmax[i-1], b[f[i]]);
    }
    for(int i=n-1;i>=0;--i) {
        if(pmax[i] >= mn || i == n - 1) {
            ans[f[i]-1] = '1';
        }
        else {
        	break;
        }
        amin(mn, b[f[i]]);
    }
    cout << ans << "\n";
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
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}