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

const int maxn=200005,maxm=16,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,q,a[maxn],b[maxn],sum[maxn],res[maxn];
pii op(pii x, pii y){
    return {(x.first+y.first)%MOD,(x.second+y.second)%MOD};
}
pii e(){return pii(0,0);}

segtree<pii,op,e,maxn> pos,neg;

array<int,3> query[maxn];
vector<vector<array<int,3>>> vec(maxn);
pii de[maxn];

void orzck(){
    cin >> n >> q;
    rep(n) cin >> a[i];
    rep(n) cin >> b[i];
    sum[0]=0;
    rep(n) sum[i+1]=sum[i]+b[i];
    rep(q) cin >> query[i][0] >> query[i][1];
    rep(q) query[i][0]--,query[i][1]--;
    rep(q) query[i][2]=i;
    rep(q) vec[query[i][0]].pb(query[i]);
    vector<pii> vals;
    rep(n) vals.pb({sum[i],i});
    sort(all(vals));
    rep(n-1) de[i]={(a[i+1]-a[i])%MOD,(sum[i+1]%MOD*(a[i+1]-a[i])%MOD+MOD)%MOD};
    rep(n-1) pos.modify(i,de[i]);
    for(auto& [x,i]: vals){
        bug(x,i);
        for(auto& arr: vec[i]){
            int l=arr[0],r=arr[1],id=arr[2];
            bug(l,r,id);
            auto valp=pos.query(l,r-1),valn=neg.query(l,r-1);
            res[id]=0;
            res[id]+=valp.second-valp.first*(x%MOD);
            res[id]-=valn.second-valn.first*(x%MOD);
            res[id]=(res[id]%MOD+MOD)%MOD;
        }
        if(i){
            pos.modify(i-1,e());
            neg.modify(i-1,de[i-1]);
        }
    }
    rep(q) print(res[i]);
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