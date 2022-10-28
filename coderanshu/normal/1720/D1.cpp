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
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    vector<int> dp(n, 1);
    vector<map<int, array<int, 4>>> mp(20);

    map<int, int> nxt;
    nxt[0] = 1, nxt[1] = 3, nxt[2] = 0, nxt[3] = 2;

    auto query = [&](int i, int val, int mask) {
        if(!mp[i].count(val) or mp[i][val][nxt[mask]] == 0) {
            return int(-1e9);
        }
        return mp[i][val][nxt[mask]];
    };

    for(int i=0;i<n;++i) {
        int cur = a[i] ^ i;
        int val = 0;
        for(int j=19;j>=1;--j) {
            val += cur & (1 << j);
            int mask = ((a[i] >> (j - 1)) & 1) * 2 + ((i >> (j - 1)) & 1);
            amax(dp[i], query(j, val, mask) + 1);
        }
        val = 0;
        for(int j=19;j>=1;--j) {
            val += cur & (1 << j);
            int mask = ((a[i] >> (j - 1)) & 1) * 2 + ((i >> (j - 1)) & 1);
            amax(mp[j][val][mask], dp[i]);
        }
    }
    cout << *max_element(all(dp)) << "\n";
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