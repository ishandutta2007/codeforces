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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;++i)
        cin >> a[i];
    if(a[1] == 1)
    {
        cout << n + 1 << " ";
        for(int i=1;i<=n;++i)
            cout << i << " ";
        cout << "\n";
        return 0;
    }
    if(a[n] == 0)
    {
        for(int i=1;i<=n+1;++i)
            cout << i << " ";
        cout << "\n";
        return 0;
    }
    // start from 1
    for(int i=1;i<=n-1;++i) 
    {
        if(a[i] == 0 && a[i+1] == 1)
        {
            for(int j=1;j<=i;++j)
                cout << j << " ";
            cout << n + 1 << " " << i + 1 << " ";
            for(int j=i+2;j<=n;++j)
                cout << j << " ";
            cout << "\n"; 
            return 0;
        }
    }
    cout << "-1\n";
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