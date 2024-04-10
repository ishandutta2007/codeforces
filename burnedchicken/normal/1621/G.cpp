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
template<typename T, signed N>
struct BIT{
    T val[N];
    void modify(signed x, T y){for(signed i=++x; i<N; i+=i&-i) val[i]+=y;}
    T query(signed x, signed y){
        T ret=0;
        for(signed i=++y; i; i-=i&-i) ret+=val[i];
        for(signed i=x; i; i-=i&-i) ret-=val[i];
        return ret;
    }
    signed first_true(bool(*f)(T,signed)){
        if(f(0,0)) return 0;
        signed cur=0;
        T curval=0;
        for(signed i=__lg(N); i>=0; --i) if(cur+(1<<i)<N){
            if(!f(curval+val[cur+(1<<i)],cur+(1<<i))) cur+=1<<i,curval+=val[cur];
        }
        return min(cur,N-2);
    }
};
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
};
const int maxn=200005,maxm=2005,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,a[maxn],l[maxn];
bool good[maxn];
BIT<modint,maxn> bit;
modint val1[maxn],val2[maxn],res;
pair<int,modint> val3[maxn];

pair<int,modint> op(pair<int,modint> x, pair<int,modint> y){
    pair<int,modint> res(max(x.first,y.first),0);
    if(x.first==res.first) res.second+=x.second;
    if(y.first==res.first) res.second+=y.second;
    return res;
}
pair<int,modint> e(){return {-inf,0};}
segtree<pair<int,modint>,op,e,maxn> tree;

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    vector<int> vec;
    rep(n) vec.pb(a[i]);
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    rep(n) a[i]=lower_bound(all(vec),a[i])-vec.begin();
    rep(n+2) bit.val[i]=0;
    rep(n) val1[i]=val2[i]=0;
    rep(n){
        val1[i]=bit.query(0,a[i]-1)+1;
        bit.modify(a[i],val1[i]);
    }
    rep(n+2) bit.val[i]=0;
    rep3(i,n-1,0){
        val2[i]=bit.query(a[i]+1,n)+1;
        bit.modify(a[i],val2[i]);
    }
    rep(n+2) tree.modify(i,e());
    rep3(i,n-1,0){
        pair<int,modint> nval=tree.query(a[i]+1,n);
        if(nval.first<0) nval={i,1};
        val3[i]=nval;
        nval=op(nval,tree.query(a[i],a[i]));
        tree.modify(a[i],nval);
    }
    res=0;
    rep(n) res+=val1[i]*(val2[i]-val3[i].second);
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
    while(t--) orzck();
    return 0;
}