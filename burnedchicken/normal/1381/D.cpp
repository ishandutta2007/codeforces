#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val%mod;if(val<0) val+=mod;}
    Modint operator +(const Modint& o) const {
        Modint res;
        res.val=val+o.val;
        if(res.val>=mod) res.val-=mod;
        return res;
    }
    Modint operator +(const int& o) const {return Modint(val+o);}
    Modint operator -() const {
        Modint res;
        res.val=-val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const Modint& o) const {
        Modint res;
        res.val=val-o.val;
        if(res.val<0) res.val+=mod;
        return res;
    }
    Modint operator -(const int& o) const {return Modint(val-o);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val);}
    Modint operator *(const int& o) const {return Modint(val*(o%mod));}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(int b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, int b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    Modint operator /(const int& o) const {return *this*Modint(o).inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
template<int mod>
ostream& operator << (ostream& o, Modint<mod> x){return o << x.val;}
template<int mod>
Modint<mod> operator +(const int& x, const Modint<mod>& y){return Modint<mod>(x+y.val);}
template<int mod>
Modint<mod> operator -(const int& x, const Modint<mod>& y){return Modint<mod>(x-y.val);}
template<int mod>
Modint<mod> operator *(const int& x, const Modint<mod>& y){return Modint<mod>(x%mod*y.val);}
#define modint Modint<MOD>
vector<modint> inv,fac,invfac;
void init_comb(int N){
    inv.resize(N),fac.resize(N),invfac.resize(N);
    inv[1]=1,fac[0]=1,invfac[0]=1;
    rep2(i,2,N) inv[i]=inv[MOD%i]*(MOD-MOD/i);
    rep2(i,1,N) fac[i]=fac[i-1]*i;
    rep2(i,1,N) invfac[i]=invfac[i-1]*inv[i];
}
inline modint C(int n, int m){return m>n||m<0?modint(0):fac[n]*invfac[m]*invfac[n-m];}
inline modint H(int n, int m){return C(n+m-1,n);}
const int maxn=100005,maxm=100005,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,a,b,fa[maxn],dep[maxn],dep2[maxn];
vector<vector<int>> adj;
vector<int> snake;

void dfs1(int u, int par){
    fa[u]=par;
    dep[u]=par==-1?0:dep[par]+1;
    for(auto v: adj[u]) if(v!=par) dfs1(v,u);
}

void dfs2(int u, int par){
    dep2[u]=par==-1?0:dep2[par]+1;
    for(auto v: adj[u]) if(v!=par) dfs2(v,u);
}

vector<int> find_path(int u, int v){
    vector<int> res1,res2;
    while(dep[u]>dep[v]) res1.pb(u),u=fa[u];
    while(dep[v]>dep[u]) res2.pb(v),v=fa[v];
    while(u!=v) res1.pb(u),res2.pb(v),u=fa[u],v=fa[v];
    res1.pb(u);
    reverse(all(res2));
    for(auto i: res2) res1.pb(i);
    return res1;
}

bool vis[maxn];

int dfs3(int u, int par){
    int res=0;
    for(auto v: adj[u]) if(v!=par&&!vis[v]) chkmax(res,dfs3(v,u)+1);
    return res;
}

vector<int> solve(vector<int> path){
    rep(n) vis[i]=0;
    vector<int> res(sz(path));
    for(auto i: path) vis[i]=1;
    rep(sz(path)) res[i]=dfs3(path[i],-1);
    return res;
}

void orzck(){
    cin >> n >> a >> b;
    a--,b--;
    adj.resize(n);
    rep(n) adj[i].clear();
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs1(0,-1);
    int u1=max_element(dep,dep+n)-dep;
    dfs2(u1,-1);
    int u2=max_element(dep2,dep2+n)-dep2;
    snake=find_path(a,b);
    int x=sz(snake)-1;
    vector<int> diam=find_path(u1,u2);
    vector<int> vec1=solve(diam);
    if(*max_element(all(vec1))<sz(snake)-1){
        print("NO");
        return;
    }
    vector<int> vec2=solve(snake);
    int curl=0,curr=sz(snake)-1;
    int maxl=vec2[0],maxr=vec2[sz(snake)-1];
    while(1){
        if(maxl+maxr+(curr-curl)>=2*x){
            print("YES");
            return;
        }
        bool flag=0;
        if(maxr+(curr-curl)>x) maxl=max(maxl+1,vec2[curl+1]),curl++,flag=1;
        if(maxl+(curr-curl)>x) maxr=max(maxr+1,vec2[curr-1]),curr--,flag=1;
        if(!flag){
            print("NO");
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}