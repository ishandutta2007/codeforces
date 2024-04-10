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
#include <queue>
#define int long long
using namespace std;
int MOD = 1000000007;
int binup[100000][18];
int n, ai, bi, wi, k, timer, ans;
vector<vector<pair<int, int> > > data;
vector<int> tin, tout, upp, dpp, steps;
void dfs(int vertex, int last){
    tin[vertex] = timer;
    timer++;
    if (last != -1){
        int nv = last;
        binup[vertex][0] = last;
        int X = 0;
        while (binup[nv][X] != -1){
            binup[vertex][X+1] = binup[nv][X];
            nv = binup[nv][X];
            X++;
        }
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].first;
        if (last == to) continue;
        dfs(to, vertex);
    }
    tout[vertex] = timer;
    timer++;
}
int LCA(int v, int u){
    //cout << tin[v] << " " << tin[u] << endl;
    if (tin[u] >= tin[v] && tout[u] <= tout[v]) return v;
    if (tin[v] >= tin[u] && tout[v] <= tout[u]) return u;
    int X = 17;
    while (X >= 0){
        int f = binup[v][X];
        if (f == -1){
            X--;
            continue;
        }
        if (tin[f] <= tin[u] && tout[f] >= tout[u]){
            X--;
            continue;
        }
        v = f;
        X--;
    }
    return binup[v][0];
}
pair<int, int> dfs2(int vertex, int last){
    int U = 0;
    int D = 0;
    bool can = false;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].first;
        if (last == to){
            if (data[vertex][i].second){
                can = true;
            }
            continue;
        }
        pair<int, int> p = dfs2(to, vertex);
        int cand = steps[p.second];
        if (data[vertex][i].second) ans += cand - 1;
        U += p.first;
        D += p.second;
    }
    U += upp[vertex];
    D += dpp[vertex];
    if (can){
        int cand = steps[U];
        ans += cand - 1;
    }
    return make_pair(U, D);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i < n; i++){
        vector<pair<int, int> > help;
        data.push_back(help);
        tin.push_back(0);
        tout.push_back(0);
        upp.push_back(0);
        dpp.push_back(0);
    }
    for (int i=0; i < n-1; i++){
        cin >> ai >> bi >> wi;
        data[ai-1].push_back(make_pair(bi-1, 0));
        data[bi-1].push_back(make_pair(ai-1, wi));
    }
    for (int i=0; i < 100000; i++){
        for (int j=0; j < 18; j++){
            binup[i][j] = -1;
        }
    }
    timer=0;
    dfs(0, -1);
    int K;
    cin >> K;
    vector<int> V;
    for (int i=0; i < K; i++){
        int A;
        cin >> A;
        V.push_back(A-1);
    }
    int old = 0;
    for (int i=0; i < K; i++){
        int nv = V[i];
        int L = LCA(old, nv);
        upp[old]++;
        upp[L]--;
        dpp[nv]++;
        dpp[L]--;
        old = nv;
    }
    int N = 1;
    for (int i=0; i < 2e6; i++){
        steps.push_back(N);
        N *= 2;
        N %= MOD;
    }
    ans = 0;
    dfs2(0, -1);
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}