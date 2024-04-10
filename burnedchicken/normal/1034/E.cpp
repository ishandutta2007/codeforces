#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;


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

const int maxn=pow2(21),maxm=pow2(17),maxk=7777714;

//i_am_noob
//#define wiwihorz  
using u64=unsigned long long;
int n;

u64 p[22][2][1<<15],q[22][2][1<<15];

void sos(u64 f[2][1<<15]){
    rep(6){
        u64 de=0;
        rep1(j,64) if(!(j>>i&1)) de^=1ull<<j;
        rep1(j,pow2(15)) f[1][j]^=(f[1][j]&de)<<(1<<i);
        rep1(j,pow2(15)) f[1][j]^=(f[0][j]&(f[0][j]>>(1<<i))&de)<<(1<<i);
        rep1(j,pow2(15)) f[0][j]^=(f[0][j]&de)<<(1<<i);
    }
    rep2(i,6,21){
        for(int j=0; j<pow2(15); j+=pow2(i-5)) rep2(k,j,j+pow2(i-6)){
            f[1][k+pow2(i-6)]^=f[1][k];
            f[1][k+pow2(i-6)]^=f[0][k]&f[0][k+pow2(i-6)];
            f[0][k+pow2(i-6)]^=f[0][k];
        }
    }
}

void inv_sos(u64 f[2][1<<15]){
    rep(6){
        u64 de=0;
        rep1(j,64) if(!(j>>i&1)) de^=1ull<<j;
        rep1(j,pow2(15)) f[1][j]^=(f[1][j]&de)<<(1<<i);
        rep1(j,pow2(15)) f[1][j]^=(f[0][j]&(~(f[0][j]>>(1<<i)))&de)<<(1<<i);
        rep1(j,pow2(15)) f[0][j]^=(f[0][j]&de)<<(1<<i);
    }
    rep2(i,6,21){
        for(int j=0; j<pow2(15); j+=pow2(i-5)) rep2(k,j,j+pow2(i-6)){
            f[1][k+pow2(i-6)]^=f[0][k]&(~f[0][k+pow2(i-6)]);
            f[1][k+pow2(i-6)]^=f[1][k];
            f[0][k+pow2(i-6)]^=f[0][k];
        }
    }
}

u64 a[2][1<<15],b[2][1<<15],c[2][1<<15];

void solve(u64 f[2][1<<15], u64 g[2][1<<15]){
    u64 res[2][1<<15];
    rep(2) memset(res[i],0,sizeof res[i]);
    rep(pow2(n)){
        int x=__builtin_popcountll(i);
        rep1(j,2) p[x][j][i>>6]^=f[j][i>>6]&(1ull<<(i&63)),q[x][j][i>>6]^=g[j][i>>6]&(1ull<<(i&63));
    }
    rep(n+1) sos(p[i]),sos(q[i]);
    rep(n+1){
        u64 h[2][1<<15];
        rep1(j,2) memset(h[j],0,sizeof h[j]);
        rep1(j,i+1){
            rep1(k,pow2(15)) h[1][k]^=h[0][k]&p[j][0][k]&q[i-j][0][k];
            rep1(k,pow2(15)) h[0][k]^=p[j][0][k]&q[i-j][0][k];
            rep1(k,pow2(15)) h[1][k]^=p[j][1][k]&q[i-j][0][k];
            rep1(k,pow2(15)) h[1][k]^=p[j][0][k]&q[i-j][1][k];
        }
        inv_sos(h);
        rep1(j,pow2(n)) if(__builtin_popcountll(j)==i) rep1(k,2) c[k][j>>6]^=h[k][j>>6]&(1ull<<(j&63));
    }
}

void orzck(){
    cin >> n;
    rep(pow2(n)){
        char ch;
        cin >> ch;
        if(ch&1) a[0][i>>6]^=1ull<<(i&63);
        if(ch&2) a[1][i>>6]^=1ull<<(i&63);
    }
    rep(pow2(n)){
        char ch;
        cin >> ch;
        if(ch&1) b[0][i>>6]^=1ull<<(i&63);
        if(ch&2) b[1][i>>6]^=1ull<<(i&63);
    }
    solve(a,b);
    rep(pow2(n)){
        int x=0;
        if(c[0][i>>6]>>(i&63)&1) x++;
        if(c[1][i>>6]>>(i&63)&1) x+=2;
        cout << x;
    }
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