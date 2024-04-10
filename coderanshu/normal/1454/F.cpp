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

const int N = 200005,LOGN = 20;

int dp[N][LOGN],logn[N];

int _runtimeTerror_()
{
    ll n;
    cin>>n;
    vector<ll> v(n+1);
    map<int,int> mp;
    map<int,vector<int>> m;
    int l = n+1,r = -1;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i];
        ++mp[-v[i]];
        m[v[i]].pb(i);
    }
    for(int j=0;j<LOGN;++j)
    {
        for(int i=1;i<=n;++i)
        {
            if(i+(1<<j)>n+1)
                continue;
            if(j==0)
                dp[i][j] = v[i];
            else
                dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    auto get = [&](int l,int r)
    {
        int x = logn[r-l+1];
        return min(dp[l][x],dp[r-(1<<x)+1][x]);
    };
    auto mxc = mp.begin()->S;
    int mx = -mp.begin()->F;
    auto go = [&](int l,int r)
    {
        cout<<"YES\n";
        cout<<l-1<<" "<<r-l+1<<" "<<n-r<<"\n";
    };
    if(mxc>=3)
    {
        go(m[mx][1],m[mx][1]);
        return 0;
    }
    else
    {
        l = m[mx][0],r = m[mx].back();
    }
    for(auto j:mp)
    {
        int e = -j.F;
        if(e==mx)
            continue;
        int u = get(l,r);
        if(j.S<3)
        {
            amin(l,m[e][0]);
            amax(r,m[e].back());
            continue;
        }
        int less = 0,grt = 0,lft = -1,rgt = n+2;
        for(auto &k:m[e])
        {
            if(k<=l)
                ++less,lft = k;
            else if(k>=r)
                ++grt,amin(rgt,k);
        }
        if(less>=1 && grt>=1)
        {
            if(u==e)
            {
                go(l,r);
                return 0;
            }
            if(u>e)
            {
                bool le = false,re = false;
                if(get(lft,r)==e)
                    le = true;
                if(get(l,rgt)==e)
                    re = true;
                if(le && less>=2)
                {
                    go(lft,r);
                    return 0;
                }
                if(re && grt>=2)
                {
                    go(l,rgt);
                    return 0;
                }
            }
        }
        amin(l,m[e][0]);
        amax(r,m[e].back());
    }
    cout<<"NO\n";
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
    for(int i=2;i<N;++i)
        logn[i] = 1+logn[i/2];
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}