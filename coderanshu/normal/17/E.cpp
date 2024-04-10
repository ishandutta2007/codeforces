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

const int SZ = 2e6+10;
// SZ = length of string + 10
struct EERTREE {

    int len[SZ], link[SZ], dep[SZ];
    char s[SZ];

    int last, sz, n;

    vector<pair<char,int>> to[SZ];

    // Extra variables here to be stored in states of tree

    EERTREE() {
        len[1] = -1, link[1] = 0;
        len[0] = 0, link[0] = 1;
        dep[0] = dep[1] = 0;
        last = 0;
        sz = 2;
        s[0] = -1;
        // to make sure that link works correctly if on adding ith char, i-1 th prefix is palindrome
        n = 1;
    }
    void clear() {
        for(int i=0;i<SZ;++i) {
            to[i].clear();
        }
        len[1] = -1, link[1] = 0;
        len[0] = 0, link[0] = 1;
        dep[0] = dep[1] = 0;
        last = 0;
        sz = 2;
        s[0] = -1;
        // to make sure that link works correctly if on adding ith char, i-1 th prefix is palindrome
        n = 1;
    }
    int get(int i,char c) {
        int id = 0;
        for(auto &[i,j]:to[i]) {
            if(i == c) {
                return id;
            }
            ++id;
        }
        return -1;
    }

    void addChar(char c) {
        s[n++] = c;
        while(s[n - 1] != s[n - 2 - len[last]]) {
            last = link[last];
        }
        if(get(last, c) == -1) {
            int tmp = link[last];
            while(s[n - 1] != s[n - 2 - len[tmp]]) {
                tmp = link[tmp];
            }
            // must have been present
            int id = get(tmp, c);
            if(id == -1) {
                link[sz] = 0;
            }
            else {
                link[sz] = to[tmp][id].S;
            }
            len[sz] = len[last] + 2;
            to[last].push_back({c, sz++});
        }   
        last = to[last][get(last,c)].S;
        dep[last] = dep[link[last]] + 1;
        // do cnt[last]++ if need to count occurences
    }
}pt;

const int mod = 51123987;

int _runtimeTerror_()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> fx(n+1, 0);
    for(int i=1;i<=n;++i) {
        pt.addChar(s[i - 1]);
        fx[i] = pt.dep[pt.last];
        fx[i] += fx[i - 1];
        fx[i] %= mod;
    }
    pt.clear();
    ll ans = 0;
    for(int i=n;i>=1;--i) {
        pt.addChar(s[i - 1]);
        ans += fx[i - 1] * 1ll * pt.dep[pt.last] % mod;
        ans %= mod;
    }
    cout << ((fx[n] * 1ll * (fx[n] - 1) / 2 % mod) - ans + mod) % mod << "\n";
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