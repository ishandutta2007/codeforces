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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

const int N = 100005;

int p[N][2], r[N][2];

int parent(int i,int j)
{
    return p[i][j] = p[i][j] == i ? i : parent(p[i][j],j);
}

bool merge(int x,int y,int j)
{
    int a = parent(x,0), b = parent(y,0);
    int aa = parent(x,1), bb = parent(y,1);
    if((a == b && j == 0) || (aa == bb && j == 1) || (j == 2 && (a == b || aa == bb)))
        return false;
    if(j == 0 || j == 2) {
        if(r[a][0] > r[b][0])
            swap(a,b);
        r[b][0] += r[a][0];
        p[a][0] = b;
    }
    if(j == 1 || j == 2) 
    {
        if(r[aa][1] > r[bb][1])
            swap(aa,bb);
        r[bb][1] += r[aa][1];
        p[aa][1] = bb;
    }
    return true;
}

int _runtimeTerror_()
{
    int n,m1,m2;
    cin >> n >> m1 >> m2;

    for(int i=1;i<=n;++i)
    {
        p[i][0] = p[i][1] = i;
        r[i][0] = r[i][1] = 1;
    }

    cout << n - 1 - max(m1, m2) << "\n";

    for(int i=0;i<m1;++i)
    {
        int x,y;
        cin >> x >> y;
        merge(x,y,0);
    }
    for(int i=0;i<m2;++i)
    {
        int x,y;
        cin >> x >> y;
        merge(x,y,1);
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(merge(i,j,2))
                cout << i << " " << j << "\n";
        }
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}