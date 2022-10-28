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

const int N = 2000002;
bitset<N> vis;

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ans;
    int y = k;
    vector<int> sum(n);
    sum[0] = s[0]=='1';
    for(int i=1;i<n;++i)
        sum[i] = sum[i-1] + s[i]-'0';
    if(k>20)
    {
        for(int i=0;i<k-20;++i)
            ans += "0";
        k = 20;
    }
    const int mask = (1<<k)-1;
    vector<int> msk;
    for(int i=max(y-20,0);i<n-k+1;++i)
    {
        int ff = (i-1>=0)?sum[i-1]:0;
        ff -= (i-(y-20)-1>=0)?sum[i-1-y+20]:0;
        if(ff < y-20 && y>20)
            continue;
        int u = 0;
        int cur = k-1;
        for(int j=i;j<i+k;++j)
        {
            if(s[j]=='1')
                u += (1<<cur);
            --cur;
        }
        u ^= mask;
        msk.pb(u);
        vis[u] = 1;
    }
    int x = -1;
    for(int i=0;i<(1<<k);++i)
    {
        if(!vis[i])
        {
            x = i;
            break;
        }
    }
    if(x == -1)
        cout<<"NO"<<"\n";
    else
    {
        cout<<"YES\n"<<ans;
        for(int i=k-1;i>=0;--i)
        {
            if(x&(1<<i))
                cout<<"1";
            else
                cout<<"0";
        }
        cout<<"\n";   
    }
    for(auto &j:msk)
        vis[j] = 0;
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
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}