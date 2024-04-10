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
template<typename T, signed N>
struct BIT{
    T val[N];
    void modify(signed x, T y){for(signed i=++x; i<N; i+=i&-i) val[i]+=y;}
    T query(signed x, signed y){
        T ret=0;
        for(signed i=++y; i; i-=i&-i) ret+=val[i];
        for(signed i=x; i; i-=i&-i) ret-=val[i];
        return ret;
    }
    signed first_true(bool(*f)(T,signed)){
        if(f(0,0)) return 0;
        signed cur=0;
        T curval=0;
        for(signed i=__lg(N); i>=0; --i) if(cur+(1<<i)<N){
            if(!f(curval+val[cur+(1<<i)],cur+(1<<i))) cur+=1<<i,curval+=val[cur];
        }
        return min(cur,N-2);
    }
};
const int maxn=70,maxm=260,maxk=7777714;

//i_am_noob
#define wiwihorz
int n,m,id[maxn][maxn],res[maxm];
#define num Modint<3>
#define vect array<num,maxm>

vect add(vect x, vect y){
    vect res;
    rep(maxm) res[i]=x[i]+y[i];
    return res;
}

vect sub(vect x, vect y){
    vect res;
    rep(maxm) res[i]=x[i]-y[i];
    return res;
}

vect mul(vect x, int y){
    vect res;
    rep(maxm) res[i]=x[i]*y;
    return res;
}

vector<vect> vec;
vector<int> vec2;

bool ok;

bool Insert(vect x){
    bug(sz(vec2));
    rep(sz(vec2)) if(x[vec2[i]].val){
        x=sub(x,mul(vec[i],(x[vec2[i]].val)));
        bug(vec2[i],x[vec2[i]].val);
    }
    bool flag=0;
    int t=-1;
    rep(m) if(x[i].val){
        flag=1;
        t=i;
        break;
    }
    if(!flag){
        if(x[m].val) ok=0;
        return false;
    }
    x=mul(x,x[t].val);
    bug(t);
    vec2.pb(t);
    vec.pb(x);
    return true;
}

void orzck(){
    cin >> n >> m;
    rep(n) rep1(j,n) id[i][j]=-1;
    rep(m) res[i]=-1;
    rep(m){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        res[i]=w;
        id[u][v]=id[v][u]=i;
    }
    vec.clear(),vec2.clear();
    rep(m) if(res[i]>=0){
        vect x;
        rep1(j,maxm) x[j]=0;
        bug(i,res[i]);
        x[i]=1,x[m]=res[i];
        Insert(x);
    }
    ok=1;
    rep(n) rep2(j,i+1,n) rep2(k,j+1,n) if(id[i][j]>=0&&id[j][k]>=0&&id[k][i]>=0){
        vect x;
        rep1(l,maxm) x[l]=0;
        x[id[i][j]]=1,bug(id[i][j]);
        x[id[j][k]]=1,bug(id[j][k]);
        x[id[k][i]]=1,bug(id[k][i]);
        bug(i,j,k);
        Insert(x);
        if(!ok) break;
    }
    if(!ok){
        print(-1);
        return;
    }
    rep(m){
        vect x;
        rep1(l,maxm) x[l]=0;
        x[i]=1;
        Insert(x);
    }
    vector<vect> tvec=vec;
    reverse(all(tvec));
    vec.clear(),vec2.clear();
    for(auto v: tvec) Insert(v);
    assert(sz(vec)==m);
    for(auto v: vec){
        int t=-1;
        rep(m) if(v[i].val){
            t=i;
            break;
        }
        assert(t>=0);
        res[t]=v[m].val;
    }
    rep(m){
        if(res[i]==0) print0(3);
        else print0(res[i]);
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
    while(t--) orzck();
    return 0;
}