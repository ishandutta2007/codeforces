// Har Har Mahadev
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
    vector<ll> a(n+1, 0);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    ll x;
    cin >> x;
    for(int i=1;i<=n;++i) {
        a[i] -= x;
        a[i] += a[i-1];
    }
    int last = 0;
    int ans = 0;
    vector<pll> st;

    for(int i=1;i<=n;++i) {
        int l = 0;
        auto it = upper_bound(st.rbegin(),st.rend(),make_pair(a[i],(ll)(1e9)));
        if(it != st.rend()) {
            int bk = it - st.rbegin();
            l = st[sz(st)-1-bk].S+1;
        }
        if(last >= l && last <= i) {

        }
        else {
            ++ans;
            last = i;
        }
        while(!st.empty() && a[i-1] > a[st.back().S]) {
            st.pop_back();
        }
        st.push_back({a[i-1],i-1});
    }
    cout << n - ans << "\n";
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