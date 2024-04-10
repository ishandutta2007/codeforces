#include <bits/stdc++.h>

#define MAXN (100010)

int n, m;
char s[MAXN];
bool uni[MAXN];

namespace twoSat {
    std::vector<int> vec[MAXN << 1];
    std::vector<int> mat[MAXN << 1];
    int mine[MAXN << 1];
    bool hasu[MAXN << 1];
    bool tmpu[MAXN << 1];
    int du[MAXN << 1];
    int dfn[MAXN << 1], low[MAXN << 1], bel[MAXN << 1], ncnt, scnt;
    bool vis[MAXN << 1];
    std::stack<int> stack;

    void tarjan(int u) {
        dfn[u] = low[u] = ++ncnt;
        stack.push(u);
        vis[u] = true;
        for (auto &v : vec[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (vis[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            int v;
            ++scnt;
            do {
                v = stack.top(); stack.pop();
                vis[v] = false;
                bel[v] = scnt;
            } while (v != u);
        }
    }

    bool solve() {
        ncnt = scnt = 0;
        for (int i = 1; i <= n + n; ++i) {
            if (!dfn[i]) {
                tarjan(i);
            }
            mine[i] = -1;
        }
        for (int i = 1; i <= n; ++i) {
            if (bel[i] == bel[i + n]) {
                return false;
            }
        }
        for (int i = 1; i <= n + n; ++i) {
            int u = i > n ? i - n : i;
            if (uni[u]) {
                if (hasu[bel[i]]) return false;
                hasu[bel[i]] = true;
            } else {
                if (mine[bel[i]] == -1 || mine[bel[i]] > u) {
                    mine[bel[i]] = u;
                }
            }
        }
        for (int i = 1; i <= n + n; ++i) {
            int u = i > n ? i - n : i;
            if (uni[u]) {
                if (mine[bel[i]] != -1 && u > mine[bel[i]]) {
                    return false;
                }
            }
        }
        for (int i = 1; i <= n + n; ++i) {
            for (auto &j : vec[i]) {
                if (bel[i] != bel[j]) {
                    mat[bel[j]].push_back(bel[i]);
                    ++du[bel[i]];
                }
            }
        }
        std::queue<int> queue;
        for (int i = 1; i <= scnt; ++i) {
            if (!du[i]) {
                queue.push(i);
            }
        }
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            hasu[u] |= tmpu[u];
            for (auto &v : mat[u]) {
                if (hasu[u] && hasu[v]) return false;
                tmpu[v] |= hasu[u];
                if (!(--du[v])) {
                    queue.push(v);
                }
            }
        }
        return true;
    }

    void clear() {
        for (int i = 1; i <= n + n; ++i) {
            std::vector<int>().swap(vec[i]);
            std::vector<int>().swap(mat[i]);
            dfn[i] = 0;
            vis[i] = false;
            tmpu[i] = hasu[i] = false;
            du[i] = 0;
        }
    }
}

int opp(int u) {
    if (u <= n) return u + n;
    return u - n;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; ++i) {
            uni[i] = s[i] == 'A';
        }
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u < 0) u = n - u;
            if (v < 0) v = n - v;
            twoSat::vec[opp(u)].push_back(v);
            twoSat::vec[opp(v)].push_back(u);
        }
        puts(twoSat::solve() ? "TRUE" : "FALSE");
        twoSat::clear();
    }
    return 0;
}