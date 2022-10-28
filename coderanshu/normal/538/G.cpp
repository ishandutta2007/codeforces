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
    int n,LL;
    cin>>n>>LL;
    vector<ll> t(n+1),x(n+1),y(n+1);
    for(int i=1;i<=n;++i)
        cin>>t[i]>>x[i]>>y[i];

    auto solve = [&](vector<ll> &x,vector<ll> &t,vector<ll> &ans)
    {
        for(int i=1;i<=n;++i)
        {
            if((x[i] + t[i]) % 2 != 0)
                return false;
        }
        struct node {
            ll x,coef,var;
        };
        vector<node> a;
        for(int i=1;i<=n;++i)
        {
            ll u = t[i] / LL;
            a.push_back({x[i],u,t[i] % LL});
        }
        a.push_back({0,0,0});
        sort(all(a),[&](node &l,node &r) {
            return l.var < r.var;
        });
        ld intl = -LL,intr = LL;
        for(int i=0;i<sz(a) - 1;++i)
        {
            ld left = -(a[i+1].var - a[i].var);
            ld right = -left;
            ll tmp = a[i+1].x - a[i].x;
            left -= tmp,right -= tmp;
            if(a[i+1].coef > a[i].coef)
            {
                swap(left,right);
                left *= -1,right *= -1;
            }
            ll cur = abs(a[i+1].coef - a[i].coef);
            if(cur == 0 && right >= left)
                continue;
            if(cur == 0 && left > right)
                return false;
            assert(right >= left);
            assert(cur != 0);
            left /= cur,right /= cur;
            amax(intl,left),amin(intr,right);
        }        
        ld left = a.back().var - LL,right = -left;
        left += a.back().x,right += a.back().x;
        left /= 1+a.back().coef,right /= 1+a.back().coef;
        amax(intl,left),amin(intr,right);
        ll l = ceil(intl-1e-12),r = floor(intr+1e-12);
        ll tt = -INF;
        for(;l<=r;++l)
        {
            if(abs(l % 2) == LL % 2)
            {
                tt = l;
                break;
            }
        }
        if(tt == -INF)
            return false;
        vector<ll> sum(LL+1,-INF);
        sum[LL] = tt;
        sum[0] = 0;
        for(int i=0;i<sz(a);++i)
        {
            sum[a[i].var] = a[i].x - a[i].coef * tt;
        }
        ans.assign(LL+1,0);
        ll pr = 0;
        for(int i=1;i<=LL;++i)
        {
            if(sum[i] == -INF)
                continue;
            int len = i - pr;
            int delta = sum[i] - sum[pr];
            int ones = 0,mones = 0;
            assert(abs(delta) % 2 == len % 2);
            ones = (delta + len)/2;
            mones = len - ones;
            assert(ones >= 0 && mones >= 0);
            while(ones--)
                ans[++pr] = 1;
            while(mones--)
                ans[++pr] = -1;
            pr = i;
        }
        return true;
    };
    vector<ll> X(n+1);
    for(int i=1;i<=n;++i)
        X[i] = (x[i] + y[i]);
    vector<ll> L,R;
    if(!solve(X,t,L))
    {
        cout<<"NO\n";return 0;
    }
    for(int i=1;i<=n;++i)
        X[i] = (x[i] - y[i]);
    if(!solve(X,t,R))
    {
        cout<<"NO\n";return 0;
    }
    // debug(L);
    // debug(R);
    string ans;
    for(int i=1;i<=LL;++i)
    {
        if(L[i] == 1 && R[i] == 1)
            ans += "R";
        else if(L[i] == 1 && R[i] == -1)
            ans += "U";
        else if(L[i] == -1 && R[i] == -1)
            ans += "L";
        else
            ans += "D";
    }
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