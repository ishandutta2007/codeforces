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

const int N = 100005;

map<ll,bool> pos;

void go(int l,int r,vector<ll> &a,vector<ll> &sum)
{
    // cout<<l<<" "<
    pos[sum[r] - (l>0?sum[l-1]:0)] = true;
    ll mid = (a[l] + a[r])/2;
    auto id = upper_bound(all(a),mid)-a.begin();
    if(id<=l || id>r)
        return ;
    go(l,id-1,a,sum),go(id,r,a,sum);
}

int _runtimeTerror_()
{
    int n,Q;
    cin>>n>>Q;
    vector<ll> a(n),sum(n,0);
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(all(a));
    sum[0] = a[0];
    for(int i=1;i<n;++i)
        sum[i] += sum[i-1] + a[i];
    pos.clear();
    go(0,n-1,a,sum);
    while(Q--)
    {
        ll x;
        cin>>x;
        if(pos[x])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
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