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
const int maxn=100005,maxm=5005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,m,cnt[maxn*2],sum[maxn];
set<pii> adj[maxn],st,st1;
vector<array<int,3>> edges;
map<pii,int> mm;

void add_edge(int u, int v, int w, int id){
    auto it=adj[u].begin();
    rep1(_,3){
        if(it==adj[u].end()){
            break;
        }
        auto p=*it;
        if(cnt[p.second]==2) st.erase(p);
        cnt[p.second]--;
        it++;
    }
    st1.erase({sum[u],u});
    adj[u].insert({w,id});
    it=adj[u].begin();
    sum[u]=0;
    rep1(_,3){
        if(it==adj[u].end()){
            sum[u]=inf;
            break;
        }
        auto p=*it;
        cnt[p.second]++;
        if(cnt[p.second]==2) st.insert(p);
        sum[u]+=p.first;
        it++;
    }
    st1.insert({sum[u],u});
}

void del_edge(int u, int v, int w, int id){
    auto it=adj[u].begin();
    rep1(_,3){
        if(it==adj[u].end()){
            break;
        }
        auto p=*it;
        if(cnt[p.second]==2) st.erase(p);
        cnt[p.second]--;
        it++;
    }
    st1.erase({sum[u],u});
    adj[u].erase({w,id});
    it=adj[u].begin();
    sum[u]=0;
    rep1(_,3){
        if(it==adj[u].end()){
            sum[u]=inf;
            break;
        }
        auto p=*it;
        cnt[p.second]++;
        if(cnt[p.second]==2) st.insert(p);
        sum[u]+=p.first;
        it++;
    }
    st1.insert({sum[u],u});
}

void add_edge(int id){
    add_edge(edges[id][0],edges[id][1],edges[id][2],id);
    add_edge(edges[id][1],edges[id][0],edges[id][2],id);
    mm[{edges[id][0],edges[id][1]}]=id;
}

void del_edge(int id){
    del_edge(edges[id][0],edges[id][1],edges[id][2],id);
    del_edge(edges[id][1],edges[id][0],edges[id][2],id);
    mm.erase({edges[id][0],edges[id][1]});
}

bool good(int id1, int id2){
    int u1=edges[id1][0],v1=edges[id1][1];
    int u2=edges[id2][0],v2=edges[id2][1];
    return u1!=u2&&u1!=v2&&v1!=u2&&v1!=v2;
}

void solve(){
    int res=(*st1.begin()).first;
    bug(res);
    vector<pii> vec;
    bug(sz(st));
    for(auto p: st){
        bool flag=1;
        for(auto p2: vec){
            if(good(p.second,p2.second)){
                bug(p.second,p2.second);
                chkmin(res,p.first+p2.first);
                break;
            }
            flag=0;
        }
        if(sz(vec)&&flag) break;
        vec.pb(p);
    }
    print(res);
}

void orzck(){
    cin >> n >> m;
    rep(n) st1.insert({inf,i});
    rep(m){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        if(u>v) swap(u,v);
        edges.pb({u,v,w});
        add_edge(i);
    }
    solve();
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            int u,v;
            cin >> u >> v;
            u--,v--;
            if(u>v) swap(u,v);
            del_edge(mm[{u,v}]);
        }
        else{
            int u,v,w;
            cin >> u >> v >> w;
            u--,v--;
            if(u>v) swap(u,v);
            edges.pb({u,v,w});
            add_edge(sz(edges)-1);
        }
        solve();
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