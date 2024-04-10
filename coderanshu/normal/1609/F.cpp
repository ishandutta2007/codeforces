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
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    vector<int> l(n+1,1), r(n+1,1);
    vector<int> st;
    for(int i=n;i>=1;--i) {
        while(!st.empty() && a[i] < a[st.back()]) {
            l[st.back()] = i + 1;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for(int i=n;i>=1;--i) {
        while(!st.empty() && a[i] > a[st.back()]) {
            r[st.back()] = i + 1;
            st.pop_back();
        }
        st.push_back(i);
    }
    ll ans = 0;
    for(int i=0;i<=60;++i) {
        vector<pii> mn, mx;
        auto get = [&](int r, vector<pii> &a) {
            if(a.empty()) {
                return 0;
            }
            auto it = lower_bound(all(a),make_pair(r, 0)) - a.begin();
            if(it == a.size()) {
                return a.back().S;
            }
            int len = a[it].S, ans = 0;
            if(it > 0) {
                ans += a[it-1].S;
                len = a[it].S - a[it-1].S;
            }
            ans += max(0, r - (a[it].F - len + 1) + 1);
            return ans;
        };
        auto query = [&](int l, int r, vector<pii> &a) {
            return get(r, a) - get(l-1, a);
        };
        int cnt = 0;
        for(int j=1;j<=n;++j) {
            while(!mn.empty() && a[j] <= a[mn.back().F]) {
                cnt -= query(l[mn.back().F],mn.back().F, mx);
                mn.pop_back();
            }
            while(!mx.empty() && a[j] >= a[mx.back().F]) {
                cnt -= query(r[mx.back().F],mx.back().F, mn);
                mx.pop_back();
            }
            if(popcount(a[j]) == i) {
                int sum = 0;
                if(!mx.empty()) {
                    sum = mx.back().S;
                }
                sum += j - r[j] + 1;
                mx.push_back({j,sum});
                cnt += query(r[j], j, mn);
                sum = 0;
                if(!mn.empty()) {
                    sum = mn.back().S;
                }
                sum += j - l[j] + 1;
                mn.push_back({j,sum});
                cnt += query(l[j], j, mx);
            }
            ans += cnt;
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
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}