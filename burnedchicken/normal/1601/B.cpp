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

template<typename T, T(*op)(T,T), T(*e)(), signed N>
struct segtree{
    static const signed maxn=1<<__lg(N-1)+1;
    T val[maxn<<1];
    segtree(){rep(maxn<<1) val[i]=e();}
    void pull(signed k){val[k]=op(val[k<<1],val[k<<1|1]);}
    void modify(signed p, T x){
        p+=maxn;
        val[p]=x;
        for(p>>=1; p; p>>=1) pull(p);
    }
    T query(signed l, signed r){
        T resl=e(),resr=e();
        l+=maxn,r+=maxn+1;
        while(l<r){
            if(l&1) resl=op(resl,val[l++]);
            if(r&1) resr=op(val[--r],resr);
            l>>=1,r>>=1;
        }
        return op(resl,resr);
    }
};
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=300005,maxm=7777714,maxk=7777714;

//i_am_noob
//#define wiwihorz  

int n,a[maxn],b[maxn],val[maxn];
constexpr int op(int x, int y){return min(x,y);}
constexpr int e(){return inf;}
segtree<int,op,e,maxn> tree;

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) cin >> b[i];
    tree.modify(0,0);
    rep(n){
        bug(i+b[i]-a[i+b[i]]+1,i+b[i]+1);
        int x=tree.query(i+b[i]-a[i+b[i]]+1,i+b[i]+1)+1;
        bug(x);
        tree.modify(i+1,x);
        if(x<=n){
            val[x]=i;
            bug(x,val[x]);
        }
    }
    int ans=tree.query(n,n);
    if(ans>n){
        print(-1);
        return;
    }
    print(ans);
    rep3(i,ans-1,1) print0(val[i]+1);
    print(0);
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