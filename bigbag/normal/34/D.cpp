#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 51111, inf = 111111111;

int n, r1, r2, ans[max_n], used[max_n];
vector <int> g[max_n];

void dfs(int v, int p) {
    ans[v] = p;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i], v);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> r1 >> r2;
    int num = 1;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        if (num == r1) {
            ++num;
        }
        g[x].push_back(num);
        g[num].push_back(x);
        ++num;
    }
    dfs(r2, -1);
    for (int i = 1; i <= n; ++i) {
        if (i != r2) {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}