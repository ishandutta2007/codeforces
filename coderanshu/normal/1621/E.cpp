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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    a.resize(m);
    reverse(all(a));
    vector<vector<array<int,2>>> stus(m);
    vector<ll> avg(m, 0);
    vector<ll> sum(m, 0);
    int cur = 0;
    for(int i=0;i<m;++i) {
        int s;
        cin >> s;
        stus[i].resize(s);
        for(int j=0;j<s;++j) {
            cin >> stus[i][j][0];
            stus[i][j][1] = cur++;
            avg[i] += stus[i][j][0];
        }
        sum[i] = avg[i];
        avg[i] = (avg[i] + s - 1)/s;
    }
    // teacher_age >= avg[i]
    vector<int> order(m);
    iota(all(order), 0);
    sort(all(order), [&](int x,int y) {
        return avg[x] < avg[y];
    });
    vector<bool> pref(m+10, 0), suff(m+10,0);
    vector<int> l(m+1, 0), r(m+10, m+1);

    pref[0] = 1, suff[m+1] = 1;
    for(int i=0;i<m;++i) {
        int u = order[i];
        if(avg[u] <= a[i]) {
            pref[i+1] = pref[i];
        }
        else {
            pref[i+1] = false;
        }
        amax(l[i+1], l[i]);
        if(i == m - 1 || (i < m - 1 && avg[u] > a[i + 1])) {
            l[i + 1] = i + 1;
        }
    }
    for(int i=m-1;i>=0;--i) {
        int u = order[i];
        if(avg[u] <= a[i]) {
            suff[i+1] = suff[i+2];
        }
        else {
            suff[i+1] = false;
        }
        r[i + 1] = r[i + 2];
        if((i == 0) || (i > 0 && avg[u] > a[i - 1])) {
            r[i + 1] = i + 1;
        }
    }
    auto savg = avg;
    sort(all(savg));
    string ans(cur, '0');
    // debug(a, savg);
    for(int i=0;i<m;++i) {
        int u = order[i];
        ll ss = sz(stus[u]);
        for(auto &[val, id]:stus[u]) {
            ll nxt_avg = (sum[u] - val + ss - 2) / (ss - 1);
            // debug(val, id, cur_avg, nxt_avg);
            auto nxt = upper_bound(all(savg), nxt_avg) - savg.begin();
            // debug(id, nxt, savg);
            if(nxt > i + 1) {
                // check nxt + 1here
                if(r[i + 2] <= nxt || !suff[nxt + 1] || !pref[i] || nxt_avg > a[nxt - 1]) {

                }
                else {  
                    ans[id] = '1';
                }
            }
            else if(nxt == i + 1 || nxt == i) {
                // debug(id);
                if(pref[i] && suff[i+2] && nxt_avg <= a[i]) {
                    ans[id] = '1';
                }
            }
            else {
                if(!suff[i+2] || !pref[nxt] || l[i] >= nxt + 1 || nxt_avg > a[nxt]) {

                }
                else {
                    ans[id] = '1';
                }
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
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}