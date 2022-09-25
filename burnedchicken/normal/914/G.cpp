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

const int maxn=100005,maxm=pow2(17),maxk=7777714;

const int K=17;
using poly=array<modint,1<<K>;

void fwht_xor(poly& P, bool rev=0){
    rep1(k,K) for(int i=0; i<pow2(K); i+=pow2(k+1)) rep1(j,pow2(k)){
        modint tmp=P[i+j+pow2(k)];
        P[i+j+pow2(k)]=P[i+j]-tmp;
        P[i+j]+=tmp;
    }
    modint invn=modint(1<<K).inv();
    if(rev) rep(1<<K) P[i]*=invn;
}
void sos(poly& P){rep1(k,K) for(int i=0; i<pow2(K); i+=pow2(k+1)) rep1(j,pow2(k)) P[i+j+pow2(k)]+=P[i+j];}
void sos_rev(poly& P){rep1(k,K) for(int i=0; i<pow2(K); i+=pow2(k+1)) rep1(j,pow2(k)) P[i+j+pow2(k)]-=P[i+j];}
void fwht_and(poly& P){rep1(k,K) for(int i=0; i<pow2(K); i+=pow2(k+1)) rep1(j,pow2(k)) P[i+j]+=P[i+j+pow2(k)];}
void fwht_and_rev(poly& P){rep1(k,K) for(int i=0; i<pow2(K); i+=pow2(k+1)) rep1(j,pow2(k)) P[i+j]-=P[i+j+pow2(k)];}
poly add(poly P, poly Q){
    poly R;
    rep(1<<K) R[i]=P[i]+Q[i];
    return R;
}
poly mul_term(poly P, poly Q){
    poly R;
    rep(1<<K) R[i]=P[i]*Q[i];
    return R;
}
poly mul_xor(poly P, poly Q){
    fwht_xor(P),fwht_xor(Q);
    poly R=mul_term(P,Q);
    fwht_xor(R,1);
    return R;
}
poly mul_and(poly P, poly Q){
    fwht_and(P),fwht_and(Q);
    poly R=mul_term(P,Q);
    fwht_and_rev(R);
    return R;
}
poly subset_conv(poly P, poly Q){
    poly f[K+1],g[K+1];
    rep(1<<K){
        int x=__builtin_popcountll(i);
        f[x][i]=P[i],g[x][i]=Q[i];
    }
    rep(K+1) sos(f[i]),sos(g[i]);
    poly res;
    rep(K+1){
        poly h;
        rep1(j,i+1) h=add(h,mul_term(f[j],g[i-j]));
        sos_rev(h);
        rep1(j,1<<K) if(__builtin_popcountll(j)==i) res[j]=h[j];
    }
    return res;
}

//i_am_noob
//#define wiwihorz  
int n;
modint f[1<<17];
poly a,p1,p2;

void orzck(){
    cin >> n;
    rep(n){
        int x;
        cin >> x;
        a[x]+=1;
    }
    f[0]=0,f[1]=1;
    rep2(i,2,1<<17) f[i]=f[i-2]+f[i-1];
    p1=mul_xor(a,a);
    rep(1<<17) p1[i]*=f[i];
    p2=a;
    rep(1<<17) p2[i]*=f[i];
    p1=mul_and(p1,p2);
    p2=subset_conv(a,a);
    rep(1<<17) p2[i]*=f[i];
    p1=mul_and(p1,p2);
    modint res;
    rep(1<<17) if(i&&(i&i-1)==0) res+=p1[i];
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