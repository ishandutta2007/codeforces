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

const int max_n = 222222, inf = 1011111111;

int n, t, k, v, a[max_n];
int mn[max_n], mx[max_n];
int sum1[max_n];
int sum2[max_n];
vector<int> all[max_n];

int b[max_n];
vector<int> g[max_n];

void add(int p, int lev) {
    ++v;
    g[p].push_back(v);
    all[lev].push_back(v);
    printf("%d %d\n", p, v);
}

void dfs(int v, int lev) {
    ++b[lev];
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i], lev + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &t, &k);
    for (int i = 1; i <= t; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = t; i >= 1; --i) {
        mn[i] = a[i] - min(a[i], a[i + 1]);
        mx[i] = a[i] - min(1, a[i + 1]);
        sum1[i] = mn[i] + sum1[i + 1];
        sum2[i] = mx[i] + sum2[i + 1];
    }
    //cout << sum1[1] << " " << sum2[1] << endl;
    if (sum1[1] <= k && k <= sum2[1]) {
        printf("%d\n", n);
        all[0].push_back(1);
        a[0] = 1;
        v = 1;
        for (int i = 0; i < t; ++i) {
            int x = max(mn[i], k - sum2[i + 1]);
            k -= x;
            x = a[i] - x;
            for (int j = 0; j < x; ++j) {
                add(all[i][j], i + 1);
            }
            for (int j = x; j < a[i + 1]; ++j) {
                add(all[i][0], i + 1);
            }
        }

        if (0) {
            dfs(1, 0);
            for (int i = 1; i <= t; ++i) {
                cout << b[i] << " ";
            }
        }
    } else {
        printf("-1\n");
    }
    return 0;
}