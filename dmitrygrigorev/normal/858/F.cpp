#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#define int long long
using namespace std;
struct Edge{int to; bool can;};
int n, m, ai, bi;
vector<Edge> edges;
vector<vector<int> >  data, ans;
vector<bool> used;
bool dfs(int vertex, int e){
    used[vertex] = true;
    vector<int> vertexes;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (used[edges[to].to]) continue;
        edges[to].can = false;
        edges[to^1].can = false;
        bool res = dfs(edges[to].to, to^1);
        if (res) vertexes.push_back(edges[to].to);
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (!edges[to].can) continue;
        edges[to].can = false;
        edges[to^1].can = false;
        vertexes.push_back(edges[to].to);
    }
    bool ret = true;
    if (vertexes.size() % 2 != 0 && e != -1){
        vertexes.push_back(edges[e].to);
        ret = false;
    }
    for (int i=0; i+1 < vertexes.size(); i+=2){
        vector<int> h;
        h.push_back(vertexes[i]);
        h.push_back(vertex);
        h.push_back(vertexes[i+1]);
        ans.push_back(h);
    }
    return ret;
}
int32_t main(){
    cin >> n >> m;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
    }
    for (int i=0; i < m; i++){
        cin >> ai >> bi;
        Edge e1 = {bi-1, true};
        Edge e2 = {ai-1, true};
        edges.push_back(e1);
        edges.push_back(e2);
        data[ai-1].push_back(edges.size() - 2);
        data[bi-1].push_back(edges.size() - 1);
    }
    for (int i=0; i < n; i++){
        if (!used[i]){
            dfs(i,-1);
        }
    }
    cout << ans.size() << endl;
    for (int i=0; i < ans.size(); i++){
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2]+1 << endl;
    }
    return 0;
}