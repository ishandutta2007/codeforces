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

int ans = 0;
int a[N],f[N],A[N];

struct Query
{
    int l,r,id;
};
Query Q[N];

inline void add(int x)
{
    x = a[x];
    if(x<N)
    {
        if(f[x] == x)
            --ans;
        ++f[x];
        if(f[x]==x)
            ++ans;
    }
}
inline void del(int x)
{
    x = a[x];
    if(x<N)
    {
        if(f[x] == x)
            --ans;
        if(f[x] == x+1)
            ++ans;
        --f[x];
    }
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].id = i;
    }
    const int B = max(1,(int)sqrt(n));
    sort(Q+1,Q+m+1,[&](Query &a,Query &b)
    {
        if(a.l/B == b.l/B)
            return a.r<b.r;
        return a.l/B<b.l/B;
    });
    int curL = 1,curR = 0;
    for(int i=1;i<=m;++i)
    {
        while(curR<Q[i].r)
            add(++curR);
        while(curR>Q[i].r)
            del(curR--);
        while(curL>Q[i].l)
            add(--curL);
        while(curL<Q[i].l)
            del(curL++);
        A[Q[i].id] = ans;
    }
    for(int i=1;i<=m;++i)
        cout<<A[i]<<"\n";
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