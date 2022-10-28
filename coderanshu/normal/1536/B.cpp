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

vector<string> A;

int _runtimeTerror_()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    for(auto ans:A)
    {
        bool f = false;
        string t = ans + "#" + s;
        auto z = zFunction(t);
        for(int i=ans.size()+1;i<sz(z);++i)
        {
            if(z[i] == sz(ans))
                f = true;
        }
        if(!f)
        {
            cout<<ans<<"\n";return 0;
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
    int TESTS=1;
    cin>>TESTS;
    function<void(string)> dfs = [&](string s)
    {
        if(sz(s) >= 4)
            return ;
        if(!s.empty())
            A.push_back(s);
        for(char c = 'a';c <= 'z';++c)
        {
            s += c;
            dfs(s);
            s.pop_back();
        }
    };
    dfs("");
    sort(all(A),[&](string x,string y){
        if(sz(x) != sz(y))
            return sz(x) < sz(y);
        return x < y;
    });
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}