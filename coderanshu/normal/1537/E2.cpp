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

vector<int> zFunction(string &s)
{
    int n=sz(s),l,r,i;
    vector<int> z(n);
    z[0]=n;
    l=r=0;
    for(i=1;i<n;++i)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i])
            ++z[i];
        if(i+z[i]-1>r)
        {
            l=i;r=i+z[i]-1;
        }
    }
    return z;
}


int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> z = zFunction(s);
    string ans;
    ans += s[0];
    for(int i=1;i<n;++i)
    {
        int u = z[i]+i;
        if(z[i] >= sz(ans))
        {
            ans += s[i];
            continue;
        }
        if(s[u] < ans[z[i]])
        {
            ans += s[i];
            continue;
        }
        break;
    }
    debug(ans);
    auto u = ans;
    sort(all(u));
    if(u != ans)
    {
        while(ans.back() == ans[0])
            ans.pop_back();
    }
    while(sz(ans) < k)
        ans += ans;
    while(sz(ans) > k)
        ans.pop_back();
    cout<<ans<<"\n";
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