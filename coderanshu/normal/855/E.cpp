#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
ll dp[12][65][1<<11];

int _runtimeTerror_()
{
    for(int i=1;i<=10;++i)
        dp[i][0][0]=1;
    for(int i=1;i<=10;++i)
    {
        for(int j=1;j<=60;++j)
        {
            for(int mask=0;mask<(1<<i);++mask)
            {
                for(int l=0;l<i;++l)
                {
                    dp[i][j][mask]+=dp[i][j-1][mask^(1<<l)];
                }
            }
        }
    }
    int q;
    cin>>q;
    int b;
    auto f=[&](ll r)
    {
        ll ans=0;
        if(r==0)
            return ans;
        vector<int> v;
        int mask=0;
        while(r)
        {
            v.pb(r%b);
            mask^=(1<<(r%b));
            r/=b;
        }
        ans+=mask==0;
        //cout<<"ans"<<ans<<'\n';
        reverse(all(v));
        if(v.empty())
            return ans;
        int nn=sz(v);
        for(int i=1;i<nn;++i)
            for(int j=1;j<b;++j)
                ans+=dp[b][nn-i-1][1<<j];
        for(int i=1;i<v[0];++i)
            ans+=dp[b][nn-1][1<<i];
        //cout<<"ans "<<ans<<'\n';
        mask=1<<(v[0]);
        for(int i=1;i<nn;++i)
        {
            for(int j=0;j<v[i];++j)
            {
                mask^=(1<<j);
                ans+=dp[b][nn-i-1][mask];
                mask^=(1<<j);
            }
            mask^=(1<<v[i]);
        }
        return ans;
    };
    while(q--)
    {
        ll l,r;
        cin>>b>>l>>r;
        cout<<f(r)-f(l-1)<<'\n';
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