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
const int maxn=200005;

//i_am_noob
//#define wiwihorz  
struct segment_tree{
    vector<int> val,tag;
    int type;
    inline int mid(int l, int r){return l+r>>1;}
    segment_tree(int _siz, int _type){val.resize(4*_siz),tag.resize(4*_siz),type=_type;}
    inline int oper(int i, int j){
        if(type==0) return i+j;
        else if(type==1) return min(i,j);
        else return max(i,j);
    }
    inline int def(){
        if(type==0) return 0;
        else if(type==1) return 4e18;
        else return -4e18;
    }
    void pull(int k){val[k]=oper(val[k<<1],val[(k<<1)+1]);}
    void push(int k, int l, int r){
        if(l!=r){
            if(type){
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=tag[k];
                val[(k<<1)+1]+=tag[k];
            }
            else{
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=(mid(l,r)-l+1)*tag[k];
                val[(k<<1)+1]+=(r-mid(l,r))*tag[k];
            }
        }
        tag[k]=0;
    }
    void modify(int k, int l, int r, int ql, int qr, int x){
        if(l>qr||r<ql) return;
        if(ql<=l&&qr>=r){
            if(type) val[k]+=x;
            else val[k]+=(r-l+1)*x;
            tag[k]+=x;
            return;
        }
        push(k,l,r);
        modify(k<<1,l,mid(l,r),ql,qr,x);
        modify((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
        pull(k);
    }
    int query(int k, int l, int r, int ql, int qr){
        if(l>qr||r<ql) return def();
        if(ql<=l&&qr>=r) return val[k];
        push(k,l,r);
        return oper(query(k<<1,l,mid(l,r),ql,qr),query((k<<1)+1,mid(l,r)+1,r,ql,qr));
    }
};
int n,a[maxn],b[maxn],res;
segment_tree segtree(maxn,1);

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) b[i]=i;
    sort(b,b+n,[](int i, int j){return a[i]>a[j];});
    rep(n){
        if(segtree.query(1,0,n-1,b[i],n-1)>=-a[b[i]]){
            res++;
            segtree.modify(1,0,n-1,b[i],n-1,a[b[i]]);
        }
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