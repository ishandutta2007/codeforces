#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
int n,a[maxn],minn[4*maxn],tag[4*maxn];
vector<int> vec;

void pull(int k){minn[k]=min(minn[k<<1],minn[k<<1|1]);}

void push(int k, int l, int r){
    if(l!=r){
        minn[k<<1]+=tag[k],minn[k<<1|1]+=tag[k];
        tag[k<<1]+=tag[k],tag[k<<1|1]+=tag[k];
    }
    tag[k]=0;
}

void modify(int k, int l, int r, int p, int x){
    if(l>p||r<p) return;
    if(l==r){
        minn[k]=x;
        return;
    }
    push(k,l,r);
    modify(k<<1,l,l+r>>1,p,x),modify(k<<1|1,l+r+2>>1,r,p,x);
    pull(k);
}

int query(int k, int l, int r, int ql, int qr){
    if(l>qr||r<ql) return inf+826;
    if(ql<=l&&qr>=r) return minn[k];
    push(k,l,r);
    return min(query(k<<1,l,l+r>>1,ql,qr),query(k<<1|1,l+r+2>>1,r,ql,qr));
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) vec.pb(a[i]);
    vec.resize(unique(all(vec))-vec.begin());
    rep(n) vec[i]--;
    rep(n) modify(1,0,n,i,inf);
    modify(1,0,n,n,0);
    rep(sz(vec)){
        int x=query(1,0,n,0,n);
        if(query(1,0,n,vec[i],vec[i])==x) x--;
        modify(1,0,n,i?vec[i-1]:n,x);
        //rep1(j,n+1) print0(query(1,0,n,j,j));
        //cout << "\n";
    }
    print(query(1,0,n,0,n)+sz(vec));
    return 0;
}