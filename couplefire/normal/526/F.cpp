#include <bits/stdc++.h>
using namespace std;

const int N = 1<<19;

array<int, 2> tree[N<<1];
int lazy[N<<1];

void build(int v = 1, int tl = 0, int tr = N-1){
    tree[v] = {0, tr-tl+1};
    if(tr == tl) return;
    int tm = (tl+tr)>>1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm+1, tr);
}

void push(int v, int tl, int tr){
    tree[v][0] += lazy[v];
    if(tl != tr) lazy[v<<1] += lazy[v], lazy[v<<1|1] += lazy[v];
    lazy[v] = 0;
}

void upd(int l, int r, int inc, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tr < l || tl > r) return;
    if(l <= tl && tr <= r){
        lazy[v] += inc;
        push(v, tl, tr);
        return;
    }
    int tm = (tl+tr)>>1;
    upd(l, r, inc, v<<1, tl, tm);
    upd(l, r, inc, v<<1|1, tm+1, tr);
    if(tree[v<<1][0] == tree[v<<1|1][0]) tree[v] = {tree[v<<1][0], tree[v<<1][1]+tree[v<<1|1][1]};
    else tree[v] = min(tree[v<<1], tree[v<<1|1]);
}

int n, arr[N];
long long ans;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, b; cin >> a >> b; --a; --b;
        arr[a] = b;
    }
    build();
    stack<array<int, 2>> min_st, max_st;
    min_st.push({-N, -1}); max_st.push({N, -1});
    upd(0, N-1, 1);
    for(int i = 0; i<n; i++){
        while(!max_st.empty() && max_st.top()[0] < arr[i]){
            int p2 = max_st.top()[1], val = max_st.top()[0]; max_st.pop();
            int p1 = max_st.top()[1]+1;
            upd(p1, p2, arr[i]-val);
        }
        max_st.push({arr[i], i});
        while(!min_st.empty() && min_st.top()[0] > arr[i]){
            int p2 = min_st.top()[1], val = min_st.top()[0]; min_st.pop();
            int p1 = min_st.top()[1]+1;
            upd(p1, p2, val-arr[i]);
        }
        min_st.push({arr[i], i});
        upd(0, i, -1);
        ans += tree[1][1];
    }
    cout << ans << endl;
}