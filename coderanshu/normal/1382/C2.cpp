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
    int n;
    string a,b;
    cin>>n>>a>>b;
    if(a==b)
    {
        cout<<0<<"\n";
        return 0;
    }
    vector<int> ans;
    int cnt=0,flip=0;
    for(int i=n-1;i>=0;--i)
    {
        if(i==0)
        {
            if(a[0]!=b[0])
                ans.pb(1);
            continue;
        }
        int y=flip+((cnt%2)?-i:i);
        char c=a[y];
        if(cnt%2)
            c^='0'^'1';
        if(c==b[i])
            continue;
        if(c!=a[0])
        {
            ans.pb(1),a[0]=a[0]^'0'^'1';
        }
        flip+=(cnt&1)?-i:i;
        ++cnt;
        a[0]=a[0]^'0'^'1';
        ans.pb(i+1);
    }
    cout<<sz(ans)<<" ";
    for(auto j:ans)
        cout<<j<<" ";
    cout<<"\n";
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