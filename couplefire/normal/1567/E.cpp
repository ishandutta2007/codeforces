#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define comb res = {a.val+b.val, a.pre, b.suf}; if(a.pre==tm-tl+1 && arr[tm]<=arr[tm+1]) res.pre = a.pre+b.pre; if(b.suf==tr-tm && arr[tm]<=arr[tm+1]) res.suf = b.suf+a.suf; if(arr[tm]<=arr[tm+1]) res.val += get(a.suf+b.pre)-get(a.suf)-get(b.pre);

const int N = 1<<18;

struct node{ll val; int pre, suf;} tree[N<<1];
int n, q, arr[N];

ll get(int x){return 1ll*x*(x+1)/2;}

void build(int v = 1, int tl = 0, int tr = N-1){
    if(tl==tr){
        tree[v] = {1, 1, 1};
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1, tl, tm); build(v<<1|1, tm+1, tr);
    node &res = tree[v], &a = tree[v<<1], &b = tree[v<<1|1]; comb
}

void upd(int pos, int val, int v = 1, int tl = 0, int tr = N-1){
    if(tl==tr){
        arr[pos] = val;
        tree[v] = {1, 1, 1};
        return;
    }
    int tm = (tl+tr)>>1;
    if(pos<=tm) upd(pos, val, v<<1, tl, tm);
    else upd(pos, val, v<<1|1, tm+1, tr);
    node &res = tree[v], &a = tree[v<<1], &b = tree[v<<1|1]; comb
}

node query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    if(l<=tl && tr<=r) return tree[v];
    int tm = (tl+tr)>>1;
    if(r<=tm) return query(l, r, v<<1, tl, tm);
    if(l>=tm+1) return query(l, r, v<<1|1, tm+1, tr);
    node res = {0, 0, 0};
    node a = query(l, tm, v<<1, tl, tm);
    node b = query(tm+1, r, v<<1|1, tm+1, tr);
    tl = l; tr = r;
    comb return res;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    build();
    while(q--){
        int t, x, y; cin >> t >> x >> y;
        if(t==1) upd(x-1, y);
        else cout << query(x-1, y-1).val << '\n';
    }
}