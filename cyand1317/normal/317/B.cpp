#include <cstdio>
#include <cstring>
static const int MAXSZ = 70;
static const int MAXSZ_VALID = 67;

int g[MAXSZ][MAXSZ] = {{ 0 }};

inline bool step() {
    static int h[MAXSZ][MAXSZ];
    memset(h, 0, sizeof h);
    for (int i = 0; i < MAXSZ - 1; ++i)
        for (int j = 0; j < MAXSZ - 1; ++j) {
            if (j) h[i][j - 1] += g[i][j] / 4;
            h[i][j + 1] += g[i][j] / 4;
            if (i) h[i - 1][j] += g[i][j] / 4;
            h[i + 1][j] += g[i][j] / 4;
        }
    for (int i = 0; i < MAXSZ; ++i) h[0][i] += g[1][i] / 4;
    for (int i = 0; i < MAXSZ; ++i) h[i][0] += g[i][1] / 4;
    for (int i = 0; i < MAXSZ; ++i)
        for (int j = 0; j < MAXSZ; ++j) h[i][j] += g[i][j] % 4;
    if (memcmp(g, h, sizeof h) == 0) return false;
    memcpy(g, h, sizeof h); return true;
}
/*inline bool empty_row(int w) {
    for (int i = 0; i < MAXSZ; ++i) if (g[w][i]) return false; return true;
}
inline bool empty_col(int w) {
    for (int i = 0; i < MAXSZ; ++i) if (g[i][w]) return false; return true;
}
inline void print_board() {
    static const char *colour[5] = {
        "\033[0m",      // 0
        "\033[1;46m",   // 1
        "\033[1;42m",   // 2
        "\033[1;43m",   // 3
        "\033[1;41m"    // 4+
    };
    int lb = 0, rb = MAXSZ - 1, db = 0, ub = MAXSZ - 1;
    while (lb < MAXSZ && empty_col(lb)) ++lb;
    while (rb > lb && empty_col(rb)) --rb;
    while (db < MAXSZ && empty_row(db)) ++db;
    while (ub > db && empty_row(ub)) --ub;
    printf("=== Board size: %d * %d ===\n", ub - db + 1, rb - lb + 1);
    for (int i = db; i <= ub; ++i) {
        for (int j = lb; j <= rb; ++j)
            printf("%s%3d", colour[g[i][j] >= 4 ? 4 : g[i][j]], g[i][j]);
        puts("\033[0m");
    }
}*/

int n, t;

int main()
{
    scanf("%d%d", &n, &t);

    g[0][0] = n;
    while (step()) ;

    int x, y;
    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &x, &y);
        if (x < 0) x = -x; if (y < 0) y = -y;
        if (x >= MAXSZ_VALID || y >= MAXSZ_VALID) puts("0");
        else printf("%d\n", g[x][y]);
    }

    return 0;
}