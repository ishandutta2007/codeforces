#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <bitset>
#include <fstream>
#define int long long
using namespace std;
const int M = 100000;
int n, m, u, v, timer, counter;
vector<vector<int> > data, tt;
int binup[M][20];
vector<int> tin, tout, depth, cs, os, ch;
void dfs(int vertex, int last, int d, int type){
    cs[vertex] = counter;
    tin[vertex] = timer;
    timer += 1;
    depth[vertex] = d;
    os[vertex] = (type == 0);
    ch[vertex] = (type == 1);
    if (last != -1){
        if (os[vertex] != 0) os[vertex] += os[last];
        if (ch[vertex] != 0) ch[vertex] += ch[last];
        binup[vertex][0] = last;
        int now_father = last;
        int now_level = 0;
        while (binup[now_father][now_level] != -1){
            binup[vertex][now_level + 1] = binup[now_father][now_level];
            now_father = binup[now_father][now_level];
            now_level += 1;
        }
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (last == to) continue;
        dfs(to, vertex, d+1, tt[vertex][i]);
    }
    tout[vertex] = timer;
    timer += 1;
}
int lca(int fv, int sv){
    if (tin[fv] <= tin[sv] && tout[fv] >= tout[sv]) return fv;
    if (tin[sv] <= tin[fv] && tout[sv] >= tout[fv]) return sv;
    int now_vertex = fv;
    for (int level=19; level >= 0; level --){
        if (binup[now_vertex][level] == -1) continue;
        int candidate = binup[now_vertex][level];
        if (tin[candidate] < tin[sv] && tout[candidate] > tout[sv]) continue;
        now_vertex = candidate;
    }
    return binup[now_vertex][0];
}
signed main()
{
    cin >> n;
    vector<bool> fathers;
    for (int i=0; i < n; i++){
        tin.push_back(-1);
        tout.push_back(-1);
        depth.push_back(-1);
        vector<int> help, h;
        tt.push_back(h);
        data.push_back(help);
        fathers.push_back(true);
        cs.push_back(-1);
        os.push_back(-1);
        ch.push_back(-1);
    }
    for (int i=0; i < n; i++){
        int p, t;
        cin >> p >> t;
        if (p == -1) continue;
        data[p-1].push_back(i);
        fathers[i] = false;
        tt[p-1].push_back(t);
    }
    cin >> m;
    for (int i=0; i < M; i++){
        for (int j=0; j < 20; j++){
            binup[i][j] = -1;
        }
    }
    timer = 0;
    counter = 0;
    for (int i=0; i < n; i++){
        if (fathers[i]){
            dfs(i, -1, 0, -1);
            counter++;
        }
    }
    for (int i=0; i < m; i++){
        int t;
        cin >> t >> u >> v;
        u--;
        v--;
        if (cs[u] != cs[v] || u == v){
            cout << "NO" << endl;
            continue;
        }
        int p = lca(u, v);
        if (t == 1){
            if (p != u){
                cout << "NO" << endl;
                continue;
            }
            if (os[v] >= depth[v] - depth[u]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{
            if (p == v){
                cout << "NO" << endl;
                continue;
            }
            bool can = true;
            if (depth[v] - depth[p] > ch[v]) can = false;
            if (depth[u] - depth[p] > os[u]) can = false;
            if (can) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}