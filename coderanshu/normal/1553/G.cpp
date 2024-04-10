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
#define runSieve


const int N = 1000005;

bool prime[N];

int pf[N];

void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

int p[N],sz[N];

int parent(int i)
{
    return p[i] == i ? i : parent(p[i]);
}

void merge(int x,int y)
{
    x = parent(x),y = parent(y);
    if(x == y)
        return ;
    if(sz[x] > sz[y])
        swap(x,y);
    sz[y] += sz[x];
    p[x] = y;
}

int have[N];

int _runtimeTerror_()
{
    int n,Q;
    cin >> n >> Q;
    for(int i=1;i<=1e6;++i)
        p[i] = i,sz[i] = 1;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        int tmp = a[i];
        while(tmp != 1 && !prime[tmp])
        {
            int z = pf[tmp];
            if(have[z])
                merge(have[z],a[i]);
            while(tmp % z == 0)
                tmp /= z;
            have[z] = a[i];
        }
        if(tmp > 1 && have[tmp])
            merge(have[tmp],a[i]);
        have[tmp] = a[i];
    }
    set<pii> can;
    for(int i=1;i<=n;++i)
    {
        int tmp = a[i] + 1;
        vector<int> h;
        h.push_back(parent(a[i]));
        while(tmp != 1 && !prime[tmp])
        {
            int z = pf[tmp];
            if(have[z])
                h.push_back(parent(have[z]));
            while(tmp % z == 0)
                tmp /= z;
        }
        if(tmp > 1 && have[tmp])
            h.push_back(parent(have[tmp]));
        sort(all(h));
        h.resize(unique(all(h)) - h.begin());
        for(auto &j:h)
        {
            for(auto &k:h)
            {
                if(j != k)
                    can.insert({j,k});
            }
        }
    }
    while(Q--)
    {
        int x,y;
        cin >> x >> y;
        x = a[x],y = a[y];
        x = parent(x),y = parent(y);
        if(x == y)
            cout << "0\n";
        else if(can.count({x,y}))
            cout << "1\n";
        else
            cout << "2\n";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}