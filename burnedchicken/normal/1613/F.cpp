#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

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

template <typename T>
struct FFT{
    int siz;
    vector<T> rt,rev_rt;
    T inv_siz;
    FFT(int _siz){
        siz=_siz;
        T x=T(3).Pow((MOD-1)>>_siz);
        rep(pow2(_siz)) rt.pb(i?rt.back()*x:T(1));
        rep(pow2(_siz)) rev_rt.pb(i?rt[pow2(_siz)-i]:T(1));
        inv_siz=T(pow2(siz)).inv();
    }
    void mul_matrix(vector<T>& vec, vector<T>& RT){
        vec.resize(pow2(siz));
        int rev=0;
        rep(pow2(siz)){
            if(i>rev) swap(vec[i],vec[rev]);
            for(int j=pow2(siz-1); (rev^=j)<j; j>>=1);
        }
        T tmp;
        rep2(layer,1,siz+1) for(int i=0; i<pow2(siz); i+=pow2(layer)) for(int j=i; j<i+pow2(layer-1); j++){
            tmp=RT[(j-i)<<(siz-layer)]*vec[j+pow2(layer-1)];
            vec[j+pow2(layer-1)]=vec[j]-tmp;
            vec[j]=vec[j]+tmp;
        }
    }
    void sqr(vector<T>& vec, vector<T>& ans){
        mul_matrix(vec,rt);
        ans.resize(pow2(siz));
        rep(pow2(siz)) ans[i]=vec[i]*vec[i];
        mul_matrix(ans,rev_rt);
        rep(pow2(siz)) ans[i]=ans[i]*inv_siz;
    }
    void mul(vector<T>& vec1, vector<T>& vec2, vector<T>& ans){
        mul_matrix(vec1,rt),mul_matrix(vec2,rt);
        ans.resize(pow2(siz));
        rep(pow2(siz)) ans[i]=vec1[i]*vec2[i];
        mul_matrix(ans,rev_rt);
        rep(pow2(siz)) ans[i]=ans[i]*inv_siz;
    }
};
const int maxn=250005,maxm=10000005,maxk=7777714;
    
//i_am_noob
//#define wiwihorz  
int n,c[maxn],cnt[maxn],dp[maxn],ndp[maxn];

vector<modint> solve(int l, int r){
    if(l==r){
        vector<modint> res={1,c[l]};
        return res;
    }
    int mid=l+r>>1;
    vector<modint> vec1=solve(l,mid),vec2=solve(mid+1,r);
    FFT<modint> fft(__lg(r-l+1)+1);
    vector<modint> res;
    fft.mul(vec1,vec2,res);
    //bug(l,r);
    //for(auto i: res) bug(i);
    return res;
}

void orzck(){
    init_comb(maxn);
    cin >> n;
    rep(n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        c[u]++,c[v]++;
    }
    rep2(i,1,n) c[i]--;
    rep(n) bug(c[i]);
    rep(n) cnt[c[i]]++;
    vector<modint> vec=solve(0,n-1);
    modint res=0;
    rep(n+1) res+=vec[i]*fac[n-i]*(i&1?-1:1),bug(vec[i]);
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