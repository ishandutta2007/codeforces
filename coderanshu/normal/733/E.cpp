#include<bits/stdc++.h>
using namespace std ;

#define int             int64_t
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
    string s;
    cin>>s;
    vector<ll> d_cnt(n+1,0),d_sum(n+1),u_cnt(n+1),u_sum(n+1,0);
    for(int i=1;i<=n;++i)
    {
        u_cnt[i] = u_cnt[i-1];
        u_sum[i] = u_sum[i-1];
        d_cnt[i] = d_cnt[i-1];
        d_sum[i] = d_sum[i-1];
        if(s[i-1] == 'D')
        {
            d_cnt[i] += 1;
            d_sum[i] += i;
        }
        else
        {
            u_cnt[i] += 1;
            u_sum[i] += i;
        }
    }
    for(int i=1;i<=n;++i)
    {
        int64_t ans = 0;
        if(s[i-1] == 'U')
        {
            int r_d = d_cnt[n] - d_cnt[i];
            int l_u = u_cnt[i-1];
            if(r_d > l_u)
            {
                auto it = lower_bound(all(d_cnt),d_cnt[i]+l_u+1)-d_cnt.begin();
                ans += (d_sum[it] - d_sum[i] - (i * (l_u+1))) * 2;
                ans -= (u_sum[i-1]) * 2;
                ans += l_u * i * 2;
                ans += i;
            }
            else
            {
                ans += (d_sum[n] - d_sum[i] - (d_cnt[n] - d_cnt[i]) * i) * 2;
                ans += (n - i + 1);
                auto it = lower_bound(all(u_cnt),u_cnt[i-1]-r_d+1)-u_cnt.begin();
                ans -= (u_sum[i-1] - u_sum[it-1]) * 2;
                ans += (r_d * i) * 2;
            }
            cout << ans << " ";
        }
        else
        {
            int r_d = d_cnt[n] - d_cnt[i];
            int l_u = u_cnt[i-1];
            if(r_d >= l_u)
            {
                auto it = lower_bound(all(d_cnt),d_cnt[i]+l_u)-d_cnt.begin();
                ans += (d_sum[it] - d_sum[i] - (i * (l_u))) * 2;
                ans -= (u_sum[i-1]) * 2;
                ans += l_u * i * 2;
                ans += i;
            }
            else
            {
                ans += (d_sum[n] - d_sum[i] - (d_cnt[n] - d_cnt[i]) * i) * 2;
                ans += (n - i + 1);
                auto it = lower_bound(all(u_cnt),u_cnt[i-1]-r_d)-u_cnt.begin();
                ans -= (u_sum[i-1] - u_sum[it-1]) * 2;
                ans += ((r_d + 1) * i) * 2;
            }
            cout << ans << " ";
        }
    }
    return 0;
}

int32_t main()
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