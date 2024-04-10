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
const int maxn=100005;
//i_am_noob
int n,q,sum[4*maxn],maxx[4*maxn],op,l,r,x,k;

void pull(int k){sum[k]=sum[k<<1]+sum[k<<1|1],maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);}

void modify1(int k, int l, int r, int p, int x){
    if(l>p||r<p) return;
    if(l==r) return sum[k]=x,maxx[k]=x,void();
    modify1(k<<1,l,l+r>>1,p,x),modify1(k<<1|1,(l+r>>1)+1,r,p,x);
    pull(k);
}

void modify2(int k, int l, int r, int ql, int qr, int x){
    if(l>qr||r<ql||maxx[k]<x) return;
    if(l==r) return sum[k]=sum[k]%x,maxx[k]=maxx[k]%x,void();
    modify2(k<<1,l,l+r>>1,ql,qr,x),modify2(k<<1|1,(l+r>>1)+1,r,ql,qr,x);
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
    #endif
    cin >> n >> q;
    rep(n){
        cin >> x;
        modify1(1,0,maxn-1,i,x);
    }
    while(q--){
        cin >> op;
        if(op==1){
            cin >> l >> r;
            print(query(1,0,maxn-1,l-1,r-1));
        }
        else if(op==2){
            cin >> l >> r >> x;
            modify2(1,0,maxn-1,l-1,r-1,x);
        }
        else{
            cin >> k >> x;
            modify1(1,0,maxn-1,k-1,x);
        }
    }
    return 0;
}