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
const int maxn=500005,maxm=100005,maxk=7777714;

//i_am_noob
//#define wiwihorz  
struct pt{
    int x,y,tag;
    pt(int _x=0, int _y=0){
        x=_x,y=_y;
        if(x>=00&&y==0) tag=0;
        else if(x>0&&y>0) tag=1;
        else if(x==0&&y>0) tag=2;
        else if(x<0&&y>0) tag=3;
        else if(x<0&&y==0) tag=4;
        else if(x<0&&y<0) tag=5;
        else if(x==0&&y<0) tag=6;
        else tag=7;
    }
}a[maxn];

bool operator <(pt x, pt y){
    if(x.tag!=y.tag) return x.tag<y.tag;
    if(x.x<0) x.x*=-1,x.y*=-1;
    if(y.x<0) y.x*=-1,y.y*=-1;
    return x.y*y.x<x.x*y.y;
}

bool operator ==(pt x, pt y){return x.tag==y.tag&&x.y*y.x==x.x*y.y;}

double abs(pt x){return sqrt(x.x*x.x+x.y*x.y);}

int n,k,id[maxn],cnt[maxn];
vector<vector<double>> dis;
priority_queue<pair<double,int>> pq;
double res;

void orzck(){
    cin >> n >> k;
    int cur=0;
    rep(n){
        int x,y;
        cin >> x >> y;
        if(x==0&&y==0) continue;
        a[cur]=pt(x,y);
        cur++;
    }
    assert(cur==n-1);
    n=cur;
    sort(a,a+n);
    vector<pt> vec;
    rep(n) vec.pb(a[i]);
    vec.resize(unique(all(vec))-vec.begin());
    rep(n) id[i]=lower_bound(all(vec),a[i])-vec.begin();
    dis.resize(maxn);
    rep(n) dis[id[i]].pb(abs(a[i]));
    rep(n) sort(all(dis[i]));
    rep(n) if(sz(dis[i])) pq.push({dis[i].back()*(k-1),i});
    int t=k;
    while(!pq.empty()){
        auto [d,id]=pq.top();
        pq.pop();
        if(d<0){
            t--;
            rep3(i,t-1,0){
                res+=dis[id][i]*(k-1-2*cnt[id]);
                cnt[id]++;
            }
            break;
        }
        res+=d;
        cnt[id]++;
        dis[id].pop_back();
        if(sz(dis[id])) pq.push({dis[id].back()*(k-1-2*cnt[id]),id});
        t--;
        if(t==0) break;
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
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}