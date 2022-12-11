// 549B - Looksery Party
#include <cstdio>
#include <list>
static const int MAXN = 1e5 + 3;
static const int MAXM = 2e5 + 3;

int n, m;
int a[MAXN];
bool push[MAXN] = { false }; int push_count = 0;
int head[MAXN], dest[MAXM], next[MAXM];
inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}
std::list<int> zeroes;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0; i < n; ++i) if (a[i] == 0) zeroes.push_back(i);
    while (!zeroes.empty()) {
        int r = zeroes.front(); zeroes.pop_front(); if (a[r] != 0) continue;
        a[r] -= 1; push[r] = true; ++push_count;
        for (int w = head[r]; w != -1; w = next[w])
            if (--a[dest[w]] == 0) zeroes.push_back(dest[w]);
    }

    printf("%d\n", push_count);
    for (int i = 0; i < n; ++i) if (push[i]) printf("%d ", i + 1); putchar('\n');
    return 0;
}