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
    vector<vector<int>> ids(n + 1);
    string s;
    cin >> s;
    int sum = 0;
    ids[0].push_back(0);
    for(int i=0;i<2 * n;++i) {
        sum += s[i] == '(' ? 1: -1;
        ids[sum].push_back(i + 1);
    }
    int ans = 0;
    function<void(int, int, int x)> dfs = [&](int l, int r, int x) {
        if(l >= r) {
            return ;
        }
        debug(l, r);
        auto it = lower_bound(all(ids[x]), l) - ids[x].begin();
        vector<int> t = {l};
        while(it < sz(ids[x]) and ids[x][it] <= r) {
            t.push_back(ids[x][it]);
            ++it;
        }
        ++ans;
        for(int i=1;i<sz(t);++i) {
            dfs(t[i - 1] + 1, t[i] - 1, x + 1);
        }
    };
    dfs(1, 2 * n, 0);
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