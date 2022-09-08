#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_m = 300333;
const int max_q = 500555;

int n, m, q, a[max_n], p[max_n];
vector<int> all[max_n];
int from[max_m], to[max_m], del[max_m];
int tp[max_q], num[max_q];
pair<int, int> upd[max_q];
set<int> cur[max_n];

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return find_set(p[v]);
}

pair<int, int> union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 == v2) {
        return {-1, -1};
    }
    if (all[v1].size() > all[v2].size()) {
        swap(v1, v2);
    }
    p[v1] = v2;
    for (int v : all[v1]) {
        all[v2].push_back(v);
    }
    return {v1, v2};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &from[i], &to[i]);
        --from[i];
        --to[i];
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &tp[i], &num[i]);
        --num[i];
        if (tp[i] == 2) {
            del[num[i]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        all[i].push_back(i);
        p[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (!del[i]) {
            union_set(from[i], to[i]);
        }
    }
    for (int i = q - 1; i >= 0; --i) {
        if (tp[i] == 2) {
            const int id = num[i];
            upd[i] = union_set(from[id], to[id]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] == i) {
            for (int v : all[i]) {
                cur[i].insert(a[v]);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if (tp[i] == 1) {
            int root = find_set(num[i]);
            int ans = 0;
            if (!cur[root].empty()) {
                auto it = --cur[root].end();
                ans = *it;
                cur[root].erase(it);
            }
            printf("%d\n", ans);
        } else {
            if (upd[i].first == -1) {
                continue;
            }
            //cout << "#" << upd[i].first << " " << upd[i].second << endl;
            p[upd[i].first] = upd[i].first;
            for (int v : all[upd[i].first]) {
                int x = a[v];
                auto it = cur[upd[i].second].find(x);
                if (it != cur[upd[i].second].end()) {
                    cur[upd[i].second].erase(it);
                    cur[upd[i].first].insert(x);
                }
            }
        }
    }
    return 0;
}