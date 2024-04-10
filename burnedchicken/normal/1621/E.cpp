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
const int maxn=100005,maxm=2005,maxk=7777714;

//i_am_noob
#define wiwihorz  
int n,m,a[maxn],sum[maxn],id[maxn];
vector<int> vec[maxn];
bool b[maxn],b1[maxn],b2[maxn];
//b: possible now b1: possble if push right b2: possible if push left
vector<int> v,v1,v2;
string res[maxn];

void orzck(){
    cin >> n >> m;
    rep(n) cin >> a[i];
    sort(a,a+n);
    rep(m){
        int k;
        cin >> k;
        vec[i].resize(k),sum[i]=0;
        for(auto& j: vec[i]) cin >> j;
        for(auto j: vec[i]) sum[i]+=j;
    }
    rep(m) id[i]=i;
    sort(id,id+m,[](int i, int j){return sum[i]*sz(vec[j])>sum[j]*sz(vec[i]);});
    vector<int> vals;
    rep(m) vals.pb(ceiling(sum[id[i]],sz(vec[id[i]])));
    rep(m) b[i]=b1[i]=b2[i]=0,res[i].clear();
    v.clear(),v1.clear(),v2.clear();
    rep(m){
        int x=lower_bound(a,a+n,vals[i])-a;
        x=n-x;
        if(x>=i+1) b[i]=1;
        else v.pb(i);
        if(x>=i+2) b1[i]=1;
        else v1.pb(i);
        if(x>=i) b2[i]=1;
        else v2.pb(i);
    }
    rep(m){
        for(auto j: vec[id[i]]){
            int nval=ceiling(sum[id[i]]-j,sz(vec[id[i]])-1);
            if(nval==vals[i]){
                if(sz(v)) res[id[i]]+='0';
                else res[id[i]]+='1';
                continue;
            }
            int npos=i;
            bug(j,npos);
            bool flag=1;
            if(nval>vals[i]){
                npos=lower_bound(all(vals),nval,greater<int>())-vals.begin();
                if(a[n-1-npos]<nval) flag=0;
                if(lower_bound(all(v),npos)!=lower_bound(all(v),0)) flag=0;
                if(lower_bound(all(v1),i)!=lower_bound(all(v1),npos)) flag=0;
                if(lower_bound(all(v),n)!=lower_bound(all(v),i+1)) flag=0;
                res[id[i]]+=(flag?'1':'0');
            }
            else{
                npos=upper_bound(all(vals),nval,greater<int>())-vals.begin()-1;
                if(a[n-1-npos]<nval) flag=0;
                if(lower_bound(all(v),i)!=lower_bound(all(v),0)) flag=0;
                if(lower_bound(all(v2),npos+1)!=lower_bound(all(v2),i+1)) flag=0;
                if(lower_bound(all(v),n)!=lower_bound(all(v),npos+1)) flag=0;
                res[id[i]]+=(flag?'1':'0');
            }
        }
    }
    rep(m) cout << res[i];
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
    while(t--) orzck();
    return 0;
}