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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    cnt[0] = 1;
    for(int i=2;i<=n;++i) {
        int p;
        cin >> p;
        ++cnt[p];
    }
    vector<int> a;
    for(int i=0;i<=n;++i) {
        if(cnt[i]) {
            a.push_back(cnt[i]);
        }
    }
    sort(all(a), greater<int>());
    int lo = sz(a), hi = n, ans = -1;
    auto f = [&](int x) {
        int n = sz(a);
        int cnt = 0;
        for(int i=0;i<n;++i) {
            cnt += max(0, a[i] - (x - i));
        }
        x -= sz(a);
        return cnt <= x;
    };
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(f(mid)) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}