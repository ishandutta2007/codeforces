#include <bits/stdc++.h>
#define int long long
using namespace std;
int binup[100000][20];
int n, q;
vector<vector<int> > data;
vector<int> tin, tout, h;
int timer=0;
void dfs(int vertex, int last, int d){
    h[vertex] = d;
    tin[vertex] = timer++;
    binup[vertex][0] = last;
    if (last != -1){
        int V = last, lvl = 0;
        while (binup[V][lvl] != -1){
            binup[vertex][lvl+1] = binup[V][lvl];
            V = binup[V][lvl];
            lvl++;
        }
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        dfs(to, vertex, d+1);
    }
    tout[vertex] = timer++;
}
bool Father(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
pair<int, int> lca(int u, int v){
    if (Father(u, v)) return {h[u], u};
    if (Father(v, u)) return {h[v], v};
    for (int i=19; i >= 0; i--){
        int cand = binup[u][i];
        if (cand == -1 || Father(cand, v)) continue;
        u = cand;
    }
    return {h[u]-1, binup[u][0]};
}
struct Vertex{pair<int, int> min_code; pair<int, int> max_code; pair<int, int> min_lca;};
vector<Vertex> rmq;
void relax(int i){
    rmq[i].min_lca = min(rmq[2*i+1].min_lca, rmq[2*i+2].min_lca);
    rmq[i].min_code = min(rmq[2*i+1].min_code, rmq[2*i+2].min_code);
    rmq[i].max_code = max(rmq[2*i+1].max_code, rmq[2*i+2].max_code);
}
void construct(int i, int l, int r){
    if (r-l==1){
        rmq[i].min_code = {tin[l], l};
        rmq[i].max_code = {tin[l], l};
        if (l < n-1) rmq[i].min_lca = lca(l, l+1);
        else rmq[i].min_lca = {1e9, 1e9};
        return;
    }
    int mid = (l+r)/2;
    construct(2*i+1, l, mid);
    construct(2*i+2, mid, r);
    relax(i);
}
pair<int, int> get_min(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return {1e9, 1e9};
    if (l==l1 && r==r1) return rmq[i].min_code;
    int mid = (l+r)/2;
    return min(get_min(2*i+1, l, mid, l1, min(r1, mid)), get_min(2*i+2, mid, r, max(l1, mid), r1));
}
pair<int, int> get_max(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return {-1, -1};
    if (l==l1 && r==r1) return rmq[i].max_code;
    int mid = (l+r)/2;
    return max(get_max(2*i+1, l, mid, l1, min(r1, mid)), get_max(2*i+2, mid, r, max(l1, mid), r1));
}
pair<int, int> Lca(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return {1e9, 1e9};
    if (l==l1 && r==r1) return rmq[i].min_lca;
    int mid = (l+r)/2;
    return min(Lca(2*i+1, l, mid, l1, min(r1, mid)), Lca(2*i+2, mid, r, max(l1, mid), r1));
}
pair<int, int> Solve(int l, int r, int mid){
    if (mid == l) return {Lca(0, 0, n, l+1, r).first, mid};
    if (mid == r) return {Lca(0, 0, n, l, r-1).first, mid};
    pair<int, int> A = min(Lca(0, 0, n, l, mid-1), {h[l], l}), B = min(Lca(0, 0, n, mid+1, r), {h[r], r});
    return {lca(A.second, B.second).first, mid};

}
void solve(int l, int r){
    if (r-l==1) {
        pair<int, int> a = {h[l], r}, b = {h[r],l};
        a = max(a, b);
        cout << a.second+1 << " " << a.first << endl;
        return;
    }
    pair<int, int> mp = get_min(0,0,n,l, r+1);
    pair<int, int> tp = get_max(0,0,n,l, r+1);
    //cout << mp.first << "!!" << mp.second << endl;
    //cout << tp.first << " " << tp.second << endl;
    pair<int, int> F = Solve(l, r, mp.second);
    pair<int, int> S = Solve(l, r, tp.second);
    F = max(F, S);
    cout << F.second+1 << " " << F.first << endl;
}
signed main(){
    //freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    data.resize(n, {});
    tin.resize(n, 0);
    tout.resize(n, 0);
    h.resize(n, 0);
    for (int i=0;i<n;i++) for (int j=0;j<20;j++) binup[i][j] = -1;
    for (int i=0; i < n-1; i++){
        int x;
        cin >> x;
        data[x-1].push_back(i+1);
    }
    dfs(0, -1, 0);
    //for (int i=0;i<n;i++) cout << tin[i] << " ";
    //cout << endl;
    for (int i=0; i < 4*n; i++) rmq.push_back({});
    construct(0, 0, n);
    for (int i=0; i < q; i++){
        int L, R;
        cin >> L >> R;
        L--,R--;
        solve(L, R);
    }


}