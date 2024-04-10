#include <cstdio>
#include <cmath>
namespace prevent_math_h_y1_pollution_XD {
static const int MAXN = 128;
template <typename T> inline void rot2(T &a, T &b) {
    static T t; t = a; a = b; b = t;
}
template <typename T> inline void rot3(T &a, T &b, T &c) {
    static T t; t = a; a = b; b = c; c = t;
}

int n, area;
int x1, y1, x2, y2, x3, y3;
char c1, c2, c3;
char b[MAXN][MAXN];
bool successful = false;

inline bool out(int x) { return !(x >= 0 && x < n); }
inline bool try_put()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j) b[i][j] = '\n';
    // #1 will be put in the top-left corner
    // #3 will be put in the bottom-right corner afterwards
    // #2 will be tried to be inserted into the space remaining
    for (int i = 0; i < x1; ++i)
        for (int j = 0; j < y1; ++j) b[i][j] = c1;
    for (int i = 0; i < x3; ++i)
        for (int j = 0; j < y3; ++j)
            if (out(n - i - 1) || out(n - 1 - j) || b[n - 1 - i][n - 1 - j] != '\n') return false;
            else b[n - 1 - i][n - 1 - j] = c3;
    // Find the topmost-leftmost empty space
    int ci = -1, cj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (b[i][j] == '\n') { ci = i; cj = j; break; }
        if (ci != -1) break;
    }
    for (int i = 0; i < x2; ++i)
        for (int j = 0; j < y2; ++j)
            if (out(ci + i) || out(cj + j) || b[ci + i][cj + j] != '\n') return false;
            else b[ci + i][cj + j] = c2;
    successful = true;
    return true;
}

int main(int argc, char *argv[])
{
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    area = x1 * y1 + x2 * y2 + x3 * y3;
    n = (int)(sqrt(area) + 0.5);
    if (n * n != area) { puts("-1"); return 0; }
    if (x1 > n || x2 > n || x3 > n || y1 > n || y2 > n || y3 > n) { puts("-1"); return 0; }

    c1 = 'A'; c2 = 'B'; c3 = 'C';
    for (int i = 0; i < 6; ++i) {
        rot3(x1, x2, x3);
        rot3(y1, y2, y3);
        rot3(c1, c2, c3);
        if (try_put()) break;
        for (int j = 0; j < 8; ++j) {
            rot2(x1, y1);
            if (j % 2 == 0) rot2(x2, y2);
            if (j % 4 == 0) rot2(x3, y3);
            if (try_put()) break;
        }
        if (successful) break;
        if (i == 2) {
            rot2(x2, x3); rot2(y2, y3); rot2(c2, c3);
        }
    }
    if (successful) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= n; ++j) putchar(b[i][j]);
    } else {
        puts("-1");
    }
    return 0;
}
}

int main(int argc, char *argv[])
{
    return prevent_math_h_y1_pollution_XD::main(argc, argv);
}