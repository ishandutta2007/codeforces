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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }

    string ans((1 << 20), '0');
    map<pii,int> dp;
    auto f = [&](int have, int want) {
        assert(have >= 0);
        if(want <= 0) {
            if(have == 0) {
                return 1;
            }
            return 0;
        }
        if(dp.count({have, want})) {
            return dp[{have, want}];
        }
        int f = 0;
        for(int i=want;i<=have;++i) {
            if((i & have) == i) {
                f ^= 1;
            }
        }
        return dp[{have, want}] = f;
    };  

    for(int i=0;i<n;++i) {
        int have = n - 1;
        int want = k;
        have -= i > 0;
        want -= i > 0;
        have -= i < n - 1;
        want -= i < n - 1;
        if(f(have, want)) {
            ans[a[i]] ^= '0' ^ '1';
        }
        ll cur = a[i];
        int sum = 0;
        for(int j=i+1;j<n;++j) {
            int have = n - 1;
            int want = k;
            have -= i > 0;
            want -= i > 0;
            have -= j < n - 1;
            want -= j < n - 1;
            sum += a[j];
            have -= j - i;
            if(sum > 20) {
                break;
            }
            if(cur * (1 << sum) >= (1 << 20)) {
                break;
            }
            if(f(have, want)) {
                // debug(i,j,have,want);
                ans[cur * (1 << sum)] ^= '0' ^ '1';
            }
        }
    }
    while(ans.back() == '0' and sz(ans) > 1) {
        ans.pop_back();
    }
    reverse(all(ans));
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}