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

const int maxn=100005,maxm=105,maxk=7777714;

//i_am_noob
//#define wiwihorz  
const int DE=5;
map<vector<int>,ld> dp;
map<vector<int>,int> to;

ld solve(vector<int> vec){
    if(dp.count(vec)) return dp[vec];
    if(sz(vec)<=1) return 0;
    ld res=inf;
    int res2=-1;
    rep2(mask,1,pow2(DE)-1){
        vector<int> vec2[DE+1];
        for(auto i: vec) vec2[__builtin_popcount(i&mask)].pb(i);
        int de=0;
        rep(DE+1) if(sz(vec2[i])) de++;
        if(de<=1) continue;
        ld tot=1;
        rep(DE+1) if(sz(vec2[i])) tot+=((ld)vec2[i].size())/sz(vec)*solve(vec2[i]);
        if(tot<res) res=tot,res2=mask;
    }
    dp[vec]=res;
    to[vec]=res2;
    return res;
}

int n,cnt;
string str,ans,res;
ykh;
int base;

int query(string str1){
    cnt++;
    #ifdef i_am_noob
    int res=0;
    rep(n) if(ans[i]!=str1[i]) res++;
    #else
    print(str1); cout << flush;
    int res;
    cin >> res;
    #endif
    if(res==n){
        bug(cnt);
        exit(0);
    }
    return res;
}

int query(int l, int mask){
    string str2=str;
    rep2(i,l,l+DE) if(mask>>(i-l)&1){
        if(str2[i]=='T') str2[i]='F';
        else str2[i]='T';
    }
    return (query(str2)-base+__builtin_popcount(mask))/2;
}

void orzck(){
    vector<int> vec;
    rep(1<<DE) vec.pb(i);
    solve(vec);
    cin >> n;
    #ifdef i_am_noob
    rep(n) ans+=rng()&1?'T':'F';
    #endif
    rep(n) str+=rng()&1?'T':'F';
    base=query(str);
    rep1(j,n/DE){
        vector<int> state;
        rep(1<<DE) state.pb(i);
        while(sz(state)>1){
            assert(to.count(state));
            int x=to[state];
            int y=query(j*DE,x);
            vector<int> nstate;
            for(auto i: state) if(__builtin_popcount(i&x)==y) nstate.pb(i);
            state=nstate;
        }
        assert(sz(state)==1);
        rep(DE){
            bool b=state[0]>>i&1;
            if(str[j*DE+i]=='T') b^=1;
            if(b) res+='T';
            else res+='F';
        }
    }
    rep2(j,n/DE*DE,n){
        if(str[j]=='T') str[j]='F';
        else str[j]='T';
        if(query(str)>base){
            res+=str[j];
        }
        else{
            if(str[j]=='T') res+='F';
            else res+='T';
        }
        if(str[j]=='T') str[j]='F';
        else str[j]='T';
    }
    query(res);
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