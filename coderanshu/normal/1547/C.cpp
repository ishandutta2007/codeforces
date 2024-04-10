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
    int k,n,m;
    cin >> k >> n >> m;
    vector<int> ans,a(n),b(m);
    for(int i=0;i<n;++i)
        cin >> a[i];
    for(int i=0;i<m;++i)
        cin >> b[i];
    int l = 0,r = 0;
    while(l < n && r < m)
    {
        if(a[l] == 0)
            ++k,ans.push_back(0),++l;
        else if(b[r] == 0)
            ++k,ans.push_back(0),++r;
        else if(a[l] <= k)
            ans.push_back(a[l]),++l;
        else if(b[r] <= k)
            ans.push_back(b[r]),++r;
        else
        {
            cout << "-1\n";
            return 0;
        }
    }
    while(l < n)
    {
        if(a[l] == 0)
            ++k;
        else if(a[l] > k)
        {
            cout << "-1\n";
            return 0;
        }
        ans.push_back(a[l]);
        ++l;
    }
    while(r < m)
    {
        if(b[r] == 0)
            ++k;
        else if(b[r] > k)
        {
            cout << "-1\n";
            return 0;
        }
        ans.push_back(b[r]);
        ++r;
    }
    for(auto &j:ans)
        cout << j << " ";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}