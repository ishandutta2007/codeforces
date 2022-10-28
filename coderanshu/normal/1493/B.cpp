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
    int h,m;
    cin>>h>>m;
    map<int,int> mp;
    mp[0] = 0;
    mp[1] = 1,mp[2] = 5,mp[5] = 2,mp[8] = 8;
    auto f = [&](int x,int y)
    {
        int f1 = x/10%10,f2 = x%10,g1 = y/10%10,g2 = y%10;
        if(!mp.count(f1))
            return false;
        if(!mp.count(f2))
            return false;
        if(!mp.count(g1))
            return false;
        if(!mp.count(g2))
            return false;
        x = mp[g2]*10+mp[g1];
        y = mp[f2]*10+mp[f1];
        if(x>=0 && x<h && y>=0 && y<m)
            return true;
        return false;
    };
    string s;
    cin>>s;
    int x = (s[0]-'0')*10 + (s[1]-'0');
    int y = (s[3]-'0')*10+(s[4]-'0');
    while(!f(x,y))
    {
        if(y == m-1)
            y = 0,x = (x+1)%h;
        else
            ++y;
    }
    cout<<(x/10%10)<<x%10<<":"<<(y/10%10)<<y%10<<"\n";
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