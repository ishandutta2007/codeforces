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

const int maxn=1000005,maxm=16,maxk=7777714;

//i_am_noob
#define wiwihorz  
int a[maxn],sum;
string str;

void upd(int pos, int x){
    sum-=a[pos];
    a[pos]=x;
    sum+=x;
}

void report(){
    vector<pii> res;
    int cur=0;
    while(cur<sz(str)){
        if(str[cur]=='0'){
            res.pb({cur+1,cur+1});
            cur++;
            continue;
        }
        int x=__lg(a[cur]);
        rep2(j,1,x+1) if(cur+j>=sz(str)||(str[cur+j]=='1'&&__lg(a[cur+j])!=x-j)) assert(0);
        res.pb({cur+1,cur+x+1});
        cur+=x+1;
    }
    print(sz(res));
    for(auto& [x,y]: res) print(x,y);
}

void orzck(){
    cin >> str;
    rep(sz(str)) a[i]=0;
    sum=0;
    rep(sz(str)) upd(i,str[i]=='1');
    if(sum==0) return print(-1),void();
    if(!(sum&sum-1)) return report();
    int tar=pow2(__lg(sum)+1);
    int cur=0;
    while(cur<sz(str)-1){
        if(str[cur]=='0'){
            cur++;
            continue;
        }
        upd(cur,2);
        if(sum==tar) break;
        cur+=2;
    }
    if(sum==tar) return report();
    bug(sum);
    cur=0;
    while(cur<sz(str)-2){
        bug(cur,sum);
        if(str[cur]=='0'){
            cur++;
            continue;
        }
        upd(cur,4);
        if(str[cur+1]=='1') upd(cur+1,2);
        if(str[cur+2]=='1') upd(cur+2,1);
        if(sum>tar){
            rep2(j,cur+3,sz(str)) if(str[j]=='1'){
                upd(j,1);
                if(sum==tar) break;
            }
        }
        if(sum==tar) break;
        cur+=3;
    }
    if(sum==tar) return report();
    vector<int> ones;
    rep(sz(str)) if(str[i]=='1') ones.pb(i);
    assert(sz(ones)==5||sz(ones)==9);
    if(ones.back()==ones[0]+sz(ones)-1){
        rep(sz(ones)-1) upd(ones[i],pow2(sz(ones)-2-i));
        upd(ones.back(),1);
        return report();
    }
    for(auto i: ones) upd(i,1);
    int x=-1;
    for(auto i: ones) if(i<sz(str)-2&&str[i+1]=='0'){
        upd(i,4);
        x=i;
        break;
    }
    assert(x!=-1);
    if(sum==8) return report();
    assert(sz(ones)==9);
    for(auto i: ones) if(i<sz(str)-2&&(i<x-2||i>x+2)&&str[i+1]=='1'){
        upd(i,4);
        upd(i+1,2);
        assert(sum==16);
        return report();
    }
    int y=-1;
    for(auto i: ones) if(i<sz(str)-2&&(i<x-2||i>x+2)&&str[i+1]=='0'){
        upd(i,4);
        y=i;
        break;
    }
    assert(y!=-1);
    for(auto i: ones) if(i<sz(str)-1&&(i<x-1||i>x+2)&&(i<y-1||i>y+2)){
        upd(i,2);
        break;
    }
    assert(sum==16);
    report();
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