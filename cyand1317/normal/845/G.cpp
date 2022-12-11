#include <cstdio>
#include <vector>
static const int MAXN = 100005;
static const int MAXM = 200006;
static const int LOGW = 30;

int n, m;
int head[MAXN], dest[MAXM], wgh[MAXM], next[MAXM];

inline void add_edge(int u, int v, int w)
{
    static int _m = 0;
    dest[_m] = v; wgh[_m] = w; next[_m] = head[u]; head[u] = _m++;
}

template <int SZ> struct linear_basis {
    int r[SZ];
    void clear() { for (int i = 0; i < SZ; ++i) r[i] = 0; }
    linear_basis() { this->clear(); }

    inline void insert(int x) {
        for (int i = SZ - 1; i >= 0; --i) if (x & (1LL << i)) {
            if (r[i] == 0) {
                for (int j = i - 1; j >= 0; --j) if (x & (1LL << j)) x ^= r[j];
                for (int j = i + 1; j < SZ; ++j) if (r[j] & (1LL << i)) r[j] ^= x;
                r[i] = x; break;
            } else {
                x ^= r[i];
            }
        }
    }
};

int oxo[MAXN];
linear_basis<LOGW> b;

void dfs(int u, int in)
{
    for (int w = head[u]; w != -1; w = next[w]) if (w != (in ^ 1)) {
        if (oxo[dest[w]] == -1) {
            oxo[dest[w]] = oxo[u] ^ wgh[w];
            dfs(dest[w], w);
        } else {
            b.insert(oxo[dest[w]] ^ oxo[u] ^ wgh[w]);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w); --u, --v;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    oxo[0] = 0;
    for (int i = 1; i < n; ++i) oxo[i] = -1;
    dfs(0, -114514);

    int quq = oxo[0] ^ oxo[n - 1];
    for (int i = LOGW - 1; i >= 0; --i)
        if (b.r[i] != 0 && (quq & (1 << i)))
            quq ^= b.r[i];
    printf("%d\n", quq);

    return 0;
}