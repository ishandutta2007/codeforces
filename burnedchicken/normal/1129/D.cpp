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
const int MOD=Mod2;
const int maxn=100005;
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
const int K=405;
int n,k,a[maxn],b[maxn/K+5],cnt[maxn],occ[maxn],lst[maxn];
modint val[maxn],arr[maxn/K+5][maxn+5000],tot;

void modify(int r, bool add){
    int pos=r/K;
    rep2(i,pos*K,r+1){
        arr[pos][cnt[i]+5000]-=val[i];
        if(cnt[i]<=b[pos]) tot-=val[i];
        //if(cnt[i]<0) print(r),exit(0);
        cnt[i]+=add?1:-1;
        //if(cnt[i]<0) print(r),exit(0);
        arr[pos][cnt[i]+5000]+=val[i];
        if(cnt[i]<=b[pos]) tot+=val[i];
    }
    if(add) rep(pos){
        b[i]--;
        if(b[i]+1+5000>=0) tot-=arr[i][b[i]+1+5000];
    }
    else rep(pos){
        b[i]++;
        if(b[i]+5000>=0) tot+=arr[i][b[i]+5000];
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    #endif
    cin >> n >> k;
    rep(n) cin >> a[i];
    rep(n) a[i]--;
    rep(n) occ[i]=-1;
    rep(n) lst[i]=occ[a[i]],occ[a[i]]=i;
    rep(ceiling(n,K)) b[i]=k;
    val[0]=arr[0][5000]=tot=1;
    rep(n){
        modify(i,true);
        if(lst[i]>=0){
            rep1(_,2) modify(lst[i],false);
            if(lst[lst[i]]>=0) modify(lst[lst[i]],true);
        }
        val[i+1]=tot;
        arr[(i+1)/K][5000]+=tot;
        tot+=tot;
    }
    print(val[n]);
    return 0;
}