#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m, cur, used[max_n];
vector<int> g[max_n];
vector<int> cycle;

void wa() {
    printf("-1\n");
    exit(0);
}

double st = clock();

bool is_tl() {
    if ((clock() - st) / CLOCKS_PER_SEC > 0.9) {
        return true;
    }
    return false;
}

bool dfs(int v) {
    used[v] = cur;
    for (int to : g[v]) {
        if (used[to] == cur + 1) {
            continue;
        }
        if (used[to] == cur) {
            cycle.push_back(v);
            return true;
        } else {
            if (dfs(to)) {
                cycle.push_back(v);
                return true;
            }
        }
    }
    used[v] = cur + 1;
    return false;
}

vector<int> perm;

bool has_cycle(int v = 0) {
    cur += 2;
    cycle.clear();
    used[v] = cur + 1;
    for (int i : perm) {
        if (used[i] < cur) {
            if (dfs(i)) {
                return true;
            }
        }
    }
    return false;
}

int cnt[max_n];

int main() {
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        perm.push_back(i);
    }
    random_shuffle(perm.begin(), perm.end());
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    has_cycle();
    vector<int> p = cycle;
    random_shuffle(p.begin(), p.end());
    int it = 0;
    for (int v : p) {
        if (cnt[v] < it) {
            continue;
        }
        if (!has_cycle(v)) {
            printf("%d\n", v);
            return 0;
        }
        ++it;
        for (int v : cycle) {
            ++cnt[v];
        }
        if (is_tl()) {
            wa();
        }
    }
    wa();
    return 0;
}