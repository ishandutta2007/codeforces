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
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n,Q;
    cin >> n >> Q;
    string s;
    cin >> s;
    vector<vector<int>> pos(n+1,vector<int>(2,0)), neg = pos;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<2;++j)
            pos[i][j] = pos[i-1][j], neg[i][j] = neg[i-1][j];
        pos[i][i%2] += s[i-1] == '+';
        neg[i][i%2] += s[i-1] == '-';
    }
    auto get = [&](int l,int r) {
        int f = abs((pos[r][0] - pos[l-1][0]) - (pos[r][1] - pos[l-1][1]));
        int g = abs((neg[r][0] - neg[l-1][0]) - (neg[r][1] - neg[l-1][1]));
        if(f > g)
            swap(f,g);
        assert(abs(f-g) <= 1);
        f += g;
        if(f == 0)
            return 0;
        if(f % 2 == 1)
            return 1;
        return 2;
    };
    for(int i=0;i<Q;++i)
    {
        int l,r;
        cin >> l >> r;
        cout << get(l,r) << "\n";
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
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}