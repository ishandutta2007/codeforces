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
    int n;
    cin>>n;
    vector<pair<ll,string>> ans;
    map<string,pair<ll,string>> mp;


    auto haha = [&](string s)
    {
        if(sz(s) < 4)
            return 0ll;
        ll ans = 0;
        for(int i=0;i<=sz(s)-4;++i)
            ans += s.substr(i,4) == "haha";
        return ans;
    };
    auto get = [&](string t)
    {
        vector<string> ans;
        string tmp;
        for(int i=0;i<sz(t);++i)
        {
            if(t[i] >= 'a' && t[i] <= 'z')
            {
                tmp += t[i];
            }
            else
            {
                if(tmp.empty())
                    continue;
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        if(!tmp.empty())
            ans.push_back(tmp);
        return ans;
    };

    auto process = [&](string s)
    {
        if(sz(s) <= 3)
            return s;
        string ans;
        ans += s.substr(0,3);
        ans += "#";
        ans += s.substr(sz(s)-3,3);
        return ans;
    };
    string t;
    getline(cin,t);
    for(int i=0;i<n;++i)
    {
        string t;
        getline(cin,t);
        auto u = get(t);
        // debug(t);
        // debug(u);
        if(sz(u) == 2)
        {
            mp[u[0]] = {haha(u[1]),process(u[1])};
            ans.push_back({haha(u[1]),u[1]});
            continue;
        }
        // continue;
        auto L = mp[u[1]];
        auto R = mp[u[2]];
        ll cnt = L.F + R.F;
        string s = L.S + R.S;
        cnt += haha(s);
        s = process(s);
        mp[u[0]] = {cnt,s};
        // debug(cnt,s);
        ans.push_back({cnt,s});
    }
    cout<<ans.back().F<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
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