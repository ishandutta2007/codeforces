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

template<typename T, int maxn, int type>
struct sparse{
    vector<T> val[22];
    sparse(){rep(__lg(maxn)+1) val[i].resize(max(0ll,maxn-pow2(i)+1));}
    inline T oper(T i, T j){return type?max(i,j):min(i,j);}
    void init(vector<T>& vec){
        rep(sz(vec)) val[0][i]=vec[i];
        rep2(i,1,__lg(maxn)+1) rep1(j,sz(vec)-pow2(i)+1) val[i][j]=oper(val[i-1][j],val[i-1][j+pow2(i-1)]);
    }
    T query(int l, int r){return oper(val[__lg(r-l+1)][l],val[__lg(r-l+1)][r-pow2(__lg(r-l+1))+1]);}
};

const int maxn=200005,maxm=30,maxk=7777714;

//i_am_noob
//#define wiwihorz  
int n,a[maxn],b[maxn],pre[maxn],res;
sparse<int,maxn,1> sp;
vector<int> vec1,vec2;

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) a[i]--;
    vector<int> stk;
    stk.pb(-1);
    rep(n) b[i]=inf;
    rep(n){
        while(stk.back()>=0&&a[stk.back()]<a[i]) stk.pop_back();
        chkmin(b[i],stk.back());
        stk.pb(i);
    }
    stk.clear();
    stk.pb(-1);
    rep(n){
        while(stk.back()>=0&&a[stk.back()]>a[i]) stk.pop_back();
        chkmin(b[i],stk.back());
        stk.pb(i);
    }
    vector<int> vec;
    rep(n) vec.pb(b[i]);
    bug(vec);
    sp.init(vec);
    rep(n-1){
        if(a[i]>a[i+1]) vec1.pb(i);
        else vec2.pb(i);
    }
    vector<int> de1,de2;
    rep(sz(vec1)-1) if(a[vec1[i+1]]>a[vec1[i]]){
        de1.pb(vec1[i+1]);
        pre[vec1[i+1]]=vec1[i];
    }
    rep(sz(vec2)-1) if(a[vec2[i+1]]<a[vec2[i]]){
        de1.pb(vec2[i+1]);
        pre[vec2[i+1]]=vec2[i];
    }
    int cur=-1;
    sort(all(de1));
    for(auto i: de1){
        bug(i);
        int L=pre[i]-cur;
        if(L<=0) continue;
        bug(cur,pre[i]);
        res-=pre[i]*(pre[i]-1)/2-cur*(cur-1)/2;
        bug(res);
        cur=pre[i];
        int R;
        bool flag=0;
        if(a[i]>a[i+1]&&a[i+1]>a[pre[i]]) flag=1;
        if(a[i]<a[i+1]&&a[i+1]<a[pre[i]]) flag=1;
        bug(flag);
        if(flag) R=i;
        else{
            int l=i+1,r=n-1;
            while(l<r){
                int mid=l+r+1>>1;
                if(sp.query(i,mid)>=i) r=mid-1,bug("de");
                else l=mid;
            }
            R=l;
        }
        res+=L*R;
        bug(L,R);
        bug(res);
    }
    bug(cur);
    res+=(n-1-cur)*(n-cur)/2;
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
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}