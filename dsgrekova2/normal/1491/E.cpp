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
#define all(x) (x).begin(), (x).end()
#define ll long long
#define int ll
using namespace std;
vector<int> edge;
vector<vector<pair<int, int>>> g;
vector<int> sz;
vector<int> fibnum;
void dfs(int v, int p, pair<int, pair<int, int>> &res, int fib1, int fib2){
    sz[v] = 1;
    for (auto [i, ex] : g[v]){
        if (!edge[ex] or i == p)
            continue;
        dfs(i, v, res, fib1, fib2);
        sz[v] += sz[i];
        if (sz[i] == fib1){
            res = {ex, {i, 1}};
        }
        if (sz[i] == fib2){
            res = {ex, {i, 2}};
        }
    }
}
bool slvv0(int v, int fibpos){
    if (fibpos <= 3)
        return true;
    pair<int, pair<int, int>> res = {-1, {-1, -1}};
    dfs(v, -1, res, fibnum[fibpos-1], fibnum[fibpos-2]);
    if (res == pair<int, pair<int, int>>{-1, {-1, -1}}){
        return false;
    }
    edge[res.first] = 0;
    return (slvv0(v, fibpos - (3 - res.second.second)) and slvv0(res.second.first, fibpos - res.second.second));
}
void solve(){
    int n;
    fibnum.push_back(1);
    fibnum.push_back(1);
    cin >> n;
    while (fibnum.back() < n){
        fibnum.push_back(fibnum.back() + fibnum[fibnum.size() - 2]);
    }
    if (fibnum.back() != n){
        cout << "NO";
        return;
    }
    sz.assign(n, 0);
    g.assign(n, {});
    edge.assign(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    if (slvv0(0, fibnum.size() - 1)){
        cout << "YES";
    }else{
        cout << "NO";
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}