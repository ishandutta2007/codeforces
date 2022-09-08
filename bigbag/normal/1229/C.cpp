#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m, q, sz[max_n];
vector<int> more[max_n];

long long val(int v) {
    return 1LL * more[v].size() * (sz[v] - more[v].size());
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        ++sz[u];
        ++sz[v];
        if (u > v) {
            swap(u, v);
        }
        more[u].push_back(v);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += val(i);
    }
    printf("%I64d\n", ans);
    scanf("%d", &q);
    while (q--) {
        int v;
        scanf("%d", &v);
        ans -= val(v);
        while (!more[v].empty()) {
            int u = more[v].back();
            more[v].pop_back();
            ans -= val(u);
            more[u].push_back(v);
            ans += val(u);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}