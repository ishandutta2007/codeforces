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
    int n, d;
    cin >> n >> d;
    vector<int> p(n+1), sub(n+1);
    for(int i=1;i<=n;++i) {
        p[i] = i, sub[i] = 1;
    }
    function<int(int)> parent = [&](int i) {
        return p[i] = (p[i] == i) ? i : parent(p[i]);
    };
    int cnt = 0;
    function<void(int,int)> merge = [&](int x,int y) {
        x = parent(x), y = parent(y);
        if(x == y) {
            return ;
        }
        if(sub[x] > sub[y]) {
            swap(x, y);
        }
        sub[y] += sub[x];
        p[x] = y;
        ++cnt;
    };
    for(int i=1;i<=d;++i) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
        int rem = i - cnt + 1;
        vector<int> szs;
        for(int j=1;j<=n;++j) {
            if(parent(j) == j) {
                szs.push_back(sub[j]);
            }
        }
        sort(all(szs),greater<int>());
        int ans = 0;
        for(int j=0;j<rem;++j) {
            ans += szs[j];
        }
        cout << ans - 1 << "\n";
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}