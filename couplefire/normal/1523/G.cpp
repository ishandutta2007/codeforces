#include <bits/stdc++.h>
using namespace std;

const int N = 1<<16, M = 2e5+5;

struct node{
    int val = M; node* c[2];
    node(){c[0]=c[1]=nullptr;}
    void upd(int ind, int v, int tl = 0, int tr = N-1){
        if(tl == ind && tr == ind){val = min(val, v); return;}
        int tm = (tl+tr)>>1;
        if(ind <= tm){
            if(!c[0]) c[0] = new node();
            c[0]->upd(ind, v, tl, tm);
        } else{
            if(!c[1]) c[1] = new node();
            c[1]->upd(ind, v, tm+1, tr);
        }
        if(c[0]) val = min(val, c[0]->val);
        if(c[1]) val = min(val, c[1]->val);
    }
    int query(int l, int r, int tl = 0, int tr = N-1){
        if(tr < l || tl > r) return M;
        if(l <= tl && tr <= r) return val;
        int tm = (tl+tr)>>1; int res = M;
        if(c[0]) res = min(res, c[0]->query(l, r, tl, tm));
        if(c[1]) res = min(res, c[1]->query(l, r, tm+1, tr));
        return res;
    }
};

struct Node{
    node seg; Node* c[2];
    Node(){c[0]=c[1]=nullptr;}
    void upd(int x, int y, int v, int tl = 0, int tr = N-1){
        if(tl == x && tr == x) return seg.upd(y, v);
        int tm = (tl+tr)>>1;
        if(x <= tm){
            if(!c[0]) c[0] = new Node();
            c[0]->upd(x, y, v, tl, tm);
        } else{
            if(!c[1]) c[1] = new Node();
            c[1]->upd(x, y, v, tm+1, tr);
        }
        seg.upd(y, v);
    }
    int query(int x1, int x2, int y1, int y2, int tl = 0, int tr = N-1){
        if(tr < x1 || tl > x2) return M;
        if(x1 <= tl && tr <= x2) return seg.query(y1, y2);
        int tm = (tl+tr)>>1; int res = M;
        if(c[0]) res = min(res, c[0]->query(x1, x2, y1, y2, tl, tm));
        if(c[1]) res = min(res, c[1]->query(x1, x2, y1, y2, tm+1, tr));
        return res;
    }
};

int n, m;
array<int, 2> arr[M];
vector<int> stuff[N];
Node* tree = new Node();

int solve(int l, int r){
    if(l > r) return 0;
    int res = tree->query(l, r, l, r);
    if(res == M) return 0;
    return arr[res][1]-arr[res][0]+1+solve(l, arr[res][0]-1)+solve(arr[res][1]+1, r);
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b; --a; --b;
        arr[i] = {a, b};
        stuff[b-a+1].push_back(i);
    }
    vector<int> ans;
    for(int i = n; i>=1; i--){
        reverse(stuff[i].begin(), stuff[i].end());
        for(int j : stuff[i]) tree->upd(arr[j][0], arr[j][1], j);
        ans.push_back(solve(0, n-1));
    }
    reverse(ans.begin(), ans.end());
    for(int x : ans) cout << x << endl;
}