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
    int ca,cb,ab,cora,corb;
    cout<<"AND 1 3\n"<<flush;
    cin>>ca;
    cout<<"AND 2 3\n"<<flush;
    cin>>cb;
    cout<<"AND 1 2\n"<<flush;
    cin>>ab;
    cout<<"OR 1 3\n"<<flush;
    cin>>cora;
    cout<<"OR 2 3\n"<<flush;
    cin>>corb;
    int x = 0;
    for(int j=0;j<17;++j)
    {
        if(ca&(1<<j) && cb&(1<<j))
            x |= (1<<j);
        int l = ca&(1<<j);
        int r = cb&(1<<j);
        if(l==0 && r==0 && ((ab&(1<<j))==0))
        {
            if((cora&(1<<j)) || corb&(1<<j))
                x |= (1<<j);
        }
    }
    int cxora = cora - ca;
    int cxorb = corb - cb;
    vector<int> ans(n+1,0);
    ans[2] = x^cxora;
    ans[1] = x^cxorb;
    ans[3] = x^ans[1]^ans[2];
    for(int i=4;i<=n;++i)
    {
        int x;
        cout<<"XOR 1 "<<i<<"\n"<<flush;
        cin>>x;
        ans[i] = x^ans[1];
    }
    cout<<"! ";
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout << "AshishGup";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}