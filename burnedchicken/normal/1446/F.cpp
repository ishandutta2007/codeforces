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
const int maxn=100005,maxm=5,maxk=7777714;

//i_am_noob
//#define wiwihorz  
struct point{
    int x,y;
}a[maxn];
int n,k;
const double pi=acos(-1);

double abs(point p){return sqrt(p.x*p.x+p.y*p.y);}

double acos(point p){
    double res=0;
    if(p.y<0) res+=pi,p.x*=-1,p.y*=-1;
    if(abs(p.x)<eps) return res+pi/2;
    return res+acos(p.x/abs(p));
}

BIT<int,2*maxn> bit;

int solve(double r){
    vector<point> vec;
    rep(n) if(abs(a[i])>=r) vec.pb(a[i]);
    vector<pair<double,double>> vec1;
    vector<pair<double,int>> tmp;
    rep(sz(vec)){
        point p=vec[i];
        double ang=acos(p);
        double ang1=ang-acos(r/abs(p)),ang2=ang+acos(r/abs(p));
        if(ang1<0) ang1+=2*pi;
        if(ang2>=2*pi) ang2-=2*pi;
        if(ang1>ang2) swap(ang1,ang2);
        tmp.pb({ang1,i*2}),tmp.pb({ang2,i*2+1});
        vec1.pb({ang1,ang2});
    }
    sort(all(tmp));
    vector<pii> vec2;
    rep(sz(vec)){
        pair<double,double> p=vec1[i];
        pii p1;
        pair<double,int> de;
        de={p.first,i*2};
        p1.first=lower_bound(all(tmp),de)-tmp.begin();
        de={p.second,i*2+1};
        p1.second=lower_bound(all(tmp),de)-tmp.begin();
        //assert(p1.first<p1.second);
        vec2.pb(p1);
    }
    int t[maxn*2];
    memset(t,-1,sizeof t);
    rep(sz(vec2)) t[vec2[i].first]=vec2[i].second,t[vec2[i].second]=vec2[i].first;
    //rep(sz(vec2)*2) assert(t[i]!=-1);
    memset(bit.val,0,sizeof bit.val);
    int res=0;
    rep(sz(vec2)*2){
        if(t[i]>i) continue;
        res+=bit.query(t[i]+1,i-1);
        bit.modify(t[i],-1);
        bit.modify(i,1);
    }
    return res;
}

void orzck(){
    cin >> n >> k;
    rep(n) cin >> a[i].x >> a[i].y;
    double l=0,r=100000;
    rep1(_,50){
        double mid=(l+r)/2;
        if(solve(mid)>n*(n-1)/2-k) l=mid;
        else r=mid;
        bug(r-l);
    }
    print(l);
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