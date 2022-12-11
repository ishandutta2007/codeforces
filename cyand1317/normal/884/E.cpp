#include <cstdio>
#include <cstdlib>
#include <cstring>
static const int MAXN = (1 << 12) + 3;
static const int MAXM = (1 << 12) + 4;

int n, m;
int s[MAXM], t[MAXM];

inline int hex(const char c)
{
    if (c >= '0' && c <= '9') return c - '0'; else return c - 'A' + 10;
}

inline bool col(const int *s, int pos)
{
    return (s[pos >> 2] >> ((3 - pos & 3))) & 1;
}

namespace dsu {
    int p[MAXM * 8];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline bool merge(int u, int v) { if ((u = root(u)) != (v = root(v))) { if (rand() & 1) p[u] = v; else p[v] = u; return true; } else return false; }
}

int rep[MAXM * 8];

int main()
{
    srand(20171028);
    scanf("%d%d", &n, &m); m /= 4;

    for (int i = 0; i < m; ++i) t[i] = 0;
    for (int i = 0; i < m * 8; ++i) dsu::p[i] = -1;

    int scc = 0;

    for (int i = 0; i < n; ++i) {
        getchar();
        for (int j = 0; j < m; ++j) s[j] = hex(getchar());

        for (int j = 0; j < m * 4; ++j) if (col(s, j)) {
            if (col(t, j)) {
                dsu::p[m * 4 + j] = dsu::p[j];
                if (j > 0 && col(s, j - 1) && dsu::merge(m * 4 + j - 1, m * 4 + j))
                    --scc;
            } else {
                if (j > 0 && col(s, j - 1)) {
                    dsu::p[m * 4 + j] = dsu::p[m * 4 + j - 1];
                } else {
                    dsu::p[m * 4 + j] = m * 4 + j;
                    ++scc;
                }
            }
        }

        for (int j = 0; j < m * 8; ++j) if (dsu::p[j] != -1) dsu::root(j);
        for (int j = 0; j < m * 4; ++j) dsu::p[j] = dsu::p[m * 4 + j];
        for (int j = 0; j < m * 8; ++j) rep[j] = -1;
        for (int j = 0; j < m * 4; ++j) {
            if (rep[dsu::p[j]] == -1) rep[dsu::p[j]] = j;
            dsu::p[j] = rep[dsu::p[j]];
        }

        memcpy(t, s, sizeof s);
    }

    printf("%d\n", scc);
    return 0;
}