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

int _runtimeTerror_()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> p(n+1),r(n+1,1),a(n+1,0);
    vector<vector<pii>> best(1<<18,vector<pii>(2,make_pair(-1,-1)));
    vector<pii> good(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        p[i] = i,r[i] = 1;
        ans -= a[i];
    }
    function<int(int)> parent = [&](int i)
    {
        return p[i] == i?i:parent(p[i]);
    };
    function<bool(int,int)> merge = [&](int x,int y)
    {
        x = parent(x),y = parent(y);
        if(x == y)
            return false;
        if(r[x]>r[y])
            swap(x,y);
        r[y] += r[x];
        p[x] = y;
        return true;
    };
    const int N = (1<<18)-1;
    // cost of a[0] -> 0
    int cmp = n+1;
    while(cmp > 1)
    {
        for(int i=0;i<(1<<18);++i)
            best[i][0] = best[i][1] = {-1,-1};
        for(int i=0;i<=n;++i)
        {
            good[i] = {-1,-1};
            pii u = {a[i],parent(i)};
            if(best[a[i]][0] < u)
            {
                if(best[a[i]][0].S != u.S)
                    best[a[i]][1] = best[a[i]][0];
                best[a[i]][0] = u;
            }
            else if(best[a[i]][1] < u && best[a[i]][0].S != u.S)
                best[a[i]][1] = u;
        }
        for(int i=0;i<18;++i)
        {
            for(int mask=0;mask<(1<<18);++mask)
            {
                if(mask & (1<<i))
                {
                    if(best[mask][1] > best[mask^(1<<i)][0])
                        continue;
                    if(best[mask][0] < best[mask^(1<<i)][0])
                    {
                        pii tmp = best[mask][0];
                        best[mask][0] = best[mask^(1<<i)][0];
                        if(tmp > best[mask^(1<<i)][1] && tmp.S != best[mask][0].S)
                            best[mask][1] = tmp;
                        else if(best[mask][1] > best[mask^(1<<i)][1] && best[mask][1].S != best[mask][0].S);
                        else
                            best[mask][1] = best[mask^(1<<i)][1];
                    }
                    else
                    {
                        if(best[mask^(1<<i)][0] > best[mask][1] && best[mask][0].S != best[mask^(1<<i)][0].S)
                            best[mask][1] = best[mask^(1<<i)][0];
                        else if(best[mask^(1<<i)][1] > best[mask][1] && best[mask^(1<<i)][1].S != best[mask][0].S)
                            best[mask][1] = best[mask^(1<<i)][1];
                    }

                }
            }
        }
        for(int i=0;i<=n;++i)
        {
            int root = parent(i);
            int cur = a[i] ^ N;
            if(best[cur][0].F != -1 && best[cur][0].S != root)
                amax(good[root],make_pair(best[cur][0].F+a[i],best[cur][0].S));
            else if(best[cur][1].F != -1 && best[cur][1].S != root)
                amax(good[root],make_pair(best[cur][1].F+a[i],best[cur][1].S));
        }
        for(int i=0;i<=n;++i)
        {
            if(parent(i) != i)
                continue;
            if(merge(i,good[i].second))
            {
                ans += good[i].first;
                --cmp;
            }
        }
    }
    cout << ans << "\n";
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