#include <cstdio>
static const int MAXN = 998;
static const int LEVELS = 30;

int k;
int n, last_n;
bool a[MAXN][MAXN] = {{ false }};
inline void add_edge(int u, int v) { a[u][v] = a[v][u] = true; }

int main()
{
    n = 4; last_n = 2;
    add_edge(0, 2);
    add_edge(0, 3);
    for (int i = 1; i < LEVELS; ++i) {
        // i + 2 more vertices
        add_edge(n, last_n);
        add_edge(n + 1, last_n + 1);
        for (int j = 2; j < i + 2; ++j) {
            for (int k = 0; k < j; ++k)
                add_edge(n + j, last_n + k);
        }
        last_n = n;
        n += (i + 2);
    }

    scanf("%d", &k);
    for (int i = 0; i < LEVELS + 1; ++i) {
        if ((k >> i) & 1) add_edge(last_n + 1 + i, 1);
    }

    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            putchar(a[i][j] ? 'Y' : 'N');
        putchar('\n');
    }

    return 0;
}