#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

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
#define bug(...) 826
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

const int maxn=200005;

//i_am_noob
//#define wiwihorz  

int n,a[15],pw3[15];
modint prob[15][15],res,dp[20000];
vector<modint> vec[20000];
vector<int> tar[20000];

modint solve(int x){
    rep(pow2(n)) dp[i]=1;
    bug(x);
    rep1(mask1,pow2(n)) if(mask1&pow2(x)){
        vector<int> vec1;
        rep(n) if(!(mask1&pow2(i))) vec1.pb(i);
        rep1(mask2,pow2(sz(vec1))) if(mask2){
            dp[tar[mask1][mask2]]-=dp[mask1]*vec[mask1][mask2];
        }
    }
    bug(dp[pow2(n)-1]);
    return dp[pow2(n)-1];
}

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) rep1(j,n) if(i!=j) prob[i][j]=a[i]*(modint(a[i]+a[j]).inv());
    pw3[0]=1;
    rep2(i,1,n+1) pw3[i]=pw3[i-1]*3;
    bug(pow2(n));
    rep1(mask1,pow2(n)){
        vector<int> vec1;
        rep(n) if(!(mask1&pow2(i))) vec1.pb(i);
        rep1(mask2,pow2(sz(vec1))){
            bool flag=0;
            rep(sz(vec1)) if(mask2&pow2(i)){
                modint x=1;
                rep1(j,n) if(mask1&pow2(j)) x*=prob[vec1[i]][j];
                vec[mask1].pb(vec[mask1][mask2^pow2(i)]*x);
                flag=1;
                break;
            }
            int k=mask1;
            rep(sz(vec1)) if(mask2&pow2(i)) k^=pow2(vec1[i]);
            tar[mask1].pb(k);
            if(!flag) vec[mask1].pb(1);
            //bug(mask1,mask2,vec[mask1][mask2],tar[mask1][mask2]);
        }
    }
    /*
    rep1(mask,pw3[n]){
        array<int,15> arr;
        int tmp=mask;
        rep(n){
            arr[i]=tmp%3;
            tmp/=3;
        }
        bool flag=0;
        rep(n) if(arr[i]==2){
            modint x=1;
            rep1(j,n) if(arr[j]==1) x*=prob[i][j];
            val[mask]=val[mask-2*pw3[i]]*x;
            flag=1;
            break;
        }
        if(!flag) val[mask]=1;
    }
    */
    rep(n){
        res+=solve(i);
        bug(i);
    }
    print(res);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
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