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

const int maxn=300005,maxm=pow2(17),maxk=7777714;

//i_am_noob
#define wiwihorz  
void balbitorz(){}
int n,q,a[maxn],b[maxn],c[maxn],k,rt,l[maxn],r[maxn],par[maxn],minn[maxn],maxx[maxn];
vector<pii> segs,good;
vector<vector<int>> adj(maxn);
bool ok;
dsu<maxn> d;

void dfs(int u){
    bug(u);
    if(par[u]==-1) maxx[u]=inf;
    else maxx[u]=maxx[par[u]];
    if(b[u]) chkmin(maxx[u],b[u]);
    minn[u]=0;
    for(auto v: adj[u]) dfs(v),chkmax(minn[u],minn[v]);
    if(b[u]&&minn[u]>b[u]) ok=0;
    if(b[u]) minn[u]=b[u];
    bug(u,minn[u],maxx[u]);
    if(!b[u]) segs.pb({minn[u],maxx[u]});
}

void orzck(){
    cin >> n >> q;
    rep(n) adj[i].clear();
    segs.clear();
    good.clear();
    ok=1;
    d.init(n);
    rep(n) cin >> a[i];
    rep(n) cin >> b[i];
    vector<int> stk;
    stk.pb(-1);
    rep(n){
        while(stk.back()>=0&&a[i]>a[stk.back()]) stk.pop_back();
        l[i]=stk.back();
        stk.pb(i);
    }
    stk.clear();
    stk.pb(n);
    rep3(i,n-1,0){
        while(stk.back()<n&&a[i]>a[stk.back()]) stk.pop_back();
        r[i]=stk.back();
        stk.pb(i);
    }
    rep(n) bug(i,l[i],r[i]);
    rep(n){
        bug(i);
        par[i]=-1;
        if(l[i]>=0&&r[i]<=n-1){
            if(a[l[i]]<a[r[i]]) par[i]=l[i],adj[l[i]].pb(i);
            else par[i]=r[i],adj[r[i]].pb(i);
        }
        else if(l[i]>=0) par[i]=l[i],adj[l[i]].pb(i);
        else if(r[i]<=n-1) par[i]=r[i],adj[r[i]].pb(i);
        else rt=i;
        bug(rt);
    }
    dfs(rt);
    k=0;
    rep(n) if(!b[i]) k++;
    rep(k-1) cin >> c[i];
    assert(sz(segs)==k);
    for(auto [x,y]: segs) if(x>y) ok=0;
    if(!ok){
        while(q--){
            int de;
            cin >> de;
            print("NO");
        }
        return;
    }
    set<int> st;
    rep(k-1) st.insert(c[i]);
    sort(all(segs),[](pii p1, pii p2){return p1.second<p2.second;});
    for(auto [x,y]: segs){
        auto it=st.lower_bound(x);
        if(it!=st.end()&&*it<y) st.erase(it);
    }
    if(sz(st)){
        while(q--){
            int de;
            cin >> de;
            print("NO");
        }
        return;
    }
    set<pii> st2;//leftover
    st.clear();
    rep(k-1) st.insert(c[i]);
    rep(sz(segs)){
        auto [x,y]=segs[i];
        auto it=st.lower_bound(x);
        if(it!=st.end()&&*it<y){
            while(1){
                auto it2=st2.lower_bound({x,-1});
                if(it2!=st2.end()&&(*it2).first<*it){
                    d.Union((*it2).second,i);
                    st2.erase(it2);
                }
                else break;
            }
            st2.insert({*it,i});
            st.erase(it);
        }
        else{
            while(1){
                auto it2=st2.lower_bound({x,-1});
                if(it2!=st2.end()&&(*it2).first<y){
                    d.Union((*it2).second,i);
                    st2.erase(it2);
                }
                else break;
            }
            rep1(j,sz(segs)) if(d.Find(j)==d.Find(i)){
                good.pb(segs[j]);
            }
            break;
        }
    }
    vector<pii> uni;
    for(auto [x,y]: good){
        while(sz(uni)&&uni.back().second>=x){
            chkmin(x,uni.back().first);
            uni.pop_back();
        }
        uni.pb({x,y});
    }
    while(q--){
        int x;
        cin >> x;
        auto it=lower_bound(all(uni),pii(x+1,-1));
        if(it==uni.begin()){
            print("NO");
            continue;
        }
        it--;
        print((*it).second>x?"YES":"NO");
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