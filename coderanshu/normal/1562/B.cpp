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
    string s;
    cin >> s;
    for(int i=0;i<n;++i)
    {
        int num = s[i] - '0';
        for(int j=2;j<=num-1;++j)
        {
            if(num % j == 0)
            {
                cout << 1 << "\n" << num << "\n";
                return 0;
            }
        }
        if(num == 1)
        {
            cout << "1\n1\n";
            return 0;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int num = (s[i] - '0') * 10 + s[j] - '0';
            for(int j=2;j<=num-1;++j)
            {
                if(num % j == 0)
                {
                    cout << 2 << "\n" << num << "\n";
                    return 0;
                }
            }
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
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}