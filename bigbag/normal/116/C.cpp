#include <map>
#include <set>
#include <stack>
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

const int max_n = 2222, inf = 1111111111;

int n, ans, mx, p[max_n];
vector<int> g[max_n];

void dfs(int v, int lev) {
    mx = max(mx, lev);
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i], lev + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (p[i] == -1) {
            mx = 0;
            dfs(i, 1);
            ans = max(ans, mx);
        }
    }
    cout << ans << endl;
    return 0;
}