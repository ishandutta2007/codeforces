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
    int l = 1,r = n;
    cout<<"? 1 "<<n<<"\n"<<flush;
    int pos;
    cin>>pos;
    bool left = false;
    if(pos != 1)
    {
        cout<<"? 1 "<<pos<<"\n"<<flush;
        int tmp;
        cin>>tmp;
        if(tmp==pos)
            left = true;
    }
    else
    {
        left = false;
    }
    int ans = -1;
    if(left)
    {
        int lo=1,hi=pos-1;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            cout<<"? "<<mid<<" "<<pos<<"\n"<<flush;
            int x;
            cin>>x;
            if(x == pos)
                lo = mid+1,ans = mid;
            else
                hi = mid-1;
        }
    }
    else
    {
        int lo = pos+1,hi = n;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            cout<<"? "<<pos<<" "<<mid<<"\n"<<flush;
            int x;
            cin>>x;
            if(x == pos)
                hi = mid-1,ans = mid;
            else
                lo = mid+1;
        }
    }
    assert(ans!=-1);
    cout<<"! "<<ans<<"\n"<<flush;
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