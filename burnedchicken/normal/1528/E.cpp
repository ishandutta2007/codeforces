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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=1000005;

//i_am_noob
//#define wiwihorz  
template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=(_val%mod+mod)%mod;}
    operator int() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val%mod);}
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
    bool operator ==(const Modint& o) const {return val==o.val;}
};
#define modint Modint<MOD>
modint val[maxn],res;

modint cnt2_(int x){
    if(x<=0) return 0;
    return (val[x-1]*(val[x-1]-modint(1)))*modint((MOD+1)/2)+val[x-1];
}

modint cnt2(int x){
    return cnt2_(x)-cnt2_(x-1);
}

modint cnt3_(int x){
    if(x<=0) return 0;
    if(x==1) return 1;
    const modint k=modint(6).inv();
    return val[x-1]*(val[x-1]-modint(1))*(val[x-1]-modint(2))*k+val[x-1]*(val[x-1]-modint(1))+val[x-1];
}

modint cnt3(int x){
    return cnt3_(x)-cnt3_(x-1);
}

modint cnt(int x){
    if(x<0) return 0;
    if(x==0) return 1;
    return val[x]-val[x-1];
}

void orzck(){
    val[0]=1;
    rep2(i,1,maxn) val[i]=(val[i-1]*(val[i-1]-modint(1)))*modint((MOD+1)/2)+val[i-1]*modint(2)+modint(1);
    rep2(i,1,4) bug(val[i]);
    int n;
    cin >> n;
    res+=modint(2)*(cnt3(n)+cnt2(n));
    res+=1;
    bug(res,cnt3(n),cnt2(n));
    rep(n) res+=cnt2(i)*cnt(n-1-i)+cnt2(i);
    //rep(n) res+=cnt2(i)*cnt2(n-1-i)+modint(2)*(cnt2(i)*cnt1(n-1-i)+cnt2(i)*cnt0(n-1-i));
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