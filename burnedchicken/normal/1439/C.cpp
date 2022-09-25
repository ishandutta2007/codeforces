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
const int maxn=1<<18;
//i_am_noob
int n,a[maxn],q,o,x,y,ans;

struct Node{
    int l,r,sum,maxx,tag;
    Node(){}
    Node(int _l, int _r, int _sum, int _maxx, int _tag):l(_l),r(_r),sum(_sum),maxx(_maxx),tag(_tag){}
    void modify(int val){sum=val*(r-l+1),maxx=val;}
}node[maxn*2+5];

inline void pull(int k){node[k].sum=node[k<<1].sum+node[k<<1|1].sum,node[k].maxx=max(node[k<<1].maxx,node[k<<1|1].maxx);}

void build(){
    rep2(i,maxn,maxn<<1) node[i]=Node(i-maxn,i-maxn,a[i-maxn],a[i-maxn],-1);
    rep3(i,maxn-1,1) node[i]=Node(node[i<<1].l,node[i<<1|1].r,0,0,-1),pull(i);
}

void push(int k){
    if(node[k].tag==-1) return;
    if(k<maxn) rep2(i,k<<1,(k<<1)+2) node[i].modify(node[k].tag),node[i].tag=node[k].tag;
    node[k].tag=-1;
}

void modify(int k, int l, int r, int x){
    if(l>node[k].r||r<node[k].l) return;
    if(l<=node[k].l&&r>=node[k].r){
        node[k].modify(x);
        node[k].tag=x;
        return;
    }
    push(k);
    modify(k<<1,l,r,x),modify(k<<1|1,l,r,x);
    pull(k);
}

int query(int k, int l, int r){
    if(l>node[k].r||r<node[k].l) return 0;
    if(l<=node[k].l&&r>=node[k].r) return node[k].sum;
    push(k);
    return query(k<<1,l,r)+query(k<<1|1,l,r);
}

int bs_suffix1(int k, int start, int x, int cur=-inf){//first suffix s.t. max of the suffix <x
    if(cur>=x||node[k].r<start||(k>=maxn&&max(cur,node[k].maxx)>=x)) return inf;
    if(max(cur,node[k].maxx)<x) return max(start,node[k].l);
    push(k);
    if(max(cur,node[k<<1|1].maxx)>=x) return bs_suffix1(k<<1|1,start,x,cur);
    int val=bs_suffix1(k<<1,start,x,max(cur,node[k<<1|1].maxx));
    return val==inf?max(start,node[k<<1|1].l):val;
}

int bs_suffix2(int k, int start, int x, int cur=0){//first suffix s.t. sum of the suffix <x
    if(cur>=x||node[k].r<start||(k>=maxn&&cur+node[k].sum>=x)) return inf;
    if(cur+node[k].sum<x) return max(start,node[k].l);
    push(k);
    if(cur+node[k<<1|1].sum>=x) return bs_suffix2(k<<1|1,start,x,cur);
    int val=bs_suffix2(k<<1,start,x,cur+node[k<<1|1].sum);
    return val==inf?max(start,node[k<<1|1].l):val;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    rep(n) cin >> a[i];
    build();
    while(q--){
        cin >> o >> x >> y;
        if(o==1){
            x--;
            int start=bs_suffix1(1,0,y);
            if(start<=x) modify(1,start,x,y);
        }
        else{
            x--;
            ans=0;
            int tmp,suf;
            while(1){
                x=bs_suffix1(1,x,y+1);
                if(x>maxn+5) break;
                suf=query(1,x,n-1);
                tmp=bs_suffix2(1,x,suf-y);
                tmp--;
                if(tmp==x) break;
                if(tmp>maxn+5){
                    ans+=n-x;
                    break;
                }
                y-=suf-query(1,tmp,n-1);
                ans+=tmp-x;
                x=tmp;
            }
            print(ans);
        }
    }
    return 0;
}