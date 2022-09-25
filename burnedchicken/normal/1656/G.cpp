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

const int maxn=200005,maxm=pow2(17),maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,a[maxn],b[maxn],to[maxn],pos[maxn][2],res[maxn];
dsu<maxn> d;

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    map<int,int> mm;
    rep(n) mm[a[i]]++;
    int de=0;
    for(auto& [x,y]: mm) if(y&1) de++;
    if(de>1){
        print("NO");
        return;
    }
    int x=-1;
    if(n&1){
        for(auto& [p,y]: mm) if(y&1){
            rep(n) if(a[i]==p&&i!=n/2){
                x=i;
                break;
            }
            if(x==-1){
                print("NO");
                return;
            }
            break;
        }
    }
    int cur=0;
    mm.clear();
    rep(n) if(i!=x){
        if(mm.count(a[i])){
            b[i]=b[mm[a[i]]];
            mm.erase(a[i]);
            to[i]=n-1-b[i];
            pos[b[i]][1]=i;
        }
        else{
            b[i]=cur++;
            mm[a[i]]=i;
            to[i]=b[i];
            pos[b[i]][0]=i;
        }
    }
    if(x!=-1) b[x]=n/2,to[x]=n/2,pos[n/2][0]=x;
    d.init(n);
    rep(n) d.Union(i,to[i]);
    set<int> st;
    rep(n/2){
        int x=d.Find(pos[i][0]),y=d.Find(pos[i][1]);
        if(x==y&&!st.count(x)) swap(to[pos[i][0]],to[pos[i][1]]),swap(pos[i][0],pos[i][1]);
        st.insert(x),st.insert(y);
    }
    d.init(n);
    rep(n) d.Union(i,to[i]);
    rep(n/2){
        if(i&&d.Find(pos[i][0])!=d.Find(pos[i-1][0])&&d.Find(pos[i][1])!=d.Find(pos[i-1][1])){
            assert(d.Find(pos[i][0])!=d.Find(pos[i][1]));
            d.Union(pos[i-1][0],pos[i][0]);
            d.Union(pos[i-1][1],pos[i][1]);
            swap(to[pos[i-1][0]],to[pos[i][0]]);
            swap(to[pos[i-1][1]],to[pos[i][1]]);
            swap(pos[i-1][0],pos[i][0]);
            swap(pos[i-1][1],pos[i][1]);
        }
        else if(d.Find(pos[i][0])!=d.Find(pos[i][1])){
            d.Union(pos[i][0],pos[i][1]);
            swap(to[pos[i][0]],to[pos[i][1]]);
            swap(pos[i][0],pos[i][1]);
        }
    }
    assert(d.siz[d.Find(0)]==n);
    rep(n) res[to[i]]=i+1;
    print("YES");
    rep(n) print0(res[i]);
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