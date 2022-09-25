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
const int maxn=2005,maxm=100005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,res,curscc,scc[maxn];
bool g[maxn][maxn];
vector<int> ord;
vector<vector<int>> adj(maxn),radj(maxn),vec(maxn);
bool vis[maxn];

void rdfs1(int u){
    vis[u]=1;
    rep1(v,n) if((!vis[v])&&g[v][u]) rdfs1(v);
    ord.pb(u);
}

void dfs1(int u){
    vis[u]=1;
    scc[u]=curscc;
    rep1(v,n) if((!vis[v])&&g[u][v]) dfs1(v);
}

void rdfs2(int u){
    vis[u]=1;
    for(auto v: radj[u]) if(!vis[v]) rdfs2(v);
    ord.pb(u);
}

void dfs2(int u){
    vis[u]=1;
    scc[u]=curscc;
    for(auto v: adj[u]) if(!vis[v]) dfs2(v);
}

void orzck(){
    cin >> n;
    rep(n) rep1(j,n){
        char c;
        cin >> c;
        g[i][j]=c=='1';
    }
    if(n<=6){
        vector<int> cnt(n+1);
        vector<int> fac(n+1);
        fac[0]=1;
        rep2(i,1,n+1) fac[i]=fac[i-1]*i;
        rep1(mask,pow2(n)){
            rep(n) if(mask>>i&1){
                rep1(j,n) g[i][j]^=1,g[j][i]^=1;
            }
            ord.clear();
            memset(vis,0,sizeof vis);
            rep(n) if(!vis[i]) rdfs1(i);
            reverse(all(ord));
            memset(vis,0,sizeof vis);
            curscc=0;
            for(auto i: ord) if(!vis[i]) dfs1(i),curscc++;
            if(curscc==1) cnt[__builtin_popcountll(mask)]+=fac[__builtin_popcountll(mask)];
            rep(n) if(mask>>i&1){
                rep1(j,n) g[i][j]^=1,g[j][i]^=1;
            }
        }
        rep(n+1) if(cnt[i]){
            print(i,cnt[i]);
            return;
        }
        print(-1);
        return;
    }
    ord.clear();
    memset(vis,0,sizeof vis);
    rep(n) if(!vis[i]) rdfs1(i);
    reverse(all(ord));
    memset(vis,0,sizeof vis);
    curscc=0;
    for(auto i: ord) if(!vis[i]) dfs1(i),curscc++;
    if(curscc==1){
        print(0,1);
        return;
    }
    vector<int> path;
    vector<int> id(n);
    rep(n){
        if(path.empty()){
            path.pb(i);
            continue;
        }
        if(g[i][path[0]]){
            path.insert(path.begin(),i);
            continue;
        }
        bool flag=0;
        rep1(j,sz(path)-1) if(g[path[j]][i]&&g[i][path[j+1]]){
            path.insert(path.begin()+j+1,i);
            flag=1;
            break;
        }
        if((!flag)&&g[path.back()][i]) path.pb(i),flag=1;
        assert(flag);
    }
    bug(path);
    auto cmp=[&id](int i, int j){return id[i]<id[j];};
    rep(sz(path)) id[path[i]]=i;
    rep(n) rep1(j,n) if(g[i][j]) vec[i].pb(j);
    rep(n) sort(all(vec[i]),cmp);
    rep1(u,n){
        rep(n) adj[i].clear(),radj[i].clear();
        rep(n) if(u!=i){
            if(g[u][i]) adj[i].pb(u),bug(i,u);
            else adj[u].pb(i),bug(u,i);
        }
        rep(sz(path)-1) if(path[i]!=u&&path[i+1]!=u) adj[path[i]].pb(path[i+1]),bug(path[i],path[i+1]);
        rep(n) if(i!=u&&sz(vec[i])){
            if(id[vec[i][0]]<id[u]) adj[i].pb(vec[i][0]),bug(i,vec[i][0]);
            auto it=upper_bound(all(vec[i]),u,cmp);
            if(it==vec[i].end()) continue;
            adj[i].pb(*it),bug(i,*it);
        }
        rep(n) for(auto v: adj[i]) radj[v].pb(i);
        ord.clear();
        memset(vis,0,sizeof vis);
        rep(n) if(!vis[i]) rdfs2(i);
        reverse(all(ord));
        memset(vis,0,sizeof vis);
        curscc=0;
        for(auto i: ord) if(!vis[i]) dfs2(i),curscc++;
        bug(curscc);
        if(curscc==1) res++;
    }
    print(1,res);
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