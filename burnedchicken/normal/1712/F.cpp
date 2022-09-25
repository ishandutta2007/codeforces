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
#define eb emplace_back
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

template<typename T, int maxn>
struct sparse_min{
    vector<T> val[22];
    sparse_min(){rep(__lg(maxn)+1) val[i].resize(max(0ll,maxn-pow2(i)+1));}
    void init(vector<T>& vec){
        rep(sz(vec)) val[0][i]=vec[i];
        rep2(i,1,__lg(maxn)+1) rep1(j,sz(vec)-pow2(i)+1) val[i][j]=min(val[i-1][j],val[i-1][j+pow2(i-1)]);
    }
    T query(int l, int r){if(l>r) swap(l,r);return min(val[__lg(r-l+1)][l],val[__lg(r-l+1)][r-pow2(__lg(r-l+1))+1]);}
};

template<int maxn>
struct my_tree{
    vector<vector<signed>> adj;
    vector<vector<signed>> child_l;
    vector<signed> par,l,r,rev_l,dep,rev_euler;
    vector<pair<signed,signed>> euler;
    signed n,rt;
    pair<signed,signed> dia;
    sparse_min<pair<signed,signed>,maxn*2> sp;
    void init(signed _n){
        n=_n;
        adj.resize(_n),child_l.resize(_n);
        for(auto& vec: adj) vec.clear();
        for(auto& vec: child_l) vec.clear();
        rt=0;
    }
    void add_edge(signed u, signed v){adj[u].pb(v),adj[v].pb(u);}
    void get_parent(signed u, signed fa){
        par[u]=fa;
        for(auto v: adj[u]) if(v!=fa) get_parent(v,u);
    }
    void get_parent(){par.resize(n),get_parent(rt,-1);}
    template<typename T>
    void get_dep(signed u, signed fa, vector<T>& vec){
        vec[u]=fa==-1?0:vec[fa]+1;
        for(auto v: adj[u]) if(v!=fa) get_dep(v,u,vec);
    }
    template<typename T>
    void get_dep(signed u, vector<T>& vec){vec.resize(n);get_dep(u,-1,vec);}
    void get_dep(signed u){dep.resize(n);get_dep(u,-1,dep);}
    void get_preorder(signed u, signed fa){
        static signed t=-1;
        if(fa<0) t=-1;
        l[u]=++t;
        rev_l[l[u]]=u;
        if(fa>=0) child_l[fa].pb(l[u]);
        euler.pb({dep[u],u});
        rev_euler[u]=sz(euler)-1;
        for(auto v: adj[u]) if(v!=fa) get_preorder(v,u),euler.pb({dep[u],u});
        r[u]=t;
    }
    void get_preorder(){
        l.resize(n);r.resize(n);rev_l.resize(n);euler.clear();rev_euler.resize(n);
        get_dep(rt);
        get_preorder(rt,-1);
    }
    void init_lca(){
        get_preorder();
        sp.init(euler);
    }
    int lca(int u, int v){return sp.query(rev_euler[u],rev_euler[v]).second;}
    int dis(int u, int v){return dep[u]+dep[v]-2*sp.query(rev_euler[u],rev_euler[v]).first;}
    signed first_step(signed u, signed v){
        //call get_parent() and get_preorder() first
        if(u==v) return -1;
        if(l[v]>=l[u]&&r[v]<=r[u]) return rev_l[*--upper_bound(all(child_l[u]),l[v])];
        return par[u];
    }
    pair<signed,signed> get_diameter(){
        pair<signed,signed> res;
        get_dep(rt);
        res.first=max_element(dep.begin(),dep.end())-dep.begin();
        get_dep(res.first);
        res.second=max_element(dep.begin(),dep.end())-dep.begin();
        dia=res;
        return res;
    }
    pair<signed,signed> get_diameter(vector<int> vec){
        if(vec.empty()) return {-1,-1};
        pair<signed,signed> res={vec[0],vec[0]};
        for(auto i: vec) if(dis(vec[0],i)>dis(vec[0],res.first)) res.first=i;
        for(auto i: vec) if(dis(res.first,i)>dis(res.first,res.second)) res.second=i;
        return res;
    }
};

const int maxn=1000005,maxm=pow2(17),maxk=7777714;

//i_am_noob
//#define wiwihorz  
void balbitorz(){}

int n,val[maxn],res[maxn];
my_tree<maxn> tr;
pii a[maxn];
vector<int> need;

void orzck(){
    cin >> n;
    tr.init(n);
    rep(n-1){
        int x;
        cin >> x;
        x--;
        tr.add_edge(x,i+1);
    }
    tr.init_lca();
    rep(n) val[i]=-inf;
    queue<int> q;
    rep(n) if(sz(tr.adj[i])==1) q.push(i),val[i]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto v: tr.adj[u]) if(val[v]<0){
            val[v]=val[u]+1;
            q.push(v);
            continue;
        }
    }
    vector<vector<int>> gr(maxn),good(maxn);
    rep(n){
        gr[val[i]].pb(i);
        if(!val[i]){
            good[val[i]].pb(i);
            continue;
        }
        bool flag=1;
        for(auto j: tr.adj[i]) if(val[j]>val[i]) flag=0;
        if(flag) good[val[i]].pb(i);
    }
    rep(n) a[i]=tr.get_diameter(gr[i]);
    rep(n) if(sz(good[i])){
        pii p=tr.get_diameter(good[i]);
        need.pb(p.first),need.pb(p.second);
    }
    int maxx=*max_element(val,val+n);
    assert(sz(need)<77777);
    int tmp;
    cin >> tmp;
    while(tmp--){
        int x;
        cin >> x;
        auto f=[&](int u, int v){return min(tr.dis(u,v),val[u]+val[v]+x);};
        int ans=-1;
        for(auto u: need){
            int l=0,r=maxx;
            while(l<r-2){
                int mid=l+r>>1;
                int res1=max(f(u,a[mid].first),f(u,a[mid].second));
                int res2=max(f(u,a[mid+1].first),f(u,a[mid+1].second));
                if(res1>res2) r=mid+1;
                else l=mid;
            }
            rep2(i,l,r+1) chkmax(ans,max(f(u,a[i].first),f(u,a[i].second)));
        }
        print0(ans);
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    // #ifdef i_am_noob
    // freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
    // freopen("output2.txt","w",stderr);
    // #endif
    cout << fixed << setprecision(15);
    ld start=clock();
    balbitorz();
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}