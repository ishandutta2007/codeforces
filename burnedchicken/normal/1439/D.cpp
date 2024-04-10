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
/*
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
*/
const int maxn=505,maxm=5005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,m,mod,fac[maxn],ifac[maxn];
inline int C(int n, int m){return m>n||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int dp1[maxn][2],dp[maxn][maxn][2];

void orzck(){
    cin >> n >> m >> mod;
    fac[0]=ifac[0]=ifac[1]=1;
    rep2(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep2(i,2,maxn) ifac[i]=ifac[mod%i]*(mod-mod/i)%mod;
    rep2(i,2,maxn) ifac[i]=ifac[i]*ifac[i-1]%mod;
    dp1[0][0]=1,dp1[0][1]=0;
    rep2(i,1,m+1){
        rep1(j,i){
            dp1[i][0]+=(i+1)*C(i-1,j)%mod*dp1[j][0]%mod*dp1[i-1-j][0];dp1[i][0]%=mod;
            dp1[i][1]+=dp1[j][0]*dp1[i-1-j][0]%mod*C(i-1,j)%mod*(j*(j+1)/2+(i-j-1)*(i-j)/2);dp1[i][1]%=mod;
            dp1[i][1]+=dp1[j][1]*dp1[i-1-j][0]%mod*C(i-1,j)%mod*(i+1);dp1[i][1]%=mod;
            dp1[i][1]+=dp1[i-1-j][1]*dp1[j][0]%mod*C(i-1,j)%mod*(i+1);dp1[i][1]%=mod;
        }
        bug(i,dp1[i][0],dp1[i][1]);
    }
    rep(n+1) rep1(j,i+1){
        if(j==0){
            dp[i][j][0]=1,dp[i][j][1]=0;
            continue;
        }
        if(i==j){
            dp[i][j][0]=dp1[i][0],dp[i][j][1]=dp1[i][1];
            continue;
        }
        dp[i][j][0]+=dp[i-1][j][0],dp[i][j][1]+=dp[i-1][j][1];
        rep2(k,1,j+1){
            int de=C(j,k);
            int tmp=(dp[i-k-1][j-k][1]*dp1[k][0]+dp[i-k-1][j-k][0]*dp1[k][1])%mod*de;
            dp[i][j][0]+=dp[i-k-1][j-k][0]*dp1[k][0]%mod*de;dp[i][j][0]%=mod;
            dp[i][j][1]=(dp[i][j][1]+tmp)%mod;
        }
    }
    print(dp[n][m][1]);
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