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

template<typename T=long long>
struct fenwick {
    vector<T> bit;
    int n;
    fenwick(int x) {
        n = x;
        bit.resize(x + 1, T(0));
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
    // kth element
    int getKth(T k) {
        int ans = 0;
        T cnt = 0;
        for(int i=20;i>=0;--i) {
            if(ans + (1 << i) <= n && cnt + bit[ans + (1 << i)] < k) {
                ans += (1 << i);
                cnt += bit[ans];
            }
        }
        if(ans == n) {
            return -1;
        }
        return ans + 1;
    }
    void insert(int x) {
        update(x, 1);
    }
    void erase(int x) {
        update(x, -1);
    }
};


int _runtimeTerror_()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<deque<int>> dq(26);
    for(int i=0;i<n;++i) {
        dq[a[i]-'a'].push_back(i+1);
    } 
    ll ans = INF;   
    ll cnt = 0;
    fenwick<ll> fenw(n);
    ll aux = 0;
    for(int i=1;i<=n;++i) {
        int c = b[i-1] - 'a';
        int close = n + 100;
        for(int j=0;j<c;++j) {
            if(!dq[j].empty()) {
                amin(close, dq[j].front() + aux + fenw.get(dq[j].front()));
            }
        }   
        if(close <= n) {
            ll val = cnt;
            val += max(0, close - i);
            amin(ans, val);
        }
        if(!dq[c].empty()) {
            close = dq[c].front() + aux + fenw.get(dq[c].front());
            cnt += max(0, close - i);
            fenw.update(dq[c].front(),-1);
            dq[c].pop_front();
            aux += 1;
        }
        else {
            break;
        }
        // debug(i);
    }
    if(ans >= n * 1ll * n) {
        ans = -1;
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