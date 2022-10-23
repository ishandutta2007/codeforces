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
#define eb emplace_back
#define sort_unique(a) sort(all(a)),a.resize(unique(all(a))-a.begin())
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

const int maxn=1000005,maxm=pow2(17),maxk=7777714;

//i_am_noob
//#define wiwihorz  
void balbitorz(){}
int n,K,b,p,m,a[49],sum[49],mul[49];
vector<int> vec[49],par_sum[49],poss;

void dfs(int x, int mask){
    if(x==K){
        poss.pb(mask);
        return;
    }
    dfs(x+1,mask);
    bool flag=1;
    rep(x) if(a[i]>=a[x]&&!(mask>>i&1)) flag=0;
    if(flag) dfs(x+1,mask|pow2(x));
}

void orzck(){
    cin >> n >> b >> p >> m;
    K=0;
    rep(n){
        char c;
        int x;
        cin >> c >> x;
        if(c=='+') vec[K].pb(x);
        else if(x>1) a[K++]=x;
    }
    rep(K+1) sort(all(vec[i]));
    rep(K+1){
        par_sum[i].resize(sz(vec[i])+1);
        par_sum[i][sz(vec[i])]=0;
        rep3(j,sz(vec[i])-1,0) par_sum[i][j]=par_sum[i][j+1]+vec[i][j];
    }
    rep(K+1) sum[i]=accumulate(all(vec[i]),0ll);
    sum[0]++;
    dfs(0,0);
    int res=-1;
    for(auto mask: poss){
        bug(mask);
        mul[K]=1;
        rep(K) if(mask>>i&1) mul[K]*=a[i];
        rep3(i,K-1,0){
            if(mask>>i&1) mul[i]=mul[i+1];
            else mul[i]=mul[i+1]*a[i];
        }
        int cntm=__builtin_popcountll(mask);
        if(cntm*m>b) continue;
        int cntp=(b-cntm*m)/p;
        int tot=0;
        rep(K+1) tot+=sum[i]*mul[i];
        int l=0,r=inf;
        while(l<r){
            int mid=l+r>>1;
            int choose=0;
            rep(K+1) if(mul[0]-mul[i]>0){
                int tar=ceiling(mid,mul[0]-mul[i]);
                choose+=sz(vec[i])-(lower_bound(all(vec[i]),tar)-vec[i].begin());
            }
            if(choose<=cntp) r=mid;
            else l=mid+1;
        }
        bug(cntp,l);
        int real_choose=0;
        rep(K+1) if(mul[0]-mul[i]>0){
            int tar=ceiling(l,mul[0]-mul[i]);
            int id=(lower_bound(all(vec[i]),tar)-vec[i].begin());
            real_choose+=sz(vec[i])-id;
            bug(i,id);
            tot+=par_sum[i][id]*(mul[0]-mul[i]);
        }
        if(real_choose<cntp&&l>0) tot+=(cntp-real_choose)*(l-1);
        chkmax(res,tot);
    }
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
    ld start=clock();
    balbitorz();
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}