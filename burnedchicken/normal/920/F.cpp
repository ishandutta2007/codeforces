#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
const int maxn=300005;
//i_am_noob
int n,q,a[maxn],sum[4*maxn],maxx[4*maxn],D[1<<20],op,l,r,x;

void pull(int k){sum[k]=sum[k<<1]+sum[k<<1|1],maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);}

void build(int k, int l, int r){
    if(l==r) return sum[k]=maxx[k]=a[l],void();
    build(k<<1,l,l+r>>1),build(k<<1|1,(l+r>>1)+1,r);
    pull(k);
}

void modify(int k, int l, int r, int ql, int qr){
    if(l>qr||r<ql||maxx[k]<=2) return;
    if(l==r) return sum[k]=D[sum[k]],maxx[k]=D[maxx[k]],void();
    modify(k<<1,l,l+r>>1,ql,qr),modify(k<<1|1,(l+r>>1)+1,r,ql,qr);
    pull(k);
}

int query(int k, int l, int r, int ql, int qr){
    if(l>qr||r<ql) return 0;
    if(l>=ql&&r<=qr) return sum[k];
    return query(k<<1,l,l+r>>1,ql,qr)+query(k<<1|1,(l+r>>1)+1,r,ql,qr);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    rep2(i,1,1<<20) for(int j=i; j<(1<<20); j+=i) D[j]++;
    cin >> n >> q;
    rep(n) cin >> a[i];
    build(1,0,maxn-1);
    while(q--){
        cin >> op >> l >> r;
        l--,r--;
        if(op==1) modify(1,0,maxn-1,l,r);
        else print(query(1,0,maxn-1,l,r));
    }
    return 0;
}