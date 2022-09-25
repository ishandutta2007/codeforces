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
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=300005;

//i_am_noob
#define wiwihorz  
struct segment_tree{
    vector<int> val,tag;
    int type;
    inline int mid(int l, int r){return l+r>>1;}
    segment_tree(int _siz, int _type){val.resize(4*_siz),tag.resize(4*_siz),type=_type;}
    inline int oper(int i, int j){
        return __gcd(i,j);
    }
    inline int def(){
        return 0;
    }
    void pull(int k){val[k]=oper(val[k<<1],val[(k<<1)+1]);}
    void modify(int k, int l, int r, int ql, int qr, int x){
        if(l>qr||r<ql) return;
        if(ql<=l&&qr>=r){
            val[k]=x;
            return;
        }
        modify(k<<1,l,mid(l,r),ql,qr,x);
        modify((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
        pull(k);
    }
    int query(int k, int l, int r, int ql, int qr){
        if(l>qr||r<ql) return def();
        if(ql<=l&&qr>=r) return val[k];
        return oper(query(k<<1,l,mid(l,r),ql,qr),query((k<<1)+1,mid(l,r)+1,r,ql,qr));
    }
};
segment_tree segtree(maxn,0);
int n,a[maxn],res;

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n-1) segtree.modify(1,0,n-2,i,i,abs(a[i+1]-a[i]));
    int l=0;
    res=1;
    rep(n-1) bug(segtree.query(1,0,n-2,i,i));
    rep2(i,1,n){
        while(l<i&&segtree.query(1,0,n-2,l,i-1)==1) l++;
        chkmax(res,i-l+1);
        bug(l,i);
    }
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