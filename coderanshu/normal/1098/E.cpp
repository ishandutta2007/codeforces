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

const int N = 100005;

const int N2 = 50005;

int dp[N2][17];
int lg[N2];

ll f[N];
ll sum[N];
ll cnt[N];

long long GudBoi(long long a, long long b, long long c, long long n)
{
    long long val = 0;
    if(a < 0)
    {
        ll x = (abs(a)+c-1)/c;
        a += x * c;
        val -= x*(n+1)*n/2;
    }
    if(b < 0)
    {
        ll x = (abs(b)+c-1)/c;
        b += x * c;
        val -= x*(n+1);
    }
    if(!a) return val + (b / c) * (n + 1);
    
    if(a >= c or b >= c) return val + ( ( n * (n + 1) ) / 2) * (a / c) + (n + 1) * (b / c) + GudBoi(a % c, b % c, c, n);
    long long m = (a * n + b) / c;
    return val + m * n - GudBoi(c, c - b - 1, a, m - 1);
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    lg[1] = 0;
    for(int i=2;i<N2;++i)
        lg[i] = 1 + lg[i/2];
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        dp[i][0] = a[i];
    }
    for(int i=1;i<17;++i)
    {
        for(int j=1;j<=n;++j)
        {   
            if(j+(1<<i)>n+1)
                break;
            int u = (1<<(i-1));
            dp[j][i] = __gcd(dp[j][i-1],dp[j+u][i-1]);
        }
    }
    auto get = [&](int l,int r)
    {
        int x = 1<<(lg[r-l+1]);
        return __gcd(dp[l][lg[r-l+1]],dp[r-x+1][lg[r-l+1]]);
    };
    for(int i=1;i<=n;++i)
    {
        int cur = a[i];
        int l = i;
        while(true)
        {
            if(l>n)
                break;
            int lo = l,hi = n,ans = -1;
            int cur = get(i,l);
            while(lo<=hi)
            {
                int mid = (lo+hi)/2;
                if(get(i,mid) == cur)
                    ans = mid,lo = mid+1;
                else
                    hi = mid-1;
            }
            assert(ans != -1);
            f[cur] += ans - l + 1;
            l = ans + 1;
        }
    }
    for(int i=1;i<=100000;++i)
    {
        cnt[i] = cnt[i-1] + f[i];
        sum[i] = sum[i-1] + i * f[i];
    }
    auto solve = [&](ll up)
    {
        int r = 1;
        ll ans = 0;
        for(int i=1;i<=100000;++i)
        {
            if(f[i] == 0)
                continue;
            while(r <= 1e5 && sum[r] - sum[i-1] <= up)
                ++r;
            ans += (cnt[r-1]-cnt[i-1]) * (cnt[r-1]-cnt[i-1] + 1)/2;
            if(r > i)
                ans -= (cnt[r-1]-cnt[i]) * (cnt[r-1] - cnt[i] + 1)/2;
            if(i == r)
            {
                ll len = min(f[i],up/i);
                ans += f[i]*(f[i]+1)/2 - (f[i]-len)*(f[i]-len+1)/2;
                ++r;
            }
            while(r <= 1e5 && sum[r-1] - sum[i] < up)
            {
                if(f[r] == 0)
                {
                    ++r;
                    continue;
                }
                ll y = sum[r-1] - sum[i];
                ll bound = min(f[i],(up-y)/i);
                ll lower = up - y - r * (f[r]+1) + 1;
                lower = max((lower+i-1)/i,1ll);
                if(lower > 1)
                    ans += (lower-1)*f[r];
                if(lower <= bound)
                    ans += GudBoi(-i,up-y-lower*i,r,bound-lower);
                ++r;
            }
            --r;
        }
        return ans;
    };
    ll el = n*1ll*(n+1)/2;
    el = el*(el+1)/2;
    el = (el-1)/2+1;
    ll lo = 1,hi = 2e18,ans = -1;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(solve(mid) >= el)
            ans = mid,hi = mid-1;
        else
            lo = mid+1;
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