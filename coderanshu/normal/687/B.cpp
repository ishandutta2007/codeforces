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

#define runSieve
const int N=1000005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    vector<int> c(n);
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
        while(!prime[c[i]] && c[i] != 1)
        {
            int z = pf[c[i]];
            int p = 0;
            while(c[i] % z == 0)
                c[i] /= z,++p;
            amax(mp[z],p);
        }
        if(c[i] != 1)
            amax(mp[c[i]],1);
    }
    bool ans = true;
    while(k!=1 && !prime[k])
    {
        int z = pf[k];
        int p = 0;
        while(k%z == 0)
            k /= z,++p;
        if(mp[z] < p)
        {
            cout<<"No\n";return 0;
        }
    }
    if(k!=1 && mp[k] < 1)
    {
        cout<<"No\n";return 0;
    }
    cout<<"Yes\n";
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