#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, q, comp, usedx[max_n], usedy[max_n], x[max_n], y[max_n];
vector<int> gx[max_n], gy[max_n], xs, ys;
long long ans;

void dfs(int x, int y) {
    if (!usedx[x]) {
        usedx[x] = 1;
        for (int toy : gx[x]) {
            dfs(x, toy);
        }
    }
    if (!usedy[y]) {
        usedy[y] = 1;
        for (int tox : gy[y]) {
            dfs(tox, y);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        xs.push_back(x[i]);
        ys.push_back(y[i]);
        gx[x[i]].push_back(y[i]);
        gy[y[i]].push_back(x[i]);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for (int i = 0; i < q; ++i) {
        if (usedx[x[i]] == 0 || usedy[y[i]] == 0) {
            dfs(x[i], y[i]);
            ++comp;
        }
    }
    int ans = comp - 1 + n - xs.size() + m - ys.size();
    printf("%d\n", ans);
    return 0;
}