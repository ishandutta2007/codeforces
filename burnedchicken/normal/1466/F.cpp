#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ull unsigned long long
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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=1000005;
//i_am_noob
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

struct dsu{
    vector<int> fa,siz;
    dsu(int _siz){
        fa.resize(_siz),siz.resize(_siz);
        rep(_siz) fa[i]=i,siz[i]=1;
    }
    int Find(int _x){return fa[_x]==_x?_x:fa[_x]=Find(fa[_x]);}
    void Union(int _x, int _y){
        int _a=Find(_x),_b=Find(_y);
        if(_a==_b) return;
        if(siz[_a]<siz[_b]) swap(_a,_b);
        fa[_b]=_a;
        siz[_a]+=siz[_b];
    }
}d(maxn);

int n,m,x,a[maxn],b[maxn];
vector<int> vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> m;
    rep(n){
    	cin >> x;
    	if(x==2) cin >> a[i] >> b[i];
    	else{
    		cin >> a[i];
    		b[i]=0;
    	}
    }
    rep(n){
    	if(d.Find(a[i])==d.Find(b[i])) continue;
    	vec.pb(i);
    	d.Union(a[i],b[i]);
    }
    print(modint(2).Pow(sz(vec)),sz(vec));
    for(auto i: vec) print0(i+1);
    cout << "\n";
    return 0;
}