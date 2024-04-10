#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
const int maxn=500005;
//i_am_noob
int n,p[maxn],w[maxn],l[maxn],r[maxn],a[maxn],q,val[maxn*4],tag[maxn*4],cur,ans[maxn];
vector<int> child[maxn];

inline void pull(int k){val[k]=min(val[k<<1],val[k<<1|1]);}

inline void push(int k, int l, int r){
    if(l!=r){
        val[k<<1]+=tag[k],tag[k<<1]+=tag[k];
        val[k<<1|1]+=tag[k],tag[k<<1|1]+=tag[k];
    }
    tag[k]=0;
}

void build(int k, int l, int r){
    if(l==r){
        val[k]=a[l];
        return;
    }
    build(k<<1,l,l+r>>1),build(k<<1|1,(l+r>>1)+1,r);
    pull(k);
}

void modify(int k, int l, int r, int ql, int qr, int x){
    if(l>qr||r<ql) return;
    if(ql<=l&&qr>=r){
        val[k]+=x,tag[k]+=x;
        return;
    }
    push(k,l,r);
    modify(k<<1,l,l+r>>1,ql,qr,x),modify(k<<1|1,(l+r>>1)+1,r,ql,qr,x);
    pull(k);
}

int query(int k, int l, int r, int ql, int qr){
    if(l>qr||r<ql) return inf;
    if(ql<=l&&qr>=r) return val[k];
    push(k,l,r);
    return min(query(k<<1,l,l+r>>1,ql,qr),query(k<<1|1,(l+r>>1)+1,r,ql,qr));
}

struct qu{int id,v,l,r;}qq[maxn];

void dfs(int u){
    if(u){
        modify(1,0,n-1,l[u],r[u],-w[u]);
        modify(1,0,n-1,0,l[u]-1,w[u]);
        modify(1,0,n-1,r[u]+1,n-1,w[u]);
    }
    bug(u,l[u],r[u]);
    rep(n) bug(u,i,query(1,0,n-1,i,i));
    while(cur<q&&qq[cur].v==u) ans[qq[cur].id]=query(1,0,n-1,qq[cur].l,qq[cur].r),cur++;
    for(auto v: child[u]) dfs(v);
    if(u){
        modify(1,0,n-1,l[u],r[u],w[u]);
        modify(1,0,n-1,0,l[u]-1,-w[u]);
        modify(1,0,n-1,r[u]+1,n-1,-w[u]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> q;
    rep2(i,1,n){
        cin >> p[i] >> w[i];
        p[i]--;
        child[p[i]].pb(i);
    }
    rep(n) l[i]=i,r[i]=i;
    rep3(i,n-1,1) l[p[i]]=min(l[p[i]],l[i]),r[p[i]]=max(r[p[i]],r[i]);
    a[0]=0;
    rep2(i,1,n) a[i]=a[p[i]]+w[i];
    rep(n) if(l[i]!=r[i]) a[i]=inf;
    build(1,0,n-1);
    rep(q){
        cin >> qq[i].v >> qq[i].l >> qq[i].r;
        qq[i].v--,qq[i].l--,qq[i].r--;
        qq[i].id=i;
    }
    sort(qq,qq+q,[](qu& i, qu& j){return i.v<j.v;});
    dfs(0);
    rep(q) print(ans[i]);
    return 0;
}