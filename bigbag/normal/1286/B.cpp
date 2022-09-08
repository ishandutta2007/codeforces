#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int n, c[max_n], sz[max_n], a[max_n];
vector<int> g[max_n];

void add(int v, int x) {
    a[v] += x;
    for (int to : g[v]) {
        add(to, x);
    }
}

void increase(int v, int x) {
    if (a[v] > x) {
        ++a[v];
    }
    for (int to : g[v]) {
        increase(to, x);
    }
}

void dfs(int v) {
    for (int to : g[v]) {
        dfs(to);
        sz[v] += sz[to];
    }
    if (c[v] > sz[v]) {
        puts("NO");
        exit(0);
    }
    ++sz[v];
    int x = 0;
    for (int to : g[v]) {
        add(to, x);
        x += sz[to];
    }
    for (int to : g[v]) {
        increase(to, c[v]);
    }
    a[v] = c[v] + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int root;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int p;
        scanf("%d%d", &p, &c[i]);
        --p;
        if (p == -1) {
            root = i;
        } else {
            g[p].push_back(i);
        }
    }
    dfs(root);
    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}