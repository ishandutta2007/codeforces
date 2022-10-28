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
    vector<pii> a(m);
    vector<int> have(m);
    for(int i=0;i<m;++i)
        cin>>a[i].F>>a[i].S;
    iota(all(have),0);
    sort(all(have),[&](int l,int r){
        auto y = a[l],x = a[r];
        return y.S - y.F > x.S - x.F;
    });
    debug(have);
    int cur = 0;
    vector<int> ans(n+1,0);

    vector<set<pii>> seg(4*m+40);
    function<void(int,int,int,int)> add = [&](int v,int st,int en,int i)
    {
        auto it = seg[v].lower_bound(make_pair(a[i].F,-1));
        if(it != seg[v].end() && it->S <= a[i].S) {

        }
        else
        {
            while(true)
            {
                auto it = seg[v].lower_bound(make_pair(a[i].F+1,-1));
                if(it != seg[v].begin())
                {
                    --it;
                    if(it->S >= a[i].S)
                    {
                        seg[v].erase(it);
                    }
                    else
                        break;
                }
                else
                    break;
            }
            seg[v].insert(a[i]);
        }
        if(st == en)
            return ;
        int mid = (st + en)/2;
        if(i <= mid)
            add(v<<1,st,mid,i);
        else
            add(v<<1|1,mid+1,en,i);
    };
    function<int(int,int,int,int,int)> get = [&](int v,int st,int en,int l,int r)
    {
        auto it = seg[v].lower_bound(make_pair(l,-1));
        debug(*it);
        if(it == seg[v].end() || it->S > r)
            return -1;
        if(st == en)
            return st;
        int mid = (st + en)/2;
        auto u = get(v<<1,st,mid,l,r);
        if(u != -1)
            return u;
        return get(v<<1|1,mid+1,en,l,r);
    };
    function<void(int,int,int&)> dfs = [&](int l,int r,int &ans)
    {
        if(l > r)
            return ;
        int u = get(1,0,m-1,l,r);
        debug(l,r,u);
        if(u == -1)
            return ;
        ans += a[u].S - a[u].F + 1;
        dfs(l,a[u].F-1,ans);
        dfs(a[u].S + 1,r,ans);
    };
    for(int i=n;i>=1;--i)
    {
        while(cur < m && a[have[cur]].S - a[have[cur]].F + 1 >= i) {
            add(1,0,m-1,have[cur]);
            // debug(have[cur]);
            ++cur;
            // debug(i,cur);
        }
        debug(i,"Here");

        dfs(1,n,ans[i]);
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<"\n";
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