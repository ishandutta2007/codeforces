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

const int N = 5005;

ll dp[N];

vector<int> zFunction(string &s)
{
    int n=sz(s),l,r,i;
    vector<int> z(n);
    z[0]=n;
    l=r=0;
    for(i=1;i<n;++i)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i])
            ++z[i];
        if(i+z[i]-1>r)
        {
            l=i;r=i+z[i]-1;
        }
    }
    return z;
}

int _runtimeTerror_()
{
    int n;
    ll a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    string t = s;
    t += "#";
    vector<int> v(n,0);
    for(int i=0;i<n;++i)
    {
        vector<int> z = zFunction(t);
        for(int j=n-i+1;j<n+1;++j)
            amax(v[i],z[j]);
        t += t[0];
        t.erase(t.begin());
    }
    dp[0] = a;
    for(int i=1;i<n;++i)
    {
        dp[i] = dp[i-1] + a;
        for(int j=0;j<=i;++j)
        {
            if(v[j]>=i-j+1)
                amin(dp[i],dp[j-1]+b);
        }
    }
    cout<<dp[n-1]<<"\n";
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