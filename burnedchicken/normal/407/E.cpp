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

const int maxn=200005;

//i_am_noob
//#define wiwihorz  
struct segment_tree{
    vector<int> val,tag;
    int type,L,R;
    inline int mid(int l, int r){return l+r>>1;}
    segment_tree(int _siz=0, int _type=0){val.resize(4*_siz),tag.resize(4*_siz),type=_type,L=0,R=_siz-2;}
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
    void modify_in(int k, int l, int r, int ql, int qr, int x){
        if(l>qr||r<ql) return;
        if(ql<=l&&qr>=r){
            if(type) val[k]+=x;
            else val[k]+=(r-l+1)*x;
            tag[k]+=x;
            return;
        }
        push(k,l,r);
        modify_in(k<<1,l,mid(l,r),ql,qr,x);
        modify_in((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
        pull(k);
    }
    int query_in(int k, int l, int r, int ql, int qr){
        if(l>qr||r<ql) return def();
        if(ql<=l&&qr>=r) return val[k];
        push(k,l,r);
        return oper(query_in(k<<1,l,mid(l,r),ql,qr),query_in((k<<1)+1,mid(l,r)+1,r,ql,qr));
    }
    void modify(int l, int r, int x){modify_in(1,L,R,l,r,x);}
    int query(int l, int r){return query_in(1,L,R,l,r);}
};
segment_tree tree(maxn,1);

int n,k,d,a[maxn],b[maxn],lst[maxn],res1,res2;

void orzck(){
    cin >> n >> k >> d;
    rep(n) cin >> a[i];
    if(d==0){
        res1=0,res2=-1;
        rep(n){
            if(i&&a[i]==a[i-1]) lst[i]=lst[i-1];
            else lst[i]=i;
            if(i-lst[i]>res2-res1) res1=lst[i]+1,res2=i+1;
        }
        print(res1,res2);
        return;
    }
    rep(n) b[i]=(a[i]%d+d)%d;
    map<int,int> mm;
    rep(n){
        if(i&&b[i]==b[i-1]) lst[i]=lst[i-1];
        else lst[i]=i;
        if(mm.count(a[i])) chkmax(lst[i],mm[a[i]]+1);
        mm[a[i]]=i;
    }
    res1=0,res2=-1;
    rep(n) tree.modify(i,i,i*d);
    vector<int> stk1,stk2;
    stk1.pb(-1),stk2.pb(-1);
    rep(n){
        while(stk1.back()>=0&&a[i]>=a[stk1.back()]){
            tree.modify(stk1[sz(stk1)-2]+1,stk1.back(),-a[stk1.back()]);
            stk1.pop_back();
        }
        tree.modify(stk1.back()+1,i,a[i]);
        stk1.pb(i);
        while(stk2.back()>=0&&a[i]<=a[stk2.back()]){
            tree.modify(stk2[sz(stk2)-2]+1,stk2.back(),a[stk2.back()]);
            stk2.pop_back();
        }
        tree.modify(stk2.back()+1,i,-a[i]);
        stk2.pb(i);
        int l=lst[i],r=i;
        while(l<r){
            int mid=l+r>>1;
            if(tree.query(lst[i],mid)/d-i<=k) r=mid;
            else l=mid+1;
        }
        bug(i,l,tree.query(l,l)/d-i);
        if(i-l>res2-res1) res1=l+1,res2=i+1;
    }
    print(res1,res2);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}