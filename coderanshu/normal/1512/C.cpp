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
    int a,b;
    cin>>a>>b;
    int n = a + b;
    string s;
    cin>>s;
    for(auto &j:s)
        a -= j == '0',b -= j == '1';
    vector<int> id;
    for(int i=0;;++i)
    {
        if(i>=n-i-1)
            break;
        if(s[i] == '?' || s[n-i-1] == '?')
        {
            if(s[i] == '?' && s[n-i-1] == '?')
                id.push_back(i);
            else
            {
                char c = s[i] ^ s[n-1-i] ^ '?';
                s[i] = s[n-1-i] = c;
                a -= c == '0', b -= c == '1';
            }
        }
        if(s[i] != s[n-1-i])
        {
            cout<<"-1\n";return 0;
        }
    }
    if(a < 0 || b < 0)
    {
        cout<<"-1\n";return 0;
    }
    bool have = false;
    if(n % 2 == 1 && s[n/2] == '?')
        have = true;
    if(have && (a+b)%2 == 1)
    {
        if(a % 2 == 1)
            s[n/2] = '0',--a;
        else
            s[n/2] = '1',--b;
        assert(a + b == 2 * sz(id));
        for(auto &j:id)
        {
            if(a)
                s[j] = s[n-1-j] = '0',a -= 2;
            else
                s[j] = s[n-1-j] = '1',b -= 2;
        }
        cout<<s<<"\n";
        return 0;
    }
    if(!have && (a + b)% 2 == 0 && a % 2 == 0 && b % 2 == 0)
    {
        assert(a + b == 2 * sz(id));
        for(auto &j:id)
        {
            if(a)
                s[j] = s[n-1-j] = '0',a -= 2;
            else
                s[j] = s[n-1-j] = '1',b -= 2;
        }
        cout<<s<<"\n";
        return 0;
    }
    cout<<"-1\n";
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