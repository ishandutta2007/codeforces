#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > data;
int n, m, k;
bool more(int d){
    if (n%k==0){
        int T = n/k;
        return (d >= T);
    }
    int T = n/k + 1;
    return (d >= T);
}
vector<vector<int> > ans;
vector<int> h;
vector<bool> used;
void add(vector<int> &path, int A, int B, int dp){
    vector<int> dop;
    int stat = 0;
    for (int i=0; i < path.size(); i++){
        if (path[i] == A) stat=1;
        if (stat==1) dop.push_back(path[i]);
        if (path[i] == B) stat=2;
    }
    if (dp!=-1) dop.push_back(dp);
    reverse(dop.begin(), dop.end());
    ans.push_back(dop);
}
void print(){
    cout << "CYCLES" << "\n";
    for (int i=0; i < ans.size(); i++){
        cout << ans[i].size() << "\n";
        for (int j=0; j < ans[i].size(); j++) cout << ans[i][j] + 1 << " ";
        cout << "\n";
    }
    exit(0);
}
void dfs(int vertex, int last, int d, vector<int> &path){
    used[vertex] = true;
    h[vertex] = d-1;
    path.push_back(vertex);
    if (more(d)){
        cout << "PATH" << "\n";
        cout << d << "\n";
        for (int i=0; i < path.size(); i++) cout << path[i]+1 << " ";
        exit(0);
    }
    int ctr = 0;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        dfs(to, vertex, d+1, path);
        ctr++;
    }
    if (ctr == 0){
        int A=-1, B=-1;
        for (int i=0; i < data[vertex].size(); i++){
            int to = data[vertex][i];
            if (to==last) continue;
            if (A==-1) A = to;
            else if (B==-1) B = to;
            else break;
        }
        if (h[A] > h[B]) swap(A, B);
        if ((h[B] - h[A]+ 2 )%3 != 0){
            add(path, A, B, vertex);
        }
        else if ((h[vertex] - h[A] + 1) % 3 != 0){
            add(path, A, vertex, -1);
        }
        else add(path, B, vertex, -1);
        if (ans.size() == k) print();
    }
    path.pop_back();
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    data.resize(n, {});
    used.resize(n, false);
    for (int i=0; i < m; i++){
        int u, v;
        cin >> u >> v;
        data[u-1].push_back(v-1);
        data[v-1].push_back(u-1);
    }
    vector<int> kek = {};
    h.resize(n, -1);
    dfs(0, -1, 1, kek);
}