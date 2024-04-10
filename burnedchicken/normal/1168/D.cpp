#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
//#define int ll
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
struct segment_tree{
    vector<int> val,tag;
    int type,L,R;
    inline int mid(int l, int r){return l+r>>1;}
    segment_tree(int _siz=0, int _type=0){val.resize(4*_siz),tag.resize(4*_siz),type=_type,L=0,R=_siz-2;}
    inline int oper(int i, int j){
        if(type==0) return i+j;
        else if(type==1) return min(i,j);
        else return max(i,j);
    }
    inline int def(){
        if(type==0) return 0;
        else if(type==1) return 1e9;
        else return -1e9;
    }
    void pull(int k){val[k]=oper(val[k<<1],val[(k<<1)+1]);}
    void push(int k, int l, int r){
        if(l!=r){
            if(type){
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=tag[k];
                val[(k<<1)+1]+=tag[k];
            }
            else{
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=(mid(l,r)-l+1)*tag[k];
                val[(k<<1)+1]+=(r-mid(l,r))*tag[k];
            }
        }
        tag[k]=0;
    }
    void modify_in(int k, int l, int r, int ql, int qr, int x){
        if(l>qr||r<ql) return;
        if(ql<=l&&qr>=r){
            if(type) val[k]+=x;
            else val[k]+=(r-l+1)*x;
            tag[k]+=x;
            return;
        }
        push(k,l,r);
        modify_in(k<<1,l,mid(l,r),ql,qr,x);
        modify_in((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
        pull(k);
    }
    int query_in(int k, int l, int r, int ql, int qr){
        if(l>qr||r<ql) return def();
        if(ql<=l&&qr>=r) return val[k];
        push(k,l,r);
        return oper(query_in(k<<1,l,mid(l,r),ql,qr),query_in((k<<1)+1,mid(l,r)+1,r,ql,qr));
    }
    void modify(int l, int r, int x){modify_in(1,L,R,l,r,x);}
    int query(int l, int r){return query_in(1,L,R,l,r);}
};
const int maxn=150005,maxm=50005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,q,siz[maxn],dep[maxn],par[maxn][18],head[maxn],l[maxn],r[maxn],val[maxn];
vector<vector<int>> adj(maxn);
segment_tree tree[26],hldtree(maxn,2);
set<int> st;

void dfs1(int u){
    dep[u]=par[u][0]==-1?0:dep[par[u][0]]+1;
    rep2(i,1,18) par[u][i]=par[u][i-1]==-1?-1:par[par[u][i-1]][i-1];
    siz[u]=1;
    for(auto v: adj[u]) dfs1(v),siz[u]+=siz[v];
}

void dfs2(int u, int h){
    static int t=-1;
    l[u]=++t;
    head[u]=h;
    int maxx=-1,maxid=-1;
    for(auto v: adj[u]) if(siz[v]>maxx) maxx=siz[v],maxid=v;
    if(maxid>=0) dfs2(maxid,h);
    for(auto v: adj[u]) if(v!=maxid) dfs2(v,v);
    r[u]=t;
    if(l[u]==r[u]) st.insert(dep[u]);
}

void hld_modify(int u, int v, int x){
    int c=0;
    while(dep[head[v]]>dep[u]) hldtree.modify(l[head[v]],l[v],x),v=par[head[v]][0],c++;
    assert(c<=20);
    hldtree.modify(l[u],l[v],x);
}

int dfs3(int u, int x){
    int res=0;
    for(auto v: adj[u]) chkmax(res,dfs3(v,x)+(val[v]==x));
    hldtree.modify(l[u],l[u],res);
    return res;
}

void add(int u, int x){
    int v=par[u][0];
    int de=tree[x].query(l[u],r[u])+1;
    if(de<=tree[x].query(l[v],r[v])){
        tree[x].modify(l[u],r[u],1);
        return;
    }
    rep3(i,17,0) if(par[v][i]!=-1&&de>tree[x].query(l[par[v][i]],r[par[v][i]])) v=par[v][i];
    tree[x].modify(l[u],r[u],1);
    bug(v,par[u][0]);
    hld_modify(v,par[u][0],1);
}

void sub(int u, int x){
    int v=par[u][0];
    tree[x].modify(l[u],r[u],-1);
    int de=tree[x].query(l[u],r[u]);
    if(de<tree[x].query(l[v],r[v])){
        return;
    }
    rep3(i,17,0) if(par[v][i]!=-1&&de>=tree[x].query(l[par[v][i]],r[par[v][i]])) v=par[v][i];
    bug(v,par[u][0]);
    hld_modify(v,par[u][0],-1);
}

int m;

bool check(){
    return hldtree.val[1]<=0;
}

bool check_naive(){
    rep(n){
        int tot=0;
        rep1(j,26) tot+=tree[j].query(l[i],r[i]);
        for(int u=i; u>0; u=par[u][0]) if(val[u]>=0) tot--;
        if(tot>m-dep[i]) return false;
    }
    return true;
}

void orzck(){
    rep(26) tree[i]=segment_tree(maxn,2);
    cin >> n >> q;
    par[0][0]=-1;
    rep2(i,1,n){
        int x;
        cin >> x;
        x--;
        adj[x].pb(i);
        par[i][0]=x;
        char c;
        cin >> c;
        if(c=='?') val[i]=-1;
        else val[i]=c-'a';
    }
    dfs1(0);
    dfs2(0,0);
    m=*st.begin();
    rep2(i,1,n) if(val[i]>=0) tree[val[i]].modify(l[i],r[i],1);
    rep(n){
        hldtree.modify(l[i],l[i],dep[i]-m);
    }
    rep(26) dfs3(0,i);
    while(q--){
        int x;
        char c;
        cin >> x >> c;
        if(sz(st)>=2){
            print("Fou");
            continue;
        }
        x--;
        if(val[x]>=0) sub(x,val[x]);
        if(c=='?') val[x]=-1;
        else val[x]=c-'a';
        if(val[x]>=0) add(x,val[x]);
        int res=0,tot=0;
        rep(26) tot+=tree[i].val[1];
        bug(tot,m);
        //bug(check(),check_naive());
        //rep(n) bug(i,hldtree.query(l[i],l[i]));
        if(!check()){
            print("Fou");
            continue;
        }
        print0("Shi");
        rep(26) res+=(i+1)*(tree[i].val[1]+m-tot);
        print(res);
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