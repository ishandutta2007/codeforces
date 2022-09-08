#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, p[max_n], h[max_n], mxh[max_n];
vector<int> g[max_n], order, ans;

bool cmp(int a, int b) {
    return mxh[a] < mxh[b];
}

void solve(int v) {
    order.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        solve(g[v][i]);
        if (i) {
            for (int j = 0; j < mxh[g[v][i - 1]] - h[v]; ++j) {
                ans.push_back(g[v][i]);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
        h[i] = h[p[i]] + 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        mxh[i] = h[i];
        for (int to : g[i]) {
            mxh[i] = max(mxh[i], mxh[to]);
        }
        sort(g[i].begin(), g[i].end(), cmp);
    }
    solve(0);
    for (int v : order) {
        printf("%d ", v);
    }
    printf("\n%d\n", ans.size());
    for (int v : ans) {
        printf("%d ", v);
    }
    puts("");
    return 0;
}