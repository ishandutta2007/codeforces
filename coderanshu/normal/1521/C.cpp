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
    vector<pii> got;
    vector<int> a(n+1);
    auto done = [&](int id)
    {
        a[id] = 1;
        for(int i=1;i<=n;++i)
        {
            if(i == id)
                continue;
            cout<<"? 1 "<<id<<" "<<i<<" "<<n-1<<"\n"<<flush;
            int x;
            cin>>x;
            a[i] = x;
        }
        cout<<"! ";
        for(int i=1;i<=n;++i)
            cout<<a[i]<<" ";
        cout<<"\n"<<flush;
        return 0;
    };
    for(int i=1;i<=n-n%2;i+=2)
    {
        cout<<"? 2 "<<i<<" "<<i+1<<" "<<1<<"\n"<<flush;
        int x;
        cin>>x;
        if(x == 1)
        {
            // a[i] = 1
            done(i);
            return 0;
        }
        if(x == 2)
        {
            cout<<"? 2 "<<i+1<<" "<<i<<" "<<1<<"\n"<<flush;
            int x;
            cin>>x;
            if(x == 1)
            {
                done(i+1);return 0;
            }
        }
    }
    cout<<"? 2 "<<n-1<<" "<<n<<" "<<1<<"\n"<<flush;
    int x;
    cin>>x;
    if(x == 1)
    {
        done(n-1);return 0;
    }
    if(x == 2)
    {
        cout<<"? 2 "<<n<<" "<<n-1<<" "<<1<<"\n"<<flush;
        int x;
        cin>>x;
        if(x == 1)
        {
            done(n);return 0;
        }
    }
    assert(false);
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