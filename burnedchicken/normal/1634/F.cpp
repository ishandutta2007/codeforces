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

const int maxn=300005,maxm=16,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,a[maxn],q,mod,f[maxn];
pii val[maxn*4],tag[maxn*4];

int add(int x, int y){
    x+=y;
    if(x>=mod) x-=mod;
    return x;
}

int get_fib(pii p, int t){
    if(t==1) return p.first;
    if(t==2) return p.second;
    return (p.first*f[t-2]+p.second*f[t-1])%mod;
}

void pull(int k, int l, int r){
    if(val[k<<1].first==-1||val[k<<1|1].first==-1) val[k]={-1,-1};
    else if(val[k<<1].second==-1&&val[k<<1|1].second==-1) val[k]={val[k<<1].first,val[k<<1|1].first};
    else if(val[k<<1].second==-1){
        if(val[k<<1|1].second==add(val[k<<1].first,val[k<<1|1].first)) val[k]={val[k<<1].first,val[k<<1|1].first};
        else val[k]={-1,-1};
    }
    else if(val[k<<1|1].second==-1){
        if(val[k<<1|1].first==add(val[k<<1].first,val[k<<1].second)) val[k]=val[k<<1];
        else val[k]={-1,-1};
    }
    else{
        int t=(l+r>>1)-l+1;
        if(val[k<<1|1].first!=get_fib(val[k<<1],t+1)) val[k]={-1,-1};
        else if(val[k<<1|1].second!=get_fib(val[k<<1],t+2)) val[k]={-1,-1};
        else val[k]=val[k<<1];
    }
}

void build(int k, int l, int r){
    if(l==r){
        val[k]={a[l],-1};
        tag[k]={0,0};
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
    pull(k,l,r);
}

pii op(pii p, pii p2){
    pii res;
    if(p.first==-1) res.first=-1;
    else if(p2.first==-1) res.first=p.first;
    else res.first=add(p.first,p2.first);
    if(p.second==-1) res.second=-1;
    else if(p2.second==-1) res.second=p.second;
    else res.second=add(p.second,p2.second);
    return res;
}

void push(int k, int l, int r){
    if(l==r){
        tag[k]={0,0};
        return;
    }
    int mid=l+r>>1;
    val[k<<1]=op(val[k<<1],tag[k]);
    tag[k<<1]=op(tag[k<<1],tag[k]);
    int t=mid-l+1;
    pii p={get_fib(tag[k],t+1),get_fib(tag[k],t+2)};
    val[k<<1|1]=op(val[k<<1|1],p);
    tag[k<<1|1]=op(tag[k<<1|1],p);
    tag[k]={0,0};
}

void modify(int k, int l, int r, int ql, int qr, int x){
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r){
        pii p;
        if(x==1) p={f[l-ql+1],f[l-ql+2]};
        else p={mod-f[l-ql+1],mod-f[l-ql+2]};
        if(p.first>=mod) p.first-=mod;
        if(p.second>=mod) p.second-=mod;
        val[k]=op(val[k],p);
        tag[k]=op(tag[k],p);
        return;
    }
    push(k,l,r);
    int mid=l+r>>1;
    modify(k<<1,l,mid,ql,qr,x),modify(k<<1|1,mid+1,r,ql,qr,x);
    pull(k,l,r);
}

void modify(int l, int r, int x){modify(1,0,n-1,l,r,x);}

void orzck(){
    cin >> n >> q >> mod;
    f[0]=0,f[1]=1%mod,f[2]=1%mod;
    rep2(i,3,maxn) f[i]=(f[i-1]+f[i-2])%mod;
    rep(n) cin >> a[i];
    rep(n){
        int x;
        cin >> x;
        a[i]-=x;
        if(a[i]<0) a[i]+=mod;
    }
    build(1,0,n-1);
    while(q--){
        char c;
        int l,r;
        cin >> c >> l >> r;
        l--,r--;
        if(c=='A') modify(l,r,1);
        else modify(l,r,-1);
        bug(val[1].first,val[1].second);
        if(val[1]==pii(0,0)||val[1]==pii(0,-1)) print("YES");
        else print("NO");
    }
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