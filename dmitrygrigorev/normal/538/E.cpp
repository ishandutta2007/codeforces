#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > data;
vector<int> mini, maxi;
vector<int> sz;
void dfs(int lvl, int vertex, int last){
    int counter = 0;
    int Sz = 0;
    vector<int> tos;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        dfs(1-lvl, to, vertex);
        Sz += sz[to];
        tos.push_back(to);
        counter++;
    }
    sz[vertex] = Sz;
    if (counter == 0){
        mini[vertex] = 1;
        maxi[vertex] = 1;
        sz[vertex]++;
        return;
    }
    if (lvl == 0){
        int mz = 1e6;
        for (int i=0; i < tos.size(); i++){
            int T = tos[i];
            mz = min(mz, sz[T] - maxi[T]);
        }
        maxi[vertex] = sz[vertex] - mz;
    }
    else{
        int mz = 0;
        for (int i=0; i < tos.size(); i++){
            int T = tos[i];
            mz += sz[T] - maxi[T] + 1;
        }
        maxi[vertex] = sz[vertex] - mz + 1;
    }
    if (lvl == 1){
        int mz = 1e6;
        for (int i=0; i < tos.size(); i++){
            int T = tos[i];
            mz = min(mz, mini[T]);
        }
        mini[vertex] = mz;
    }
    else{
        int mz = 0;
        for (int i=0; i < tos.size(); i++){
            int T = tos[i];
            mz += mini[T];
        }
        mini[vertex] = mz;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        mini.push_back(0);
        maxi.push_back(0);
        sz.push_back(0);
    }
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    dfs(0, 0, -1);
    cout << maxi[0]  << " " << mini[0] << endl;
    return 0;
}