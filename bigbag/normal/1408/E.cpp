#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int m, n, a[max_n], b[max_n], p[max_n], last[max_n];
vector<pair<int, pair<int, int>>> all;

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

bool union_set(int v1, int v2) {
    if (v1 == -1 || v2 == -1) {
        return true;
    }
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 == v2) {
        return false;
    }
    p[v1] = v2;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        last[i] = -1;
        while (k--) {
            int x;
            scanf("%d", &x);
            --x;
            all.push_back({a[i] + b[x], {i, x}});
            ans += all.back().first;
        }
    }
    sort(all.rbegin(), all.rend());
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (auto p : all) {
        if (union_set(p.second.second, last[p.second.first])) {
            last[p.second.first] = p.second.second;
            ans -= p.first;
        }
    }
    cout << ans << "\n";
    return 0;
}