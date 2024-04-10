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
    vector<int> left{1};
    vector<int> ans;
    auto query = [&](vector<int> v,int x)
    {
        cout<<"? "<<sz(v)<<" "<<1<<"\n"<<flush;
        for(auto j:v)
            cout<<j<<" ";
        cout<<"\n"<<flush;
        cout<<x<<"\n"<<flush;
        int u;
        cin>>u;
        return u;
    };
    for(int i=2;i<=n;++i)
    {
        int u = query(left,i);
        if(u != 0)
        {
            for(int j=i+1;j<=n;++j)
            {
                int x;
                cout<<"? 1 1\n"<<flush;
                cout<<i<<"\n"<<flush;
                cout<<j<<"\n"<<flush;
                cin>>x;
                if(x == 0)
                {
                    ans.pb(j);
                }
            }
            int lo = 1,hi = i-1,A = 0;
            while(lo<=hi)
            {
                vector<int> v;
                int mid = (lo+hi)/2;
                for(int i=1;i<=mid;++i)
                    v.pb(i);
                if(query(v,i) != 0)
                    A = mid,hi = mid-1;
                else
                    lo = mid+1;
            }
            for(int j=1;j<i;++j)
            {
                if(j!=A)
                {
                    ans.pb(j);
                }
            }
            break;
        }
        left.pb(i);
    }
    cout<<"! "<<sz(ans)<<" ";
    for(auto &j:ans)
        cout<<j<<" ";
    cout<<"\n"<<flush;
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