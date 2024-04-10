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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=0;i<n;++i)
    {
        if(s[i] == s[(i+1)%n])
        {
            vector<vector<int>> chains;
            chains.push_back({});

            vector<int> bad(n,0);
            for(int j=0;j<n;++j)
            {
                int id = (j + i) % n;
                if(s[(id - 1 + n) %n] != s[id] && s[id] != s[(id + 1) % n])
                    bad[id] = 1;
                if(bad[id] && bad[(id - 1 + n) % n])
                    chains.back().push_back(id);
                else if(bad[id])
                    chains.push_back({id});
            }
            auto flip = [&](char &c)
            {
                c = c ^ 'B' ^ 'W';
            };
            for(auto &v:chains)
            {
                int n = sz(v);
                for(int i=0;i<(n + 1)/2;++i)
                {
                    if((i < k && i % 2 == 0) || (i >= k && k % 2 == 1))
                    {
                        flip(s[v[i]]),flip(s[v[n-1-i]]);
                        if(i == n - 1 - i)
                            flip(s[v[i]]);
                    }
                }
            }

            cout << s << "\n";
            return 0;
        }
    }
    k &= 1;
    for(int i=0;i<n;++i)
    {
        if(k)
            s[i] = s[i] ^ 'B' ^ 'W';
        cout << s[i];
    }
    cout << "\n";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}