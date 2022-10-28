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

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> a(1000001,0);
    vector<int> b(20,0),u,t;
    auto add = [&](int x)
    {
        int tmp = x;
        for(int j=0;j<20;++j)
        {
            if(x & (1<<j))
            {
                if(!b[j])
                {
                    b[j] = x;
                    u.push_back(tmp);
                }
                x ^= b[j];
            }
        }
    };
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        a[x] = 1;
    }
    int cur = 1;
    for(int i=1;i<=1000000;i*=2)
    {
        while(cur < i)
        {
            if(a[cur])
                add(cur);
            ++cur;
        }
        if(1<<(sz(u)) == i)
            t = u;
    }
    cout<<sz(t)<<"\n";
    cur = 0;
    cout<<"0 ";
    if(sz(t) == 0)
        return 0;
    auto get = [&](int mask)
    {
        int val = 0;
        for(int j=0;j<20;++j)
        {
            if(mask&(1<<j))
                val ^= t[j];
        }
        return val;
    };
    vector<int> A{0};
    A.push_back(1);
    for(int j=1;j<sz(t);++j)
    {
        vector<int> B;
        int b = sz(A)-1;
        for(int i=b;i>=0;--i)
        {
            A.push_back(A[i]|(1<<j));
        }
    }
    for(int j=1;j<sz(A);++j)
        cout<<get(A[j])<<" ";
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