#include <bits/stdc++.h>
using namespace std;
struct Edge{int to; int w; int pos;};
int n, m;
vector<vector<Edge> > data;
vector<pair<int, int> > edges;
vector<vector<int> > rmq;
bool cmp(Edge a, Edge b){
    return (a.w < b.w);
}
int bp(int to, int W){
    int L = -1, R = data[to].size();
    while (R-L>1){
        int M = (L+R)/2;
        if (data[to][M].w <= W) L = M;
        else R = M;
    }
    return R;
}
int get(int tree, int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return 0;
    if (l==l1 && r==r1) return rmq[tree][i];
    int mid = (l+r)/2;
    return max(get(tree, 2*i+1, l, mid, l1, min(r1, mid)), get(tree, 2*i+2, mid, r, max(l1, mid), r1));
}
void change(int tree, int i, int l, int r, int ind, int val){
    if (r-l==1){
        rmq[tree][i] = val;
        return;
    }
    int mid = (l+r) / 2;
    if (ind < mid) change(tree, 2*i+1, l, mid, ind, val);
    else change(tree, 2*i+2, mid, r, ind, val);
    rmq[tree][i] = max(rmq[tree][2*i+1], rmq[tree][2*i+2]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0; i < n; i++) data.push_back({});
    for (int i=0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        data[u-1].push_back({v-1, w, i});
        edges.push_back(make_pair(-1, -1));
    }
    for (int i=0; i < n; i++) sort(data[i].begin(), data[i].end(), cmp);
    for (int i=0; i < n; i++){
        for (int j=0; j < data[i].size(); j++){
            edges[data[i][j].pos] = make_pair(i, j);
        }
    }
    int ans = 1;
    for (int i=0; i < n; i++){
        vector<int> rmqq;
        for (int j=0; j < 4*data[i].size(); j++) rmqq.push_back(0);
        rmq.push_back(rmqq);
    }
    for (int i=m-1; i >= 0; i--){
        int x = edges[i].first, y = edges[i].second;
        int to = data[x][y].to;
        int ind = bp(to, data[x][y].w);
        int res = get(to, 0, 0, data[to].size(), ind, data[to].size());
        ans = max(ans, res+1);
        change(x, 0, 0, data[x].size(), y, res+1);
    }
    cout << ans << endl;
    return 0;
}