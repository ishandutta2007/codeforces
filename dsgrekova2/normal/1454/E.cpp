#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
vector<vector<int>> bg;
vector<vector<int>> g;
vector<int> vmass;
vector<bool> seen;
vector<int> tof;
pair<int, int> bad;
int dfsmass(int v, int p){
    vmass[v] = 1;
    for (auto i : g[v]) {
        if(i == p)
            continue;
        vmass[v] += dfsmass(i, v);
    }
    return vmass[v];
}
void dfstof(int v, int p){
    tof[v] = p;
    for (auto i : g[v]) {
        if(i != p)
            dfstof(i, v);
    }
}
void dfs(int v, int p){
    if(seen[v]){
        bad = {p, v};
        return;
    }
    if(p != -1) {
        g[v].push_back(p);
        g[p].push_back(v);
    }
    seen[v] = true;
    for (auto i : bg[v]){
        if(i == p)
            continue;
        dfs(i, v);
    }
}
void PolnalyubviTop(){
    g.clear();
    bg.clear();
    vmass.clear();
    tof.clear();
    seen.clear();
    int n;
    cin >> n;
    tof.assign(n, -1);
    g.assign(n, {});
    bg.assign(n, {});
    vmass.assign(n, 0);
    seen.assign(n, false);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        bg[a].push_back(b);
        bg[b].push_back(a);
    }
    dfs(0, -1);
    int s = bad.first, f = bad.second;
    dfsmass(s, -1);
    dfstof(f, -1);
    int ans = n * (n - 1) / 2;
    while(s != f){
        ans += (vmass[s] - vmass[tof[s]]) * vmass[tof[s]];
        s = tof[s];
    }
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}