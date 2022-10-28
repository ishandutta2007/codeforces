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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

int _runtimeTerror_()
{
    int n;
    cin >> n;   

    vector<int> x(n), y(n), c(n);
    for(int i=0;i<n;++i) {
        cin >> x[i] >> y[i] >> c[i];
    }
    int ans = 0;
    auto solve = [&](vector<int> &x, vector<int> &y, vector<int> &c, int ldown, int lup, int right) {
        vector<int> f(n);
        iota(all(f), 0);
        sort(all(f), [&](int a, int b) {
            return x[a] < x[b];
        });
        vector<int> cnt(n+1, 0);
        for(int i=n-1;i>=0;--i) {
            cnt[i] = cnt[i+1] + (c[f[i]] == right);
        }
        {
            auto check = [&](int a) {
                if(a > cnt[0]) {
                    return false;
                } 
                int id = n-1;
                for(int i=n-1;i>=0;--i) {
                    if(cnt[i] == a) {
                        id = i;
                        break;
                    }
                }
                vector<int> low, high;
                for(int i=0;i<n;++i) {
                    if(x[f[i]] >= x[f[id]]) {
                        continue;
                    }
                    if(c[f[i]] == ldown) {
                        low.push_back(y[f[i]]);
                    }
                    else if(c[f[i]] == lup) {
                        high.push_back(-y[f[i]]);
                    }
                }
                sort(all(low));sort(all(high));
                if(sz(low) < a || sz(high) < a) {
                    return false;
                }
                return -high[a-1] > low[a-1];
            };
            int lo = 1, hi = n;
            while(lo <= hi) {
                int mid = (lo + hi)/2;
                if(check(mid)) {
                    amax(ans, mid);
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
        {
            auto check = [&](int a) {
                if(a > cnt[0]) {
                    return false;
                } 
                int id = n-1;
                for(int i=n-1;i>=0;--i) {
                    if(cnt[i] == a) {
                        id = i;
                        break;
                    }
                }
                vector<int> low, high;
                for(int i=0;i<n;++i) {
                    if(x[f[i]] >= x[f[id]]) {
                        continue;
                    }
                    if(c[f[i]] == ldown) {
                        low.push_back(x[f[i]]);
                    }
                    else if(c[f[i]] == lup) {
                        high.push_back(-x[f[i]]);
                    }
                }
                sort(all(low));sort(all(high));
                
                if(sz(low) < a || sz(high) < a) {
                    return false;
                }
                return -high[a-1] > low[a-1];
            };
            int lo = 1, hi = n;
            while(lo <= hi) {
                int mid = (lo + hi)/2;
                if(check(mid)) {
                    amax(ans, mid);
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
    };

    vector<int> cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    for(int i=0;i<n;++i) {
        x[i] = 1e9 - x[i];
    }
    cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    for(int i=0;i<n;++i) {
        x[i] = 1e9 - x[i];
    }
    swap(x, y);
    cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    for(int i=0;i<n;++i) {
        x[i] = 1e9 - x[i];
    }
    cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    cout << ans * 3 << "\n";
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