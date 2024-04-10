#include <cstdio>
#include <cstring>
#include <vector>

static const int MAXN = 1e6 + 4;
static const int MAXK = 21;

static int n, m;
static std::vector<int> e[MAXN];
static int d_in[MAXN] = { 0 };

static int sct = 0, tct = 0, sf[MAXK];
static int f[MAXN];

static void calc(int u)
{
    if (f[u] != -1) return;
    f[u] = 0;
    for (int v : e[u]) {
        calc(v);
        f[u] |= f[v];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        ++d_in[v];
    }

    memset(f, -1, sizeof f);
    for (int i = 0; i < n; ++i) if (e[i].empty()) f[i] = 1 << (tct++);

    for (int i = 0; i < n; ++i) calc(i);
    for (int i = 0; i < n; ++i) if (d_in[i] == 0) sf[sct++] = f[i];

    for (int mask = 1; mask < (1 << sct) - 1; ++mask) {
        int sum = 0;
        for (int i = 0; i < sct; ++i)
            if (mask & (1 << i)) sum |= sf[i];
        if (__builtin_popcount(sum) <= __builtin_popcount(mask)) {
            puts("NO"); return 0;
        }
    }

    puts("YES"); return 0;
}