#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (ll i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0)
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/
const int maxn = 5e5+100;
struct Segment_Tree{
    int val[maxn*4];
    int query(int x,int l,int r,int L,int R){
        if (l>R || L>r)return -inf;
        if (L<=l && r<=R)return val[x];
        int mid = l + r >>1;
        return max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
    void up(int x){
        val[x] = max(val[x<<1],val[x<<1|1]);
    }
    void update(int x,int l,int r,int Pos,int Val){
        if (l == r){
            val[x] = Val;
            return ;
        }
        int mid = l+r >>1;
        if (Pos <= mid){
            update(x<<1,l,mid,Pos,Val);
        }else{
            update(x<<1|1,mid+1,r,Pos,Val);
        }
        up(x);
    }
}tree_empty;
struct Segmenter_Tree{
    int val[maxn*4];
    int lazy[maxn*4];
    void down(int x){
        if (!lazy[x])return;
        val[x<<1] = lazy[x];
        val[x<<1|1] = lazy[x];
        lazy[x<<1] = lazy[x];
        lazy[x<<1|1] = lazy[x];
        lazy[x] = 0;
    }
    void up(int x){
        val[x] = max(val[x<<1],val[x<<1|1]);
    }
    int query(int x,int l,int r,int L,int R){
        if (l>R || L>r)return -inf;
        if (L<=l && r<=R)return val[x];
        int mid = l+r >>1;
        down(x);
        return max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
    void update(int x,int l,int r,int L,int R,int Val){
        if (l>R || L>r)return ;
        if (L<=l && r<=R){
            val[x] = Val,lazy[x] = Val;
            return;
        }
        int mid = l+r >>1;
        down(x);
        update(x<<1,l,mid,L,R,Val);
        update(x<<1|1,mid+1,r,L,R,Val);
        up(x);
    }
}tree_fill;
int first[maxn],nxt[maxn*2],des[maxn*2],tot;
int n,m;
int l[maxn],r[maxn],dfs_clock;
inline void addEdge(int x,int y){
    tot ++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
}
void dfs(int node,int father){
    l[node] = ++dfs_clock;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v == father)continue;
        dfs(v,node);
    }
    r[node] = dfs_clock;
}
int main(){
    untie;
    cin>>n;
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
        addEdge(y,x);
    }
    dfs(1,0);
    cin>>m;
    REP(label,1,m){
        int opt,u;
        cin>>opt>>u;
        if (opt == 1){
            tree_fill.update(1,1,n,l[u],r[u],label);
        }else if (opt == 2){
            tree_empty.update(1,1,n,l[u],label);
        }else{
            int fill_label = tree_fill.query(1,1,n,l[u],l[u]);
            int empty_label = tree_empty.query(1,1,n,l[u],r[u]);
            //cout<<fill_label<<" "<<empty_label<<endl;
            if (fill_label>empty_label){
                cout<<1<<endl;
            }else {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}