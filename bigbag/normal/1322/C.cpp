#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

int t, n, m, p[max_n];
long long a[max_n];
vector<int> g[max_n];

bool cmp(int u, int v) {
    return g[u] < g[v];
}

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &a[i]);
            p[i] = i;
        }
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[v].push_back(u);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end());
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; ) {
            long long sum = 0;
            int pos = i;
            while (i < n && g[p[i]] == g[p[pos]]) {
                sum += a[p[i]];
                ++i;
            }
            if (!g[p[pos]].empty()) {
                ans = __gcd(ans, sum);
            }
        }
        printf("%I64d\n", ans);
        clr();
    }
    return 0;
}