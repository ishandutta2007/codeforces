#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], used[max_n], last[max_n];
vector<int> g[max_n], b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (a[0] != 1) {
        puts("No");
        return 0;
    }
    queue<int> q;
    q.push(a[0]);
    used[a[0]] = 1;
    int cur = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int cnt = 0;
        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = 1;
                last[to] = v;
                ++cnt;
            }
        }
        for (int j = cur; j < cur + cnt; ++j) {
            if (last[a[j]] != v) {
                puts("No");
                return 0;
            }
            q.push(a[j]);
        }
        cur += cnt;
    }
    puts("Yes");
    return 0;
}