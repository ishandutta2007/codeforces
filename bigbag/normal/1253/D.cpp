#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, p[max_n], sz[max_n], mn[max_n], mx[max_n];
int ans;

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 == v2) {
        return;
    }
    if (sz[v1] > sz[v2]) {
        swap(v1, v2);
    }
    p[v1] = v2;
    sz[v2] += sz[v1];
    mn[v2] = min(mn[v2], mn[v1]);
    mx[v2] = max(mx[v2], mx[v1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        p[i] = mn[i] = mx[i] = i;
        sz[i] = 1;
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        union_set(u, v);
    }
    for (int i = 0; i < n; ++i) {
        int id = find_set(i);
        int pos = i;
        while (mx[id] - mn[id] + 1 != sz[id]) {
            ++pos;
            if (find_set(pos) != id) {
                union_set(pos, id);
                ++ans;
            }
            id = find_set(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}