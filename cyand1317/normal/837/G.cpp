#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXM = 500004;
static const int BLK_SZ = 599;
static const int BLK_NM = 75003 / BLK_SZ + 1;
static const int MAXN = BLK_SZ * BLK_NM;

static const int F_BUFSZ = 98765;
int f_ptr = F_BUFSZ - 1;
char f_buf[F_BUFSZ];
inline void f_flush() { fread(f_buf, 1, F_BUFSZ, stdin); f_ptr = 0; }
inline char f_getchar() { if (++f_ptr == F_BUFSZ) f_flush(); return f_buf[f_ptr]; }
inline int read_int() {
    static int ret;
    static char ch;
    while ((ch = f_getchar()) < '0' || ch > '9') continue;
    ret = ch - '0';
    while ((ch = f_getchar()) >= '0' && ch <= '9') ret = ret * 10 + ch - '0';
    return ret;
}

int n, m;
int x1[MAXN], x2[MAXN], y1[MAXN], a[MAXN], b[MAXN], y2[MAXN];

int ct[BLK_NM], p[BLK_NM][BLK_SZ * 2 + 1];
int64 as[BLK_NM][BLK_SZ * 2 + 1], bs[BLK_NM][BLK_SZ * 2 + 1];

inline void block_preprocess()
{
    for (int i = 0; i < BLK_NM; ++i) {
        int start = i * BLK_SZ;
        for (int j = 0; j < BLK_SZ; ++j) {
            p[i][j * 2] = x1[start + j];
            p[i][j * 2 + 1] = x2[start + j];
        }
        p[i][BLK_SZ * 2] = 1e9 + 3;
        std::sort(p[i], p[i] + BLK_SZ * 2 + 1);
        ct[i] = std::unique(p[i], p[i] + BLK_SZ * 2 + 1) - &p[i][0];
        for (int j = 0; j < ct[i]; ++j) {
            int x = p[i][j];
            as[i][j] = bs[i][j] = 0;
            for (int k = start; k < start + BLK_SZ; ++k)
                if (x <= x1[k]) bs[i][j] += y1[k];
                else if (x <= x2[k]) as[i][j] += a[k], bs[i][j] += b[k];
                else bs[i][j] += y2[k];
        }
    }
}

inline void update(int64 &as, int64 &bs, int l, int r, int x)
{
    for (int i = l; i <= r; ++i)
        if (x <= x1[i]) bs += y1[i];
        else if (x <= x2[i]) as += a[i], bs += b[i];
        else bs += y2[i];
}
inline int64 query(int l, int r, int x)
{
    int l_bl = l / BLK_SZ, r_bl = r / BLK_SZ;
    int64 a = 0, b = 0;
    if (l_bl == r_bl) {
        update(a, b, l, r, x);
    } else {
        update(a, b, l, (l_bl + 1) * BLK_SZ - 1, x);
        update(a, b, r_bl * BLK_SZ, r, x);
        for (int i = l_bl + 1; i < r_bl; ++i) {
            int q = std::lower_bound(p[i], p[i] + ct[i], x) - &p[i][0];
            a += as[i][q];
            b += bs[i][q];
        }
    }
    return a * x + b;
}

int main()
{
    n = read_int();
    for (int i = 0; i < n; ++i) {
        x1[i] = read_int();
        x2[i] = read_int();
        y1[i] = read_int();
        a[i] = read_int();
        b[i] = read_int();
        y2[i] = read_int();
    }

    block_preprocess();

    m = read_int();
    int64 last = 0;
    for (int i = 0, l, r, x; i < m; ++i) {
        l = read_int() - 1, r = read_int() - 1;
        x = (last + read_int()) % (int)1e9;
        printf("%I64d\n", last = query(l, r, x));
    }

    return 0;
}