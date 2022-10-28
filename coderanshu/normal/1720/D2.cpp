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

const int lo = -1e9;
map<int, int> nxt = {{0, 1}, {1, 3}, {2, 0}, {3, 2}};

struct TRIE {
    vector<array<int, 2>> next;
    vector<long long> cnt;
    vector<array<int, 4>> node;
    static const int B = 31;
    int root, cur;

    TRIE() {
        next.push_back({-1, -1});
        cnt.push_back(0);
        node.push_back({lo, lo, lo, lo});
        root = 0;
        cur = 1;
    }
    void insert(int x, int f, int g, int dp) {
        int tmp = root;
        int val = 0;
        for(int i=B;i>=1;--i) {
            val += x & (1 << i);
            int t = (x >> i) & 1;
            int mask = ((f >> (i - 1)) & 1) * 2 + ((g >> (i - 1)) & 1);
            if(next[tmp][t] == -1) {
                next[tmp][t] = cur++;
                next.push_back({-1, -1});
                cnt.push_back(0);
                node.push_back({lo, lo, lo, lo});
            }
            tmp = next[tmp][t];
            amax(node[tmp][mask], dp);
        }
    }
    int query(int x, int f, int g) {
        int tmp = root;
        int val = 0;
        int ans = -1e9;
        for(int i=B;i>=1;--i) {
            val += x & (1 << i);
            int t = (x >> i) & 1;
            int mask = ((f >> (i - 1)) & 1) * 2 + ((g >> (i - 1)) & 1);
            if(next[tmp][t] == -1) {
                break;
            }
            tmp = next[tmp][t];
            amax(ans, node[tmp][nxt[mask]]);
        }
        return ans;
    }
    void clear() {
        next.clear();
        cnt.clear();
        root = 0;
        next.push_back({-1, -1});
        cnt.push_back(0);
        cur = 1;
    }
};
// change msb accordingly


int _runtimeTerror_()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    vector<int> dp(n, 1);
    TRIE trie;
    for(int i=0;i<n;++i) {
        int cur = a[i] ^ i;
        amax(dp[i], trie.query(cur, a[i], i) + 1);
        trie.insert(cur, a[i], i, dp[i]);
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