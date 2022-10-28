#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             1500000000000000000
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

const int N = 55;

ll fac[N];
ll dp[N];

int _runtimeTerror_()
{
    int n;
    ll k;
    cin>>n>>k;
    vector<int> p(n+1),r(n+1),val(n+1);
    for(int i=1;i<=n;++i)
        p[i] = i,r[i] = 0,val[i] = i;
    function<int(int)> parent = [&](int i)
    {
        return p[i] == i?i:parent(p[i]);
    };
    auto merge = [&](int x,int y)
    {
        x = parent(x),y = parent(y);
        if(x == y)
            return ;
        if(r[x] > r[y])
        {
            r[x] += r[y];
            p[y] = x;
        }
        else
            r[y] += r[x],p[x] = y,val[y] = val[x];
    };
    if(dp[n] < k)
    {
        cout<<"-1\n";return 0;
    }
    auto get = [&](int x)
    {
        if(x <= 1)
            return 1ll;
        return fac[x-1];
    };
    vector<int> ans(n+1,-1);
    for(int i=1;i<=n;++i)
    {
        int cur = i;
        if(dp[n-i] < k)
        {
            k -= dp[n-i];
            for(int j=i+1;j<=n;++j)
            {
                ll f = fac[j-i+1-2];
                if(INF / dp[n-j] < f || dp[n-j] * f >= k)
                {
                    cur = j;
                    break;
                }
                else
                    k -= dp[n-j] * f;
            }
        }
        ans[i] = cur;
        // from i .... cur is a segment or sub cycle
        int cmp = cur - i + 1 - 1;
        merge(i,cur);
        for(int j=i+1;j<cur;++j)
        {
            vector<int> t;
            for(int l=i;l<=cur;++l)
                t.pb(val[parent(l)]);
            sort(all(t));
            t.resize(unique(all(t))-t.begin());
            for(int l:t)
            {
                if(parent(l) != parent(j))
                {
                    ll u = get(cmp-1);
                    if(INF / u < dp[n-cur] || u * dp[n-cur] >= k)
                    {
                        ans[j] = val[parent(l)];
                        merge(j,l);
                        --cmp;
                        break;
                    }
                    else
                        k -= u * dp[n-cur];
                }
            }
        }
        set<int> s;
        for(int j=i;j<cur;++j)
            s.insert(ans[j]);
        for(int j=i;j<=cur;++j)
            if(!s.count(j))
                ans[cur] = j;
        i = cur;
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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
    fac[0] = 1;
    for(int i=1;i<=50;++i)
    {
        if(i > 20)
            fac[i] = INF;
        else
            fac[i] = fac[i-1] * i;
    }
    dp[0] = 1;
    for(int i=1;i<=50;++i)
    {
        if(i > 22)
            dp[i] = INF;
        else
        {
            for(int j=1;j<i;++j)
            {
                if(INF / dp[j] >= fac[i-j+1-2])
                    dp[i] += dp[j-1] * fac[i-j+1-2];
                else
                    dp[i] = INF;
                amin(dp[i],INF);
            }
            dp[i] += dp[i-1];
            amin(dp[i],INF);
        }
    }
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}