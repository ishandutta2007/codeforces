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

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> v(n);
    string ans;
    int odd = 0;
    int g = 0;
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
        odd += v[i]&1;
        g = __gcd(g,v[i]);
    }
    if(odd>=2)
    {
        cout<<"0\n";
        for(int i=0;i<n;++i)
            ans += string(v[i],char(i+'a'));
        shuffle(all(ans),rng);
        cout<<ans<<"\n";
        return 0;
    }
    if(g%2 == 1)
    {
        cout<<g<<"\n";
        string u;
        for(int i=0;i<n;++i)
            if(v[i]&1)
                u += string(v[i]/g,char(i+'a'));
        string t;
        for(int i=0;i<n;++i)
            if(v[i]%2==0)
                t += string(v[i]/2/g,char(i+'a'));
        string s = t;
        reverse(all(s));
        for(int i=0;i<g;++i)
            cout<<u<<t<<s;
        cout<<"\n";
        return 0;
    }
    cout<<g<<"\n";
    for(int i=0;i<n;++i)
    {
        ans += string(v[i]/g,char(i+'a'));
    }
    string t = ans;
    reverse(all(t));
    string u;
    for(int i=0;i<g;++i)
        u += (i&1)?ans:t;
    cout<<u<<"\n";
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