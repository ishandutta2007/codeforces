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

struct TRIE {
    vector<array<int, 2>> next;
    vector<long long> cnt;
    static const int B = 16;
    int root, cur;

    TRIE() {
        next.push_back({-1, -1});
        cnt.push_back(0);
        root = 0;
        cur = 1;
    }
    void insert(long long x) {
        int tmp = root;
        ++cnt[tmp];
        for(int i=B;i>=0;--i) {
            int t = (x >> i) & 1;
            if(next[tmp][t] == -1) {
                next[tmp][t] = cur++;
                next.push_back({-1, -1});
                cnt.push_back(0);
            }
            tmp = next[tmp][t];
            ++cnt[tmp];
        }
    }
    void erase(long long x) {
        int tmp = root;
        --cnt[tmp];
        for(int i=B;i>=0;--i) {
            tmp = next[tmp][(x >> i) & 1];
            --cnt[tmp];
        }
    }
    long long q_max(long long x) {
        int tmp = root;
        long long ans = 0;
        if(cnt[tmp] == 0) {
            return -1;
        }
        for(int i=B;i>=0;--i) {
            int t = (x >> i) & 1;
            if(next[tmp][1 - t] != -1 && cnt[next[tmp][1 - t]] > 0) {
                tmp = next[tmp][1 - t];
                ans += 1LL << i;
            }
            else {
                tmp = next[tmp][t];
            }
        }
        return ans;
    }
    long long q_min(long long x) {
        int tmp = root;
        long long ans = 0;
        if(cnt[tmp] == 0) {
            return -1;
        }
        for(int i=B;i>=0;--i) {
            int t = (x >> i) & 1;
            if(next[tmp][t] != -1 && cnt[next[tmp][t]] > 0) {
                tmp = next[tmp][t];
            }
            else {
                tmp = next[tmp][1 - t];
                ans += 1LL << i;
            }
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
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    TRIE trie;
    vector<int> candid, a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        trie.insert(a[i]);
    }
    for(int i=l;i<=r;++i) {
        candid.push_back(a[0] ^ i);
    }
    for(auto &i:candid) {
        int f = trie.q_min(i), g = trie.q_max(i);
        if(f >= l and f <= r and g >= l and g <= r) {
            cout << i << "\n";
            return 0;
        }
    }
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