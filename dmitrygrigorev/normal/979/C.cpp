#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
vector<int> path;
int x, y, zx, zy, s;
void dfs(int vertex, int last, vector<int> &p){
    p.push_back(vertex);
    if (vertex == y){
        path = p;
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (last==to) continue;
        dfs(to, vertex, p);
    }
    p.pop_back();
}
void dfs2(int vertex, int last){
    s++;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (last==to) continue;
        dfs2(to, vertex);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> x >> y;
    x--, y--;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    vector<int> nv;
    dfs(x, -1, nv);
    zx = path[1], zy = path[path.size() - 2];
    int ans = n * (n-1);
    s = 0;
    dfs2(x, zx);
    int ss = s;
    s = 0;
    dfs2(y, zy);
    ans -= s*ss;
    cout << ans;
}