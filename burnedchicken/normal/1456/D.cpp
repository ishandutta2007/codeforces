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
const int maxn=5005,maxm=5,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,t[maxn],x[maxn];
bool dp1[maxn];//consider i, not use clone for i
bool dp2[maxn];//consider i, use clone for i, cloned i before i-1 pops
int dp3[maxn];//consider i, use clone for i, clone i after i-1 pops, clone i as early as possible

void orzck(){
    cin >> n;
    rep(n) cin >> t[i] >> x[i];
    if(abs(x[0])>t[0]){
        print("NO");
        return;
    }
    dp1[0]=1;
    dp2[0]=0;
    dp3[0]=abs(x[0]);
    rep2(i,1,n){
        dp1[i]=0;
        if(dp1[i-1]&&abs(x[i]-x[i-1])<=t[i]-t[i-1]) dp1[i]=1;
        if(dp2[i-1]&&abs(x[i]-x[i-2])<=t[i]-t[i-2]) dp1[i]=1;
        if(abs(x[i]-x[i-1])<=t[i]-dp3[i-1]) dp1[i]=1;
        dp2[i]=0;
        bool flag=1;
        rep3(j,i-2,0){
            if(dp2[j]&&abs(x[j+1]-x[i])<=t[j+1]-t[j]&&abs(x[j+1]-x[i])+abs(x[j-1]-x[i])<=t[j+1]-t[j-1]) dp2[i]=1;
            if(abs(x[j+1]-x[i])<=t[j+1]-t[j]&&abs(x[j]-x[i])+abs(x[j+1]-x[i])<=t[j+1]-dp3[j]) dp2[i]=1;
            if(abs(x[j+1]-x[j])>t[j+1]-t[j]){
                flag=0;
                break;
            }
        }
        if(flag&&abs(x[i])+abs(x[0]-x[i])<=t[0]) dp2[i]=1;
        dp3[i]=inf;
        if(dp1[i-1]&&abs(x[i]-x[i-1])<=t[i]-t[i-1]) dp3[i]=t[i-1]+abs(x[i]-x[i-1]);
        if(dp2[i-1]&&abs(x[i]-x[i-2])<=t[i]-t[i-2]) chkmin(dp3[i],max(t[i-1],t[i-2]+abs(x[i]-x[i-2])));
        if(abs(x[i]-x[i-1])<=t[i]-dp3[i-1]) chkmin(dp3[i],max(t[i-1],dp3[i-1]+abs(x[i]-x[i-1])));
    }
    if(dp1[n-1]||dp2[n-1]||dp3[n-1]<=t[n-1]) print("YES");
    else print("NO");
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