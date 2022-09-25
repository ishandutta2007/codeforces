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

const int maxn=100005,maxm=5,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,a[maxn],b[maxn];

struct node{
    pii minn[2];
    node(){minn[0]={inf,inf},minn[1]={inf,inf};}
}tree[maxn*4];

node operator +(const node& n1, const node& n2){
    node res;
    res.minn[0]=min(n1.minn[0],n2.minn[0]);
    res.minn[1]=min(max(n1.minn[0],n2.minn[0]),min(n1.minn[1],n2.minn[1]));
    return res;
}

void pull(int k){
    tree[k]=tree[k<<1]+tree[k<<1|1];
    //minn[k][0]=min(minn[k<<1][0],minn[k<<1|1][0]);
    //minn[k][1]=min(max(minn[k<<1][0],minn[k<<1|1][0]),min(minn[k<<1][1],minn[k<<1|1][1]));
}

void build(int k, int l, int r){
    if(l==r){
        tree[k].minn[0]={a[l],l};
        tree[k].minn[1]={inf,inf};
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
    pull(k);
}

void modify(int k, int l, int r, int p, int x){
    if(l==r){
        tree[k].minn[0]={x,p};
        tree[k].minn[1]={inf,inf};
        return;
    }
    int mid=l+r>>1;
    if(p<=mid) modify(k<<1,l,mid,p,x);
    else modify(k<<1|1,mid+1,r,p,x);
    pull(k);
}

node query(int k, int l, int r, int ql, int qr){
    if(ql>r||qr<l) return node();
    if(ql<=l&&qr>=r) return tree[k];
    int mid=l+r>>1;
    return query(k<<1,l,mid,ql,qr)+query(k<<1|1,mid+1,r,ql,qr);
}

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) b[i]=a[i];
    build(1,0,n-1);
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        vector<int> vec;
        while(1){
            auto de=query(1,0,n-1,l,r);
            //bug(de.minn[0].first,de.minn[1].first);
            if(de.minn[0].first==de.minn[1].first){
                print(de.minn[0].first);
                break;
            }
            int x=de.minn[0].first^de.minn[1].first;
            int p=de.minn[0].second;
            vec.pb(p);
            b[p]^=pow2(__lg(x));
            modify(1,0,n-1,p,b[p]);
            //bug(p,b[p]);
        }
        for(auto i: vec) modify(1,0,n-1,i,a[i]),b[i]=a[i];
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