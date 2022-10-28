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

const int N = 1010;

const int X = N*(N-1)/2;

int a[N][N];

int cur = 0;
int sal[X];
int p[X],r[X];
int val[X],node[X];

vector<pii> ed;
int parent(int i)
{
    return p[i] = (p[i] == i)?i:parent(p[i]);
}

void merge(int x,int y,int z,int ss)
{
    x = parent(x),y = parent(y);
    if(x == y)
        return ;
    if(r[x]>r[y])
        swap(x,y);
    r[y] += r[x];
    val[y] = ss;
    p[x] = y;
    node[y] = z;
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    set<pair<int,pii>> s;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            if(i == j)
                sal[i] = a[i][j];
            else
                s.insert({a[i][j],{i,j}});
        }
    }
    for(int i=1;i<X;++i)
        r[i] = 1,p[i] = i,val[i] = sal[i],node[i] = i;
    cur = n+1;
    while(!s.empty())
    {
        auto [x,y] = *s.begin();
        s.erase(s.begin());
        if(val[parent(y.F)] == x || val[parent(y.S)] == x)
        {
            if(parent(y.F) == parent(y.S))
                continue;
            if(val[parent(y.F)] == x)
            {
                ed.pb({node[parent(y.S)],node[parent(y.F)]});
                merge(y.F,y.S,node[parent(y.F)],x);
            }
            else
            {
                ed.pb({node[parent(y.F)],node[parent(y.S)]});
                merge(y.F,y.S,node[parent(y.S)],x);
            }
            continue;
        }
        int u = cur++;
        sal[u] = x;
        ed.pb({node[parent(y.S)],u});
        ed.pb({node[parent(y.F)],u});
        merge(y.F,y.S,u,x);
    }
    int r = node[parent(1)];
    cout<<cur-1<<"\n";  
    for(int i=1;i<=cur-1;++i)
        cout<<sal[i]<<" ";
    cout<<"\n";cout<<r<<"\n";
    for(auto j:ed)
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