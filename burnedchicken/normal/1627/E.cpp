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
int n,m,k,x[maxn],dis[maxn*2],ndis[maxn*2];
vector<vector<int>> vec;
vector<vector<pii>> adj;
vector<array<int,5>> edges;
vector<pii> nodes;

inline int find_id(int x, int y){return lower_bound(all(nodes),pii(x,y))-nodes.begin();}

void orzck(){
    cin >> n >> m >> k;
    vec.resize(n);
    rep(n) vec[i].clear();
    rep(n) cin >> x[i];
    nodes.clear();
    edges.clear();
    rep(k){
        int a,b,c,d,h;
        cin >> a >> b >> c >> d >> h;
        a--,b--,c--,d--;
        edges.pb({a,b,c,d,h});
        nodes.pb({a,b}),nodes.pb({c,d});
    }
    nodes.pb({0,0}),nodes.pb({n-1,m-1});
    sort(all(nodes));
    nodes.resize(unique(all(nodes))-nodes.begin());
    adj.resize(sz(nodes));
    rep(sz(nodes)) adj[i].clear(),dis[i]=inf,ndis[i]=inf;
    for(auto& [x,y]: nodes) vec[x].pb(y);
    for(auto& arr: edges){
        int u=find_id(arr[0],arr[1]),v=find_id(arr[2],arr[3]);
        adj[u].pb({v,arr[4]});
    }
    dis[0]=0;
    rep(n) if(sz(vec[i])){
        int l=find_id(i,vec[i][0]),r=find_id(i,vec[i].back())+1;
        bug(i,l,r);
        rep2(j,l,r) bug(nodes[j].first,nodes[j].second,dis[j]);
        rep2(j,l,r) ndis[j]=dis[j];
        int cur=inf;
        rep2(j,l,r){
            if(j>l){
                int d=nodes[j].second-nodes[j-1].second;
                chkmin(ndis[j],cur+x[i]*d);
                cur+=d*x[i];
            }
            chkmin(cur,dis[j]);
        }
        cur=inf;
        rep3(j,r-1,l){
            if(j<r-1){
                int d=nodes[j+1].second-nodes[j].second;
                bug(cur,d);
                chkmin(ndis[j],cur+x[i]*d);
                cur+=d*x[i];
            }
            chkmin(cur,dis[j]);
        }
        rep2(j,l,r) bug(nodes[j].first,nodes[j].second,dis[j]);
        rep2(j,l,r) chkmin(dis[j],ndis[j]);
        rep2(j,l,r) bug(nodes[j].first,nodes[j].second,dis[j]);
        rep2(j,l,r) for(auto [v,w]: adj[j]) chkmin(dis[v],dis[j]-w),bug(j,v,w);
        rep2(j,l,r) bug(nodes[j].first,nodes[j].second,dis[j]);
    }
    if(dis[sz(nodes)-1]>1e16) print("NO ESCAPE");
    else print(dis[sz(nodes)-1]);
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