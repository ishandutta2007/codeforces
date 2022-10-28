// Har Har Mahadev
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

const int N = 200005;
vector<int> v[N];
vector<int> t_sort;
int idx[N];
int vs[N];

bool dfs_sort(int u)
{
    vs[u]=2;
    for(auto j:v[u])
    {
        if(vs[j]==2)
            return true;
        if(vs[j]==0 && dfs_sort(j))
            return true;
    }
    vs[u]=1;
    t_sort.push_back(u);
    return false;
}

// Returns true if there is a topological sort else returns false
bool top_sort(int n)
{
    t_sort.clear();
    for(int i=1;i<=n;++i)
        vs[i]=0;
    for(int i=1;i<=n;++i)
    {
        if(vs[i]==0)
        {
            if(dfs_sort(i))
            {
                t_sort.clear();
                return false;
            }
        }
    }
    reverse(t_sort.begin(),t_sort.end());
    assert(t_sort.size()==n);
    for(int i=0;i<n;++i)
        idx[t_sort[i]]=i;
    return true;
}

int _runtimeTerror_()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> a(n+1);
    map<string,int> mp;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        mp[a[i]] = i;
    }
    for(int i=1;i<=m;++i)
    {
        string s;
        int mt;
        cin>>s>>mt;
        bool pos = false;
        vector<int> x;
        for(int j=0;j<(1<<k);++j)
        {
            string t = s;
            for(int l=0;l<4;++l)
                if(j&(1<<l))
                    t[l] = '_';
            if(mp.count(t))
                x.pb(mp[t]);
            if(t == a[mt])
                pos = true;
        }
        if(!pos)
        {
            cout<<"NO\n";return 0;
        }
        for(auto &j:x)
        {
            if(j==mt)
                continue;
            v[mt].pb(j);
        }
    }
    if(top_sort(n))
    {
        cout<<"YES\n";
        for(auto &j:t_sort)
            cout<<j<<" ";
        cout<<"\n";
    }
    else
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