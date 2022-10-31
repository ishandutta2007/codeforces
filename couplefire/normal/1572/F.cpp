#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1<<18;

struct LazySeg{
    int tree[N<<1], lazy[N<<1];
    void push(int v, int tl, int tr){
        tree[v] += lazy[v]*(tr-tl+1);
        if(tl!=tr)
            lazy[v<<1] += lazy[v],
            lazy[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
    void upd(int l, int r, int inc, int v = 1, int tl = 0, int tr = N-1){
        push(v, tl, tr);
        if(tr<l || tl>r) return;
        if(l<=tl && tr<=r){
            lazy[v] = inc;
            push(v, tl, tr);
            return;
        }
        int tm = (tl+tr)>>1;
        upd(l, r, inc, v<<1, tl, tm);
        upd(l, r, inc, v<<1|1, tm+1, tr);
        tree[v] = tree[v<<1]+tree[v<<1|1];
    }
    int query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
        push(v, tl, tr);
        if(tr<l || tl>r) return 0;
        if(l<=tl && tr<=r) return tree[v];
        int tm = (tl+tr)>>1;
        return query(l, r, v<<1, tl, tm)+query(l, r, v<<1|1, tm+1, tr);
    }
} lazyseg;

struct SegBeat{
    struct node{int sum, mx, smx, cmx;};
    node tree[N<<1];
    void pull(int v){
        tree[v].sum = tree[v<<1].sum+tree[v<<1|1].sum;
        if(tree[v<<1].mx>tree[v<<1|1].mx)
            tree[v].mx = tree[v<<1].mx, tree[v].cmx = tree[v<<1].cmx, tree[v].smx = max(tree[v<<1].smx, tree[v<<1|1].mx);
        else if(tree[v<<1].mx<tree[v<<1|1].mx)
            tree[v].mx = tree[v<<1|1].mx, tree[v].cmx = tree[v<<1|1].cmx, tree[v].smx = max(tree[v<<1|1].smx, tree[v<<1].mx);
        else tree[v].mx = tree[v<<1].mx, tree[v].cmx = tree[v<<1].cmx+tree[v<<1|1].cmx, tree[v].smx = max(tree[v<<1].smx, tree[v<<1|1].smx);
    }
    void push(int v, int tl, int tr){
        if(tl==tr) return;
        if(tree[v<<1].mx>tree[v].mx)
            tree[v<<1].sum -= tree[v<<1].cmx*(tree[v<<1].mx-tree[v].mx),
            tree[v<<1].mx = tree[v].mx;
        if(tree[v<<1|1].mx>tree[v].mx)
            tree[v<<1|1].sum -= tree[v<<1|1].cmx*(tree[v<<1|1].mx-tree[v].mx),
            tree[v<<1|1].mx = tree[v].mx;
    }
    void build(int v = 1, int tl = 0, int tr = N-1){
        if(tl==tr){tree[v].mx = tl, tree[v].smx = 0, tree[v].cmx = 1; return;}
        int tm = (tl+tr)>>1;
        build(v<<1, tl, tm); build(v<<1|1, tm+1, tr); pull(v);
    }
    void upd1(int l, int r, int val, int v = 1, int tl = 0, int tr = N-1){
        if(tr<l || tl>r || val>=tree[v].mx) return;
        push(v, tl, tr);
        if(l<=tl && tr<=r && val>tree[v].smx){
            lazyseg.upd(val+1, tree[v].mx, -tree[v].cmx);
            tree[v].sum -= tree[v].cmx*(tree[v].mx-val);
            tree[v].mx = val;
            return;
        }
        if(tl==tr) return;
        int tm = (tl+tr)>>1;
        upd1(l, r, val, v<<1, tl, tm);
        upd1(l, r, val, v<<1|1, tm+1, tr); 
        pull(v);
    }
    void upd2(int pos, int val, int v = 1, int tl = 0, int tr = N-1){
        if(tr<pos || tl>pos) return;
        push(v, tl, tr);
        if(tl==tr){
            lazyseg.upd(pos, tree[v].mx, -1);
            lazyseg.upd(pos, val, 1);
            tree[v].mx = val;
            return;
        }
        int tm = (tl+tr)>>1;
        upd2(pos, val, v<<1, tl, tm);
        upd2(pos, val, v<<1|1, tm+1, tr); 
        pull(v);
    }
    int query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
        if(tr<l || tl>r) return 0;
        push(v, tl, tr);
        if(l<=tl && tr<=r) return tree[v].sum;
        int tm = (tl+tr)>>1;
        return query(l, r, v<<1, tl, tm)+query(l, r, v<<1|1, tm+1, tr);
    }
} segbeat;

int n, q;

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    segbeat.build();
    lazyseg.upd(1, n, 1);
    while(q--){
        int t, x, y; cin >> t >> x >> y;
        if(t==1){segbeat.upd2(x, y); if(x>1) segbeat.upd1(1, x-1, x-1);}
        else cout << lazyseg.query(x, y) << '\n';
    }
}