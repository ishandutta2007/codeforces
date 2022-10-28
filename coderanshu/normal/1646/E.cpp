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
    int n, m;
    cin >> n >> m;
    ll ans = 1;
    vector<int> vis(n + 1, 0);
    vis[1] = 1;
    for(int i=1;i<=n;++i) {
        if(vis[i]) {
            continue;
        }
        vector<int> a;
        ll cur = 1;
        int cnt = 0;
        while(cur * i <= n) {
            ++cnt;
            cur *= i;
            vis[cur] = 1;
            a.push_back(cnt);
        }
        int s = sz(a);
        for(int j=1;j<(1 << s);++j) {
            ll f = -1, lcm = -1;
            bool good = true;
            for(int k=0;k<s;++k) {
                if(j & (1 << k)) {
                    if(f == -1) {
                        f = a[k];
                    }
                    if(lcm == -1) {
                        lcm = a[k];
                    }
                    else {
                        lcm = lcm / __gcd(lcm, a[k] * 1ll) * a[k];
                        if(lcm > 1e9) {
                            good = false;
                            break;
                        }
                    }
                }
            }
            if(!good) {
                continue;
            }
            lcm /= f;
            if(popcount(j) & 1) {
                ans += m / lcm;
            }
            else {
                ans -= m / lcm;
            }
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}