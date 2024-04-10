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
const int MOD=Mod2;
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

const int maxn=200005,maxm=pow2(17),maxk=7777714;

template<typename T, T(*op)(T,T), T(*e)(), signed N>
struct segtree{
    static const signed maxn=1<<__lg(N-1)+1;
    T val[maxn<<1];
    segtree(){rep(maxn<<1) val[i]=e();}
    void pull(signed k){val[k]=op(val[k<<1],val[k<<1|1]);}
    void modify(signed p, T x){
        p+=maxn;
        val[p]=x;
        for(p>>=1; p; p>>=1) pull(p);
    }
    T query(signed l, signed r){
        T resl=e(),resr=e();
        l+=maxn,r+=maxn+1;
        while(l<r){
            if(l&1) resl=op(resl,val[l++]);
            if(r&1) resr=op(val[--r],resr);
            l>>=1,r>>=1;
        }
        return op(resl,resr);
    }
    signed first_true(bool(*f)(T)){
        if(f(e())) return -1;
        signed cur=1;
        T curval=e();
        while(cur<maxn){
            if(!f(op(curval,val[cur*2]))) curval=op(curval,val[cur*2]),cur=cur*2+1;
            else cur*=2;
        }
        curval=op(curval,val[cur]);
        if(!f(curval)) return maxn;
        return cur-maxn;
    }
};

template<typename T, int maxn, int type>
struct sparse{
    vector<T> val[22];
    sparse(){rep(__lg(maxn)+1) val[i].resize(max(0ll,maxn-pow2(i)+1));}
    inline T oper(T i, T j){return type?max(i,j):min(i,j);}
    void init(vector<T>& vec){
        rep(sz(vec)) val[0][i]=vec[i];
        rep2(i,1,__lg(maxn)+1) rep1(j,sz(vec)-pow2(i)+1) val[i][j]=oper(val[i-1][j],val[i-1][j+pow2(i-1)]);
    }
    T query(int l, int r){return oper(val[__lg(r-l+1)][l],val[__lg(r-l+1)][r-pow2(__lg(r-l+1))+1]);}
};

//i_am_noob
//#define wiwihorz  
int n,a[maxn],par[maxn],l[maxn],r[maxn],lca_tag[maxn];
vector<vector<int>> adj(maxn);
vector<int> lca_vec;
sparse<int,maxn*2,0> lca_sp;

void dfs(int u){
    static int t=-1;
    l[u]=++t;
    lca_vec.pb(l[u]);
    lca_tag[l[u]]=sz(lca_vec)-1;
    for(auto v: adj[u]) dfs(v),lca_vec.pb(l[u]);
    r[l[u]]=t;
}

//new ids
int lca(int u, int v){return lca_sp.query(min(lca_tag[u],lca_tag[v]),max(lca_tag[u],lca_tag[v]));}

bool g(int u, int v){return v>=u&&v<=r[u];}

pii e(){return {-2,-2};}
pii add(pii p, int v){
    if(g(p.first,p.second)){
        if(g(p.second,v)) return {p.first,v};
        if(g(v,p.second)) return {min(v,p.first),p.second};
        if(lca(v,p.second)>p.first) return {-1,-1};
        return {min(p.second,v),max(p.second,v)};
    }
    int u=lca(p.first,p.second);
    if(g(v,u)&&v!=u) return {-1,-1};
    if(g(p.first,v)) return {v,p.second};
    if(g(p.second,v)) return {p.first,v};
    if(g(v,p.first)||g(v,p.second)) return {p.first,p.second};
    return {-1,-1};
}
pii op(pii p1, pii p2){
    if(p1.first==-1) return {-1,-1};
    if(p2.first==-1) return {-1,-1};
    if(p1.first==-2) return p2;
    if(p2.first==-2) return p1;
    if(p1.first==p1.second&&p2.first==p2.second) return {min(p1.first,p2.first),max(p1.first,p2.first)};
    if(p1.first==p1.second) swap(p1,p2);
    p1=add(p1,p2.first);
    if(p1.first==-1) return {-1,-1};
    p1=add(p1,p2.second);
    return p1;
}
segtree<pii,op,e,maxn> tree;

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    par[0]=-1;
    rep2(i,1,n) cin >> par[i];
    rep2(i,1,n) par[i]--,adj[par[i]].pb(i);
    dfs(0);
    lca_sp.init(lca_vec);
    rep(n) tree.modify(a[i],{l[i],l[i]});
    //tree.debug();
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op==2){
            print(min(n,(int)tree.first_true([](pii p){return p.first==-1;})));
        }
        else{
            int u,v;
            cin >> u >> v;
            u--,v--;
            swap(a[u],a[v]);
            tree.modify(a[u],{l[u],l[u]});
            tree.modify(a[v],{l[v],l[v]});
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
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}