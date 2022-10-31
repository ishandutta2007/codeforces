#include <bits/stdc++.h>
using namespace std;

const int N = 1<<17;
const int INF = 1000000007;

int n, arr[N];
int tree[2*N], lazy[2*N];
vector<int> pos[N];

void push(int v, int tl, int tr){
    tree[v] = max(tree[v], lazy[v]);
    if(tl != tr)
        lazy[v*2] = max(lazy[v*2], lazy[v]),
        lazy[v*2+1] = max(lazy[v*2+1], lazy[v]);
    lazy[v] = -INF;
}

void upd(int l, int r, int val, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tr < l || tl > r) return;
    if(l <= tl && tr <= r){
        lazy[v] = val;
        push(v, tl, tr);
        return;
    }
    int tm = (tl+tr)>>1;
    upd(l, r, val, v*2, tl, tm);
    upd(l, r, val, v*2+1, tm+1, tr);
    tree[v] = max(tree[v*2], tree[v*2+1]);
}

int query(int pos, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tr < pos || tl > pos) return -INF;
    if(tl == tr) return tree[v];
    int tm = (tl+tr)>>1;
    return max(query(pos, v*2, tl, tm), query(pos, v*2+1, tm+1, tr));
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> arr[i], --arr[i];
    for(int i = 0; i<n; i++)
        pos[arr[i]].push_back(i);
    for(int i = 0; i<=n; i++)
        pos[i].push_back(n);
    fill(tree, tree+2*N, -INF);
    fill(lazy, lazy+2*N, -INF);
    for(int i = 0; i<=n; i++)
        upd(i, i, i);
    for(int i = 0; i<=n; i++){
        bool work = 0;
        int prev = 0;
        for(auto p : pos[i]){
            int val = query(prev);
            if(val >= p){
                prev = p+1;
                continue;
            }
            work = 1; upd(prev, p, p);
            prev = p+1;
        }
        if(!work){
            cout << i+1 << endl;
            exit(0);
        }
    }
    cout << n+2 << endl;
}