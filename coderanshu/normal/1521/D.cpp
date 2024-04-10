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


template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string) s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(char c) {
    string t = "'" + string(1,c) + "'";
    return t;
}
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for(size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}


template<typename T>
void debug_out(const char* name, T&& x) { 
    cerr << "[" << name << "] : " << to_string(x) << endl; 
}
template <typename H, typename... T>
void debug_out(const char* names, H&& arg1, T&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr << "[";
    cerr.write(names, comma - names) << "] : " << to_string(arg1) <<"\n";
    debug_out(comma+1, args...);
}
#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


const int N = 100005;

ll dp[N][2];

ll X[N],Y[N][2];
vector<int> v[N];
set<int> g[N];

void dfs(int s,int p)
{
    int deg = sz(v[s]);
    if(s != 1)
        --deg;
    ll cur = 0;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            dp[s][0] += min(dp[j][0],dp[j][1]);
            cur += min(dp[j][1],dp[j][0]);
        }
    }
    dp[s][0] += deg;
    X[s] = -1;
    ll val = INF,ver = -1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            if(cur - min(dp[j][1],dp[j][0]) + dp[j][0] + deg - 1 < val)
                val = cur - min(dp[j][1],dp[j][0]) + dp[j][0] + deg - 1,ver = j;
        }
    }
    if(val < dp[s][0])
    {
        dp[s][0] = val;
        if(ver != -1)
            X[s] = ver;
    }
    // dp[0] done
    Y[s][0] = Y[s][1] = -1;
    dp[s][1] = INF;
    if(deg >= 2)
    {
        ll val = 0;
        vector<pll> tmp;
        for(auto j:v[s])
        {
            if(j == p)
                continue;
            val += min(dp[j][1],dp[j][0]);
            tmp.push_back({dp[j][0] - min(dp[j][1],dp[j][0]),j});
        }
        val += deg - 2;
        sort(all(tmp));
        val += tmp[0].F + tmp[1].F;
        Y[s][0] = tmp[0].S,Y[s][1] = tmp[1].S;
        amin(dp[s][1],val);
    }
}


void dfs2(int s,int p,int st,vector<pii> &rm)
{
    if(st == -1)
        st = dp[s][0] < dp[s][1] ? 0 : 1;
    if(st == 0)
    {
        for(auto j:v[s])
        {
            if(j!=p)
            {
                if(j == X[s])
                    dfs2(j,s,0,rm);
                else
                    dfs2(j,s,-1,rm),g[s].erase(j),g[j].erase(s),rm.push_back({j,s});
            }
        }
    }
    else
    {
        for(auto j:v[s])
        {
            if(j!=p)
            {
                if(j == Y[s][0] || j == Y[s][1])
                    dfs2(j,s,0,rm);
                else
                    dfs2(j,s,-1,rm),g[s].erase(j),g[j].erase(s),rm.push_back({j,s});
            }
        }
    }
}

void chains(int s,vector<bool> &vis,vector<int> &A)
{
    A.push_back(s);
    vis[s] = true;
    for(auto j:g[s])
    {
        if(!vis[j])
            chains(j,vis,A);
    }
}


int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        v[i].clear();g[i].clear();X[i] = -1,Y[i][0] = Y[i][1] = -1;
        dp[i][0] = dp[i][1] = 0;
    }
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
        g[x].insert(y),g[y].insert(x);
    }
    dfs(1,0);
    vector<pii> rm;
    dfs2(1,0,-1,rm);
    // for(int i=1;i<=n;++i)
    // {
    //     // debug(i,g[i]);
    // }
    vector<bool> vis(n+1,false);
    vector<pii> c;
    for(int i=1;i<=n;++i)
    {
        if(vis[i])
            continue;
        vector<int> A;
        chains(i,vis,A);
        sort(all(A),[&](int x,int y){
            return sz(g[x]) < sz(g[y]);
        });
        if(sz(A) == 1)
            c.push_back({A[0],A[0]});
        else
            c.push_back({A[0],A[1]});
    }
    // debug(c);
    assert(sz(c) - 1 == sz(rm));
    cout<<sz(rm)<<"\n";
    for(int i=1;i<sz(c);++i)
    {
        cout<<rm[i-1].F<<" "<<rm[i-1].S<<" "<<c[0].S<<" "<<c[i].F<<"\n";
        c[0].S = c[i].S;
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