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

template<int maxn>
struct NT{
    vector<int> pr;
    int lpd[maxn];
    NT(){
        pr.clear();
        rep(maxn) lpd[i]=-1;
        rep2(i,2,maxn){
            if(lpd[i]==-1) lpd[i]=i,pr.pb(i);
            for(auto p: pr){
                if(p*i>=maxn) break;
                lpd[p*i]=p;
                if(i%p==0) break;
            }
        }
    }
    inline bool isp(int x){return lpd[x]==x;}
    int fac_cnt(int x){
        assert(x>=1&&x<maxn);
        int res=1,lst=0,cur=0;
        while(x>1){
            int p=lpd[x];
            if(p!=lst) res*=cur+1,cur=0;
            cur++;
            lst=p;
            x/=p;
        }
        return res*(cur+1);
    }
    vector<int> pfactors(int x){
        assert(x>=1&&x<maxn);
        vector<int> res;
        while(x>1){
            res.pb(lpd[x]);
            x/=lpd[x];
        }
        return res;
    }
};

const int maxn=200005,maxm=1000005,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,dep[maxn],l[maxn],r[maxn],curt;
vector<vector<int>> adj;
vector<array<int,4>> edges;
NT<maxn> nt;

void dfs(int u, int par){
    dep[u]=par==-1?0:dep[par]+1;
    l[u]=curt++;
    for(auto v: adj[u]) if(v!=par) dfs(v,u);
    r[u]=curt-1;
}

vector<vector<array<int,3>>> vec;

modint de[maxn];

void solve(vector<array<int,3>> vec1, int p){
    vector<int> vals;
    for(auto& arr: vec1) vals.pb(arr[0]),vals.pb(arr[1]);
    //vals.pb(0);
    sort(all(vals));
    vals.resize(unique(all(vals))-vals.begin());
    for(auto& arr: vec1){
        arr[0]=lower_bound(all(vals),arr[0])-vals.begin();
        arr[1]=lower_bound(all(vals),arr[1])-vals.begin();
    }
    bug(p);
    vector<int> pre(sz(vals));
    bug(sz(vals));
    for(auto& arr: vec1) pre[arr[0]]+=arr[2],pre[arr[1]]-=arr[2];
    int minn=inf,cur=0;
    for(auto i: pre){
        cur+=i;
        chkmin(minn,cur);
    }
    de[0]*=modint(p).Pow(MOD-1-minn);
    rep(sz(vals)) de[vals[i]]*=modint(p).Pow(MOD-1+pre[i]);
}

void orzck(){
    curt=0;
    cin >> n;
    adj.resize(n);
    rep(n) adj[i].clear();
    edges.clear();
    vec.resize(n+1);
    rep(n+1) vec[i].clear();
    rep(n+1) de[i]=1;
    rep(n-1){
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        u--,v--;
        edges.pb({u,v,x,y});
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(0,-1);
    rep(n-1){
        array<int,4> e=edges[i];
        if(dep[e[0]]>dep[e[1]]) swap(e[0],e[1]),swap(e[2],e[3]);
        vector<int> factors=nt.pfactors(e[2]);
        for(auto p: factors) vec[p].pb({l[e[1]],r[e[1]]+1,-1});
        factors=nt.pfactors(e[3]);
        for(auto p: factors) vec[p].pb({l[e[1]],r[e[1]]+1,1});
    }
    rep(n+1) if(sz(vec[i])){
        solve(vec[i],i);
    }
    rep2(i,1,n) de[i]*=de[i-1];
    modint res=0;
    rep(n) res+=de[i],bug(de[i]);
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

/*
modint val[maxn*4],tag[maxn*4];

void pull(int k){val[k]=val[k<<1]+val[k<<1|1];}

void push(int k, int l, int r){
    if(l!=r){
        val[k<<1]*=tag[k];
        val[k<<1|1]*=tag[k];
        tag[k<<1]*=tag[k];
        tag[k<<1|1]*=tag[k];
    }
    tag[k]=1;
}

void build(int k, int l, int r){
    val[k]=1,tag[k]=1;
    if(l==r){
        val[k]=1,tag[k]=1;
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}

void modify(int k, int l, int r, int ql, int qr, modint x){
    if(l>qr||r<ql) return;
    if(ql<=l&&qr>=r){
        val[k]*=x;
        tag[k]*=x;
        return;
    }
    push(k,l,r);
    int mid=l+r>>1;
    modify(k<<1,l,mid,ql,qr,x),modify(k<<1|1,mid+1,r,ql,qr,x);
    pull(k);
}
*/