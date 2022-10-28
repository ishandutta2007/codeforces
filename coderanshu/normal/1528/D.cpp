#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             20000000000000000
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
    cerr.write(names, comma - names) << "] : " << to_string(arg1) <<" | ";
    debug_out(comma+1, args...);
}
#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif



const int N = 602;

ll ans[N][N];

bool done[N][N];

ll g[N][N];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            g[i][j] = INF,ans[i][j] = INF;
    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        amin(g[x][y],w);
    }
    for(int i=0;i<n;++i)
    {
        ans[i][i] = 0;
        for(int it=0;it<n+1;++it)
        {
            int my = i;
            if(it > 0)
            {
                pair<ll,ll> dis = {INF,-1};
                for(int j=0;j<n;++j)
                    if(!done[i][j])
                        amin(dis,make_pair(ans[i][j],j+0ll));
                my = dis.second;
                assert(my < n);
            }
            if(my == -1)
                break;
            // debug(my);
            // debug(i,my);
            if(it != 0)
                done[i][my] = true;
            ll cur = ans[i][my];
            if(it == 0)
                ans[i][my] = INF;
            for(int j=0;j<n;++j)
            {
                ll u = cur + g[my][j];
                amin(ans[i][(j+cur)%n],u);
            }
            if(it > 0)
                for(int j=0;j<n;++j)
                    amin(ans[i][(j+my)%n],cur+j);
        }
        ans[i][i] = 0;
        for(int j=0;j<n;++j)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
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