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

int _runtimeTerror_()
{
    ll n,m,x,y,k;
    cin>>n>>m>>x>>k>>y;
    vector<ll> a(n+2,0),b(m+2,0);
    for(int i=0;i<n;++i)
        cin>>a[i+1];
    for(int j=0;j<m;++j)
        cin>>b[j+1];
    int j=0;
    ll ans=0;
    for(int i=0;i<m+1;)
    {
        ++i,++j;
        vector<ll> v;
        ll cnt=0;
        ll val=max(b[i],b[i-1]);
        int ss=0;
        while(j<n+2 && a[j]!=b[i])
        {
            if(a[j]>val)
                ++ss;
            ++cnt;
            ++j;
        }
        if(j==n+2 || (ss>0 && cnt<k))
        {
            cout<<"-1\n";return 0;
        }
        ans+=(cnt%k)*y;
        if(ss==0)
            ans+=(cnt/k)*min(x,k*y);
        else
        {
            ans+=x;
            cnt-=k;
            ans+=(cnt/k)*min(x,k*y);
        }
    }
    assert(ans>=0);
    cout<<ans;
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