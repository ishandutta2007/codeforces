#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100010
#define MAXM 100010
#define LL long long
int head[MAXN], nxt[MAXM << 1], to[MAXM << 1], tot;
LL val[MAXM << 1];
void addedge(int b, int e, LL v) {
    nxt[++tot] = head[b]; head[b] = tot; to[tot] = e; val[tot] = v;
    nxt[++tot] = head[e]; head[e] = tot; to[tot] = b; val[tot] = v;
}
struct deb {
    LL a[64];
    void insert(LL x) {
        for (int i = 63; ~i; --i)
            if (1LL << i & x)
                if (!a[i]) {a[i] = x; break;}
                else x ^= a[i];
    }
    LL query(LL val = 0) {
        LL res = val;
        for (int i = 63; ~i; --i)
            if ((res ^ a[i]) < res)
                res ^= a[i];
        return res;
    }
} deber;
LL debian[MAXN]; bool vis[MAXN];
void dfs(int u, LL v) {
    debian[u] = v; vis[u] = true;
    for (int i = head[u]; i; i = nxt[i])
        if (!vis[to[i]]) dfs(to[i], v ^ val[i]);
        else deber.insert(v ^ val[i] ^ debian[to[i]]);
}
int n, m, t1, t2;
LL t3;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%lld", &t1, &t2, &t3);
        addedge(t1, t2, t3);
    }
    dfs(1, 0);
    printf("%lld\n", deber.query(debian[n]));
    return 0;
}