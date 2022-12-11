#include <cstdio>
#include <bitset>
static const int MAXN = 418;
typedef std::bitset<MAXN> teapot;

int n, m, r, c;
char table[MAXN][MAXN], pattern[MAXN][MAXN];
teapot pot[MAXN][MAXN][26]; // pot[row][offset][letter]
teapot cur_row;

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) table[i][j] = getchar();
    scanf("%d%d", &r, &c); getchar();
    for (int i = 0; i < r; ++i)
        for (int j = 0; j <= c; ++j) pattern[i][j] = getchar();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < c; ++k)
                pot[i][k][table[i][(j + k) % m] - 'a'].set(j);
        }

    for (int i = 0; i < n; ++i) {
        cur_row.set();
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < c; ++k) if (pattern[j][k] != '?')
                cur_row &= pot[(i + j) % n][k][pattern[j][k] - 'a'];
        for (int j = 0; j < m; ++j) putchar(cur_row.test(j) + '0'); putchar('\n');
    }

    return 0;
}