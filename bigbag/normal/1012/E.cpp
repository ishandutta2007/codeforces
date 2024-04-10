#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, s, cnt, to[max_n];
int a[max_n], b[max_n], pos[max_n];
vector<int> all[max_n];

void compress() {
    pair<int, int> p[max_n];
    for (int i = 0; i < n; ++i) {
        p[i] = {a[i], i};
    }
    sort(p, p + n);
    int num = 0;
    for (int i = 0; i < n; ) {
        int start = i;
        while (i < n && p[i].first == p[start].first) {
            a[p[i].second] = num;
            ++i;
        }
        ++num;
    }
}

vector<vector<int>> cycles;
vector<pair<int, int>> g[max_n];
int parent[max_n];

void init() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    parent[v1] = v2;
}

void find_all_cycles() {
    cycles.clear();
    bool used[max_n];
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0 && to[i] != -1) {
            int pos = i;
            vector<int> cycle;
            while (used[pos] == 0) {
                used[pos] = 1;
                cycle.push_back(pos);
                g[a[pos]].push_back({cycles.size(), pos});
                pos = to[pos];
            }
            cycles.push_back(cycle);
        }

    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    compress();
    copy(a, a + n, b);
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            all[a[i]].push_back(i);
        }
        to[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            int p = all[b[i]][pos[b[i]]++];
            to[p] = i;
            ++cnt;
        }
    }
    if (cnt > s) {
        puts("-1");
        return 0;
    }
    find_all_cycles();
    init();
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 1) {
            const pair<int, int> &first = g[i][0];
            for (const pair<int, int> &p : g[i]) {
                if (find_set(first.first) != find_set(p.first)) {
                    union_set(first.first, p.first);
                    swap(to[first.second], to[p.second]);
                }
            }
        }
    }
    find_all_cycles();
    int ans = cycles.size();
    if (s - cnt) {
        int q = min((int) cycles.size(), s - cnt);
        if (q >= 3) {
            ans += 2 - q;
            printf("%d\n", ans);
            vector<int> v;
            printf("%d\n", q);
            for (int i = 0; i < q; ++i) {
                v.push_back(cycles[i][0]);
                printf("%d ", cycles[i][0] + 1);
            }
            printf("\n");
            int cp = to[v.back()];
            for (int i = v.size() - 1; i > 0; --i) {
                to[v[i]] = to[v[i - 1]];
            }
            to[v[0]] = cp;
            find_all_cycles();
        } else {
            printf("%d\n", ans);
        }
    } else {
        printf("%d\n", ans);
    }
    for (const vector<int> &cycle : cycles) {
        printf("%d\n", cycle.size());
        for (int pos : cycle) {
            printf("%d ", pos + 1);
        }
        printf("\n");
    }
    return 0;
}