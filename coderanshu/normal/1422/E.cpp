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
    cin>>s;
    int n = sz(s);
    vector<char> v;
    vector<pair<char,int>>u;
    vector<int> idx;
    char last = 0;
    vector<pair<int,string>> ans;
    u.pb({0,1});
    for(int i=n-1;i>=0;--i)
    {
        if(!v.empty() && v.back()==s[i] && u.size()>=2 && (u[sz(u)-2].F<s[i]) && idx.back()==i+1)
        {
            v.pop_back();
            idx.pop_back();
            if(u.back().S==1)
                u.pop_back();
            else
                --u.back().S;
        }
        else
        {
            v.pb(s[i]);
            idx.pb(i);
            if(u.empty() || u.back().F!=s[i])
                u.pb({s[i],1});
            else
                ++u.back().S;
        }
        // if(u.empty() || u.back()!=s[i])
            // u.pb(s[i]);
        int u = sz(v);
        string l;
        if(u<=10)
        {
            for(auto &j:v)
                l.pb(j);
            reverse(all(l));
        }
        else
        {
            for(int i=0;i<5;++i)
                l.pb(v[u-1-i]);
            l += "...";
            l.pb(v[1]);l.pb(v[0]);
        }
        ans.pb({u,l});
        // cout<<sz(v)<<"\n";
    }
    reverse(all(ans));
    for(auto &j:ans)
        cout<<j.F<<" "<<j.S<<"\n";
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