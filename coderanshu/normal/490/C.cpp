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
    string s;
    ll a,b;
    cin>>s>>a>>b;
    vector<int> v;
    int n=sz(s);
    ll rem=0;
    for(int i=0;i<n-1;++i)
    {   
        rem=(rem*10+s[i]-'0')%a;
        if(rem==0)
            v.pb(i+1);
    }
    if(v.empty())
    {
        cout<<"NO\n";
        return 0;
    }
    reverse(all(v));
    int cur=0;
    rem=0;
    for(int i=n-1;i>=1;--i)
    {
        rem=(rem+power(10,n-1-i,b)*(s[i]-'0')%b)%b;
        if(v[cur]==i)
        {
            if(rem==0 && s[i]!='0')
            {
                cout<<"YES\n";
                string x,y;
                for(int j=0;j<i;++j)
                    cout<<s[j];
                cout<<"\n";
                for(int j=i;j<n;++j)
                    cout<<s[j];
                return 0;
            }
            ++cur;
        }
    }
    cout<<"NO\n";
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