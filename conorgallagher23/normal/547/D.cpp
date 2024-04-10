#include <bits/stdc++.h>
using namespace std;
int read();
int n;
int hd[400005], nx[800005], to[800005], cnt;
int deg[800005];
void add(int f, int t) {
    nx[++cnt] = hd[f], hd[f] = cnt, to[cnt] = t, ++deg[f];
}
struct E {
    int u, v;
    void init() { u = read(), v = read() + 200000, add(u, v), add(v, u); }
} p[200005];
bool vis[800005];
int res[200005];

int tcc;
void dfs(int u) {
    for (int &i = hd[u], e; i; i = nx[i])
        if (!vis[e = i >> 1])
            vis[e] = 1, (e <= n ? (res[e] = (u <= 200000)) : 0), dfs(to[i]);
}

int main() {
    n = read(), cnt = 1;
    for (int i = 1; i <= n; ++i) p[i].init();
    for (int i = 1; i <= 400000; ++i)
        if (deg[i] & 1) add(0, i), add(i, 0);
    for (int i = 1; i <= 400000; ++i) dfs(i);
    for (int i = 1; i <= n; ++i) putchar(res[i] ? 'r' : 'b');
    return 0;
}
const int _SIZE = 1 << 22;
char ibuf[_SIZE], *iS = ibuf, *iT = ibuf;
#define gc                                                         \
    (iS == iT ? iT = ((iS = ibuf) + fread(ibuf, 1, _SIZE, stdin)), \
     (iS == iT ? EOF : *iS++) : *iS++)
int read() {
    int x = 0, f = 1;
    char c = gc;
    while (!isdigit(c)) f = (c == '-') ? -1 : f, c = gc;
    while (isdigit(c)) x = x * 10 + c - '0', c = gc;
    return x * f;
}