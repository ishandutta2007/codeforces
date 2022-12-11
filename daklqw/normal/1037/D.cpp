#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 200010
bool vis[MAXN], inq[MAXN], mark[MAXN];
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot, t1, t2, n, deg[MAXN], li[MAXN], bak, out[MAXN];
inline void addedge(int b, int e) { 
    nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
    nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
    ++deg[b]; ++deg[e];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i != n; ++i) {
        scanf("%d%d", &t1, &t2);
        addedge(t1, t2);
    }
    addedge(0, 1);
    for (int i = 1; i <= n; ++i) --deg[i];
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int t = q.front(); q.pop(); vis[t] = true;
        for (int i = 1; i <= deg[t]; ++i) { scanf("%d", &out[i]); mark[out[i]] = true; q.push(out[i]); }
        for (int i = head[t]; i; i = nxt[i]) if (!vis[to[i]] && !mark[to[i]]) return puts("No"), 0;
        for (int i = 1; i <= deg[t]; ++i) mark[out[i]] = false;
    }
    return  puts("Yes"), 0;
}