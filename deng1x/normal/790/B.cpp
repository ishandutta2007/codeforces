#include <bits/stdc++.h>

#define MAXN (200010)
#define ll long long

int n, k;
std::vector<int> vec[MAXN];
ll ans;

std::vector<int> dfs(int u, int p) {
    std::vector<int> all;
    all.resize(k);
    all[0] = 1;
    int sum = 1;
    for (auto v : vec[u]) {
        if (v == p) continue;

        auto sub = dfs(v, u);
        std::rotate(sub.begin(), sub.begin() + k - 1, sub.end());

        for (int i = 0; i < k; ++i) sum += sub[i];
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (!((i + j) % k)) continue;
                ans += 1ll * all[i] * sub[j] * (k - (i + j) % k);
            }
        }
        for (int i = 0; i < k; ++i) all[i] += sub[i];
    }
    ans += 1ll * sum * (n - sum);
    return all;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 0);
    assert(!(ans % k));
    printf("%lld\n", ans / k);
    return 0;
}