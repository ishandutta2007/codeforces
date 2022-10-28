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
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 200005;

set<pii> good[26];

set<pii> ed[26];
// set<pii> evg;
// vertex c * 100 + d

set<int> f;
int cnt[N];

map<pii,int> mp;

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    bool odd = false,four = false;

    auto add = [&](int u,int v,int id)
    {
        if(ed[id].count({v,u}))
        {
            good[id].insert({min(u,v),max(u,v)});
            odd = true;
        }

        for(int i=0;i<26;++i)
        {
            if(ed[i].count({v,u}))
            {
                ++cnt[u];
                ++cnt[v];
                if(cnt[u] == 1)
                    f.insert(u);
                if(cnt[v] == 1)
                    f.insert(v);
                break;
            }
        }
        four = !f.empty();
        ed[id].insert({u,v});
        mp[{u,v}] = id;
    };
    auto del = [&](int u,int v,int id)
    {
        if(ed[id].count({v,u}))
        {
            good[id].erase({min(u,v),max(u,v)});
            odd = false;
            for(int i=0;i<26;++i)
                if(!good[i].empty())
                    odd = true;
        }
        for(int i=0;i<26;++i)
        {
            if(ed[i].count({v,u}))
            {
                --cnt[u];
                --cnt[v];
                if(cnt[u] == 0)
                    f.erase(u);
                if(cnt[v] == 0)
                    f.erase(v);
            }
        }
        mp.erase({u,v});
        ed[id].erase({u,v});
        four = !f.empty();
    };
    for(int i=1;i<=m;++i)
    {
        char c,d;
        cin>>c;
        int u,v;
        if(c == '+')
        {
            cin>>u>>v>>d;
            add(u,v,d-'a');
        }
        else if(c == '-')
        {
            cin>>u>>v;
            del(u,v,mp[{u,v}]);
        }
        else if(c == '?')
        {
            int u;
            cin>>u;
            --u;
            if(u&1)
            {
                if(odd)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else 
            {
                if(odd || four)
                {
                    cout<<"YES\n";
                }
                else
                    cout<<"NO\n";
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
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}