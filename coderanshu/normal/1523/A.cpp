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
    int n,m;
    cin>>n>>m;
    amin(m,n+2);
    string s;
    cin>>s;
    for(int i=0;i<m;++i)
    {
        string t = s;
        for(int j=0;j<n;++j)
        {
            if(t[j] == '1')
                continue;
            if(t[j] == '0')
            {
                // debug(i,j);
                int cnt = 0;
                if(j-1>=0 && t[j-1] == '1')
                    ++cnt;
                if(j+1<n && t[j+1] == '1')
                    ++cnt;
                if(cnt == 1)
                    s[j] = '1';
            }
        }
    }
    cout<<s<<"\n";
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
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}