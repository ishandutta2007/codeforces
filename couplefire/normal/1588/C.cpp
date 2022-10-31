#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 300005;

struct node{
    int mn, cnt;
};

node comb(node a, node b){
    if(a.mn<b.mn) return a;
    if(a.mn>b.mn) return b;
    return {a.mn, a.cnt+b.cnt};
}

struct Seg{
    node tree[2*N]; int lazy[2*N];

    void clear(int v, int tl, int tr){
        lazy[v] = 0; tree[v] = {0, tr-tl+1};
        if(tl==tr) return;
        int tm = (tl+tr)>>1;
        clear(v<<1, tl, tm); clear(v<<1|1, tm+1, tr);
    }

    void push(int v, int tl, int tr){
        tree[v].mn += lazy[v];
        if(tl!=tr)
            lazy[v<<1] += lazy[v],
            lazy[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }

    void upd(int l, int r, int add, int v, int tl, int tr){
        if(l>r) return;
        push(v, tl, tr);
        if(tr<l || tl>r) return;
        if(l<=tl && tr<=r){
            lazy[v] += add;
            push(v, tl, tr);
            return;
        }
        int tm = (tl+tr)>>1;
        upd(l, r, add, v<<1, tl, tm);
        upd(l, r, add, v<<1|1, tm+1, tr);
        tree[v] = comb(tree[v<<1], tree[v<<1|1]);
    }

    int find(int l, int r, int v, int tl, int tr){
        if(l>r) return N;
        push(v, tl, tr);
        if(tr<l || tl>r) return N;
        if(l<=tl && tr<=r){
            if(tree[v].mn>=0ll) return N;
            while(tl<tr){
                int tm = (tl+tr)>>1;
                push(v<<1, tl, tm);
                push(v<<1|1, tm+1, tr);
                if(tree[v<<1].mn<0ll) v = (v<<1), tr = tm;
                else v = (v<<1|1), tl = tm+1;
            }
            return tl;
        }
        int tm = (tl+tr)>>1;
        int lres = find(l, r, v<<1, tl, tm);
        if(lres<N) return lres;
        return find(l, r, v<<1|1, tm+1, tr);
    }

    node query(int l, int r, int v, int tl, int tr){
        if(l>r) return {(int)1e18, 0};
        push(v, tl, tr);
        if(tr<l || tl>r) return {(int)1e18, 0};
        if(l<=tl && tr<=r) return tree[v];
        int tm = (tl+tr)>>1;
        return comb(query(l, r, v<<1, tl, tm), query(l, r, v<<1|1, tm+1, tr));
    }
} even, odd;

int n, arr[N];

void solve(){
    cin >> n;
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    if(n==1) ++n, arr[1] = 1e16;
    even.clear(1, 0, (n-1)>>1);
    odd.clear(1, 0, (n-2)>>1);
    int cur_sum = 0, ans = 0;
    for(int i = 0; i<n; ++i){
        cur_sum = arr[i]-cur_sum;
        if(i&1) odd.upd(i>>1, i>>1, cur_sum, 1, 0, (n-2)>>1);
        else even.upd(i>>1, i>>1, cur_sum, 1, 0, (n-1)>>1);
    }
    for(int i = 0; i<n; ++i){
        int hi = min(n-1, even.find((i+1)>>1, (n-1)>>1, 1, 0, (n-1)>>1)*2-2);
        hi = min(hi, odd.find(i>>1, (n-2)>>1, 1, 0, (n-2)>>1)*2-1);
        node bruh = comb(even.query((i+1)>>1, hi>>1, 1, 0, (n-1)>>1), odd.query(i>>1, (hi-1)>>1, 1, 0, (n-2)>>1));
        if(bruh.mn==0ll) ans += bruh.cnt;
        if(i&1) even.upd((i+1)>>1, (n-1)>>1, arr[i], 1, 0, (n-1)>>1), odd.upd(i>>1, (n-2)>>1, -arr[i], 1, 0, (n-2)>>1);
        else even.upd((i+1)>>1, (n-1)>>1, -arr[i], 1, 0, (n-1)>>1), odd.upd(i>>1, (n-2)>>1, arr[i], 1, 0, (n-2)>>1);
    }
    cout << ans << '\n';
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}