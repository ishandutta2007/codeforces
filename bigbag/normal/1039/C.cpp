#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, mod = 1000000007;

int n, m, k, parent[max_n], cur, last[max_n];
long long a[max_n], pw[max_n];
vector<pair<long long, pair<int, int>>> all;

void clr() {
    ++cur;
}

int find_set(int v) {
    if (last[v] != cur) {
        last[v] = cur;
        parent[v] = v;
    }
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (rand() % 2) {
        swap(u, v);
    }
    parent[u] = v;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (2LL * pw[i - 1]) % mod;
    }
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        all.push_back({a[u] ^ a[v], {u, v}});
    }
    sort(all.begin(), all.end());
    long long cnt_x = 1LL << k, ans = 0;
    for (int i = 0; i < all.size(); ) {
        --cnt_x;
        int pos = i;
        clr();
        int comp = n;
        while (i < all.size() && all[i].first == all[pos].first) {
            int u = all[i].second.first;
            int v = all[i].second.second;
            ++i;
            if (find_set(u) != find_set(v)) {
                --comp;
                union_set(u, v);
            }
        }
        ans += pw[comp];
        ans %= mod;
    }
    cnt_x %= mod;
    ans += (cnt_x * pw[n]) % mod;
    ans %= mod;
    printf("%d\n", ans);
    return 0;
}