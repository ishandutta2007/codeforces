#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > data;
int mx = 0, vrt,k;
void dfs(int vertex, int last, vector<int> &path){
    path.push_back(vertex);
    if (path.size() > mx){
        mx = path.size();
        vrt = path[path.size() / 2];
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to==last) continue;
        dfs(to, vertex, path);
    }
    path.pop_back();
}
void gt(int vertex, int last, int lvl){
    int ctr=0;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to==last) continue;
        ctr++;
        gt(to, vertex, lvl-1);
    }
    if (lvl==0){
        if (ctr){
            cout << "No";
            exit(0);
        }
    }
    else{
        if (ctr < 3){
            cout << "No";
            exit(0);
        }
    }
}
void solve(int vertex){
    vector<int> p;
    dfs(vertex, -1, p);
    gt(vrt, -1, k);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> k;
    for (int i=0; i < n; i++) data.push_back({});
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    if (n==1){
        cout << "No";
        return 0;
    }
    for (int i=0; i < n; i++){
        if (data[i].size() == 1){
            solve(i);
            break;
        }
    }
    cout << "Yes";
    return 0;
}