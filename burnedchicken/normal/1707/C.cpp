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

template<int maxn>
struct dsu{
    int par[maxn],siz[maxn];
    dsu(){rep(maxn) par[i]=i,siz[i]=1;}
    void init(int n){rep(n) par[i]=i,siz[i]=1;}
    int Find(int x){return x==par[x]?x:par[x]=Find(par[x]);}
    bool Union(int x, int y){
        x=Find(x),y=Find(y);
        if(x==y) return false;
        if(siz[x]<siz[y]) swap(x,y);
        par[y]=x;
        siz[x]+=siz[y];
        return true;
    }
};

const int maxn=200005,maxm=105,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,m,g[maxn][2],par[maxn],dep[maxn],l[maxn],r[maxn],pos[maxn],arr[maxn];
dsu<maxn> d;
bool good[maxn];
vector<vector<int>> adj(maxn),vec(maxn);
string res;

void dfs(int u, int fa){
    static int t=-1;
    par[u]=fa;
    dep[u]=fa==-1?0:dep[fa]+1;
    l[u]=++t;
    for(auto v: adj[u]) if(v!=fa) dfs(v,u),vec[u].pb(l[v]);
    r[u]=t;
}

bool is_anc(int u, int v){
    if(dep[v]<=dep[u]) return 0;
    if(l[v]>=l[u]&&r[v]<=r[u]) return 1;
    return 0;
}

void add(int u, int x){
    arr[l[u]]+=x;
    arr[r[u]+1]-=x;
}

void orzck(){
    cin >> n >> m;
    rep(m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[i][0]=u,g[i][1]=v;
        if(d.Union(u,v)) good[i]=1,adj[u].pb(v),adj[v].pb(u);
    }
    dfs(0,-1);
    rep(n) sort(all(vec[i]));
    rep(n) pos[l[i]]=i;
    rep(m) if(!good[i]){
        int u=g[i][0],v=g[i][1];
        if(dep[u]>dep[v]) swap(u,v);
        if(is_anc(u,v)){
            auto w=*--upper_bound(all(vec[u]),l[v]);
            auto u2=pos[w];
            add(v,1);
            add(0,1);
            add(u2,-1);
        }
        else{
            add(u,1),add(v,1);
        }
    }
    rep2(i,1,n+1) arr[i]+=arr[i-1];
    rep(n){
        if(arr[l[i]]==m-(n-1)) res+='1';
        else res+='0';
    }
    print(res);
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
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}