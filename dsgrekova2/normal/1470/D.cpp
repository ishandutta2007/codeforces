#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "complex"
#include "cassert"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define EPS 1e-11
typedef long long int ll;
typedef long double ld;
using namespace std;
vector<vector<int>> g;
vector<int> color;
int bad;
void dfs(int v){
    if (color[v] == -1){
        color[v] = 1;
        for (auto i : g[v]){
            if (color[i] == -1)
                color[i] = 2;
        }
        for (auto i : g[v]){
            dfs(i);
        }
    }
    if (color[v] == 2){
        color[v] = 0;
        for (auto i : g[v]){
            dfs(i);
        }
    }
}
void ds(){
    int n;
    bad = 0;
    cin >> n;
    g.assign(n, {});
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    color.assign(n, -1);
    dfs(0);
    if (bad){
        cout << "NO\n";
        return;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 1)
            ans.push_back(i + 1);
        if (color[i] == -1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ds();
    }
}