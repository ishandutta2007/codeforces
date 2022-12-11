#include <cstdio>
#include <cstring>
#include <algorithm>
static const int MAXN = 1024;
static const int MODULUS = 1e9 + 7;
template <typename T> inline T min4(const T a, const T b, const T c, const T d) {
    return std::min(std::min(a, b), std::min(c, d));
}

struct logger {
    int twos, threes;
    logger() : twos(0), threes(0) { }
    logger(int _2, int _3) : twos(_2), threes(_3) { }
    logger(int x) { if (x == 2) { twos = 1; threes = 0; } else if (x == 3) { twos = 0; threes = 1; } else twos = threes = 0; }
    static const double multiples = 0.63092975357146;   // ln(2) / ln(3);
};
inline logger operator * (const logger lhs, const logger rhs) {
    return logger(lhs.twos + rhs.twos, lhs.threes + rhs.threes);
}
inline logger operator / (const logger lhs, const logger rhs) {
    return logger(lhs.twos - rhs.twos, lhs.threes - rhs.threes);
}
inline logger operator * (const logger lhs, const int rhs) {
    if (rhs == 2) return logger(lhs.twos + 1, lhs.threes);
    else if (rhs == 3) return logger(lhs.twos, lhs.threes + 1);
    else return lhs;
}
inline bool operator < (const logger lhs, const logger rhs) {
    return logger::multiples * (lhs.twos - rhs.twos) < (rhs.threes - lhs.threes);
}

inline long long fpow(long long base, int exp) {
    long long ans = 1;
    while (exp) {
        if (exp & 1) ans = (ans * base) % MODULUS;
        base = (base * base) % MODULUS;
        exp >>= 1;
    }
    return ans;
}

int n;
int a[MAXN][MAXN];
int p_move[8][2] = {    // [dR, dC]
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
};
int e_dir[4][4] = {     // [R, C], [dR, dC]
    {0, 0, 0, 1}, {1, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 1, 0}
};
bool p_edge[8][4] = {   // [R, C], [dR, dC]
    {0, 0, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 0}, {0, 1, 0, 0},
    {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}
};
int cont[8][MAXN][MAXN];
int cross[MAXN][MAXN][2];   // [0] = Normal, [1] = Rotated
logger prod[8][MAXN][MAXN];

inline int in_range(int x) { return x >= 0 && x < n; }

// x = Direction (0 to 7)
inline void calc_cont(int x) {
    for (int e = 0; e < 4; ++e) if (p_edge[x][e]) {
        for (int r = e_dir[e][0] * (n - 1), c = e_dir[e][1] * (n - 1);
            in_range(r) && in_range(c);
            r += e_dir[e][2], c += e_dir[e][3])
        {
            // Calculate a line starting with a point on edge #e
            // Points on this edge are iterated with r & c
            cont[x][r][c] = !!a[r][c];
            for (int rr = r + p_move[x][0], cc = c + p_move[x][1];
                in_range(rr) && in_range(cc);
                rr += p_move[x][0], cc += p_move[x][1])
            {
                // Points on current line are iterated with rr & cc
                cont[x][rr][cc] = (a[rr][cc] ? cont[x][rr - p_move[x][0]][cc - p_move[x][1]] + 1 : 0);
            }
        }
    }
}

// x = Direction (0 to 7)
inline void calc_prod(int x) {
    for (int e = 0; e < 4; ++e) if (p_edge[x][e]) {
        for (int r = e_dir[e][0] * (n - 1), c = e_dir[e][1] * (n - 1);
            in_range(r) && in_range(c);
            r += e_dir[e][2], c += e_dir[e][3])
        {
            prod[x][r][c] = logger(a[r][c]);
            for (int rr = r + p_move[x][0], cc = c + p_move[x][1];
                in_range(rr) && in_range(cc);
                rr += p_move[x][0], cc += p_move[x][1])
            {
                prod[x][rr][cc] = prod[x][rr - p_move[x][0]][cc - p_move[x][1]] * a[rr][cc];
            }
        }
    }
}
// x = Direction (0 to 7)
inline logger partial_prod(int x, int r, int c, int sz) {
    r -= p_move[x][0];
    c -= p_move[x][1];
    if (!in_range(r) || !in_range(c)) return prod[x][r + p_move[x][0] * sz][c + p_move[x][1] * sz];
    else return prod[x][r + p_move[x][0] * sz][c + p_move[x][1] * sz] / prod[x][r][c];
}

int main()
{
    bool has_nonzeroes = false;
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j) {
            a[i][j] = getchar() - '0';
            if (j != n) has_nonzeroes |= (a[i][j] != 0);
        }
    if (!has_nonzeroes) {
        puts("0");
        return 0;
    }

    memset(cont, 0, sizeof cont);
    for (int i = 0; i < 8; ++i) calc_cont(i);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cross[i][j][0] = min4(cont[0][i][j], cont[1][i][j], cont[2][i][j], cont[3][i][j]);  // Normal
            cross[i][j][1] = min4(cont[4][i][j], cont[5][i][j], cont[6][i][j], cont[7][i][j]);  // Rotated
        }

    memset(prod, 0, sizeof prod);
    for (int i = 0; i < 8; ++i) calc_prod(i);

    logger ans(0, 0), cur;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (a[i][j] != 0) {
            // Normal
            cur = partial_prod(0, i, j, cross[i][j][0]) * partial_prod(1, i, j, cross[i][j][0])
                * partial_prod(2, i, j, cross[i][j][0]) * partial_prod(3, i, j, cross[i][j][0])
                / a[i][j] / a[i][j] / a[i][j];
            if (ans < cur) ans = cur;
            // Rotated
            cur = partial_prod(4, i, j, cross[i][j][1]) * partial_prod(5, i, j, cross[i][j][1])
                * partial_prod(6, i, j, cross[i][j][1]) * partial_prod(7, i, j, cross[i][j][1])
                / a[i][j] / a[i][j] / a[i][j];
            if (ans < cur) ans = cur;
        }
    printf("%I64d\n", fpow(2, ans.twos) * fpow(3, ans.threes) % MODULUS);

    return 0;
}