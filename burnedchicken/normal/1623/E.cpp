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

const int maxn=200005,maxm=10000005,maxk=7777714;

//i_am_noob
//#define wiwihorz
int n,k,l[maxn],r[maxn],par[maxn][18];
bool small[maxn],used[maxn],bad[maxn];
string str;
vector<int> ord;

void dfs(int u){
    bug(u);
    if(l[u]>=0) dfs(l[u]);
    ord.pb(u);
    if(r[u]>=0) dfs(r[u]);
}

void dfs1(int u){
    if(l[u]>=0) dfs1(l[u]);
    if(!small[u]) bad[u]=1;
    if(small[u]&&!used[u]){
        bug(u);
        int cnt=1;
        int u2=u;
        rep3(i,17,0) if(par[u2][i]!=-1&&!used[par[u2][i]]) u2=par[u2][i],cnt+=pow2(i);
        if(cnt>k) bad[u]=1;
        else{ 
            vector<int> vec;
            bool flag=1;
            for(int v=u; v>=0; v=par[v][0]){
                if(!used[v]){
                    if(bad[v]){
                        flag=0;
                        break;
                    }
                    vec.pb(v);
                }
                else break;
            }
            if(!flag){
                for(auto i: vec) bad[i]=1;
            }
            else{
                bug(u,sz(vec),cnt);
                for(auto i: vec) used[i]=1;
                k-=sz(vec);
            }
        }
    }
    if(r[u]>=0) dfs1(r[u]);
}

void orzck(){
    cin >> n >> k >> str;
    par[0][0]=-1;
    rep(n){
        cin >> l[i] >> r[i];
        l[i]--,r[i]--;
        if(l[i]>=0) par[l[i]][0]=i;
        if(r[i]>=0) par[r[i]][0]=i;
    }
    rep2(i,1,18) rep1(u,n) par[u][i]=par[u][i-1]==-1?-1:par[par[u][i-1]][i-1];
    dfs(0);
    assert(sz(ord)==n);
    rep3(i,n-2,0){
        int u=ord[i];
        if(str[ord[i]]>str[ord[i+1]]) small[ord[i]]=0;
        else if(str[ord[i]]<str[ord[i+1]]) small[ord[i]]=1;
        else small[ord[i]]=small[ord[i+1]];
        bug(ord[i],small[ord[i]]);
    }
    dfs1(0);
    rep(n){
        cout << str[ord[i]];
        if(used[ord[i]]) cout << str[ord[i]];
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