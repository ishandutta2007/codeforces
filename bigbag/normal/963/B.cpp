#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

int n, sz[max_n], p[max_n], cnt[max_n], used[max_n], bad[max_n];
vector<int> g[max_n];
set<int> ok;

void dfs(int v, int parent) {
    p[v] = parent;
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != parent) {
            dfs(to, v);
            sz[v] ^= sz[to];
        }
    }
}

void add(int v) {
    //cout << "+ " << v << endl;
    ok.insert(v);
}

void del(int v) {
    if (ok.count(v)) {
        //cout << "- " << v << endl;
        ok.erase(v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        if (p) {
            g[p].push_back(i);
            g[i].push_back(p);
        }
    }
    if (n % 2 == 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = g[i].size();
        bool can = ((cnt[i] % 2) == 0);
        for (int to : g[i]) {
            if (sz[to] == 0 && p[to] == i) {
                ++bad[i];
            }
        }
        if (can && bad[i] == 0) {
            add(i);
        }
    }
    while (!ok.empty()) {
        int v = *ok.begin();
        ok.erase(v);
        used[v] = 1;
        printf("%d\n", v);
        for (int to : g[v]) {
            if (used[to]) {
                continue;
            }
            --cnt[to];
        }
        if (sz[v] == 0 && p[v] != -1) {
            --bad[p[v]];
        }
        for (int to : g[v]) {
            if (used[to]) {
                continue;
            }
            if (cnt[to] % 2 == 0 && bad[to] == 0) {
                add(to);
            } else if (ok.count(to)) {
                del(to);
            }
        }
    }
    return 0;
}