#include <cstdio>
typedef long long int64;
static const int64 INF64 = 1LL << 62;
static const int MAXN = 100008;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

struct coord {
    int64 x, y, z;
    coord() : x(INF64), y(INF64), z(INF64) { }
    coord(int64 x, int64 y = 0, int64 z = 0) : x(x), y(y), z(z) { }
};
struct ineq {
    int64 al, ar, bl, br, cl, cr, sl, sr;

    ineq(int64 al = -INF64, int64 ar = INF64, int64 bl = -INF64, int64 br = INF64,
        int64 cl = -INF64, int64 cr = INF64, int64 sl = -INF64, int64 sr = INF64)
    : al(al), ar(ar), bl(bl), br(br), cl(cl), cr(cr), sl(sl), sr(sr) { }

    inline ineq intersect(const ineq &other) {
        return ineq(
            max(al, other.al), min(ar, other.ar),
            max(bl, other.bl), min(br, other.br),
            max(cl, other.cl), min(cr, other.cr),
            max(sl, other.sl), min(sr, other.sr)
        );
    }

    inline bool valid() {
        return al <= ar && bl <= br && cl <= cr && sl <= sr && (al + bl + cl <= sr) && (ar + br + cr >= sl);
    }

    inline coord solve() {
        if (!valid()) return coord(INF64, INF64, INF64);
        coord ret(al, bl, cl);
        if (ret.x + ret.y + ret.z < sr) ret.x += min(sr - (ret.x + ret.y + ret.z), ar - al);
        if (ret.x + ret.y + ret.z < sr) ret.y += min(sr - (ret.x + ret.y + ret.z), br - bl);
        if (ret.x + ret.y + ret.z < sr) ret.z += min(sr - (ret.x + ret.y + ret.z), cr - cl);
        return ret;
    }
};

int n;
coord p[MAXN];

template <typename T> inline T wipe_parity(const T x) { return x - (x & 1); }

coord check(int64 dist)
{
    ineq e;
    coord sol;
    for (int i = 0; i < n; ++i) {
        ineq w(p[i].x + p[i].y - p[i].z - dist, p[i].x + p[i].y - p[i].z + dist,
            p[i].x - p[i].y + p[i].z - dist, p[i].x - p[i].y + p[i].z + dist,
           -p[i].x + p[i].y + p[i].z - dist,-p[i].x + p[i].y + p[i].z + dist,
            p[i].x + p[i].y + p[i].z - dist, p[i].x + p[i].y + p[i].z + dist
        );
        e = e.intersect(w);
    }
    //printf("> Checking %I64d\n", dist);
    //printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n", e.al, e.ar, e.bl, e.br, e.cl, e.cr, e.sl, e.sr);
    for (int p = 0; p <= 1; ++p) {
        ineq w = ineq(
            wipe_parity(e.al - p + 1) >> 1, wipe_parity(e.ar - p) >> 1,
            wipe_parity(e.bl - p + 1) >> 1, wipe_parity(e.br - p) >> 1,
            wipe_parity(e.cl - p + 1) >> 1, wipe_parity(e.cr - p) >> 1,
            wipe_parity(e.sl - p * 3 + 1) >> 1, wipe_parity(e.sr - p * 3) >> 1
        );
        if ((sol = w.solve()).x != INF64) {
            //printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d -> %I64d %I64d %I64d\n",
            //    w.al, w.ar, w.bl, w.br, w.cl, w.cr, w.sl, w.sr, sol.x, sol.y, sol.z);
            sol.x = sol.x * 2 + p;
            sol.y = sol.y * 2 + p;
            sol.z = sol.z * 2 + p;
            return coord((sol.x + sol.y) / 2, (sol.x + sol.z) / 2, (sol.y + sol.z) / 2);
        }
    }
    return coord(INF64, INF64, INF64);
}

void work()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d%I64d%I64d", &p[i].x, &p[i].y, &p[i].z);

    int64 lo = -1, hi = 3e18 + 2016, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        //printf("> %I64d %I64d %I64d\n", lo, mid, hi);
        if (check(mid).x != INF64) hi = mid; else lo = mid;
    }

    coord ans = check(hi);
    //printf("> Minimum distance = %I64d\n", hi);
    printf("%I64d %I64d %I64d\n", ans.x, ans.y, ans.z);
}

int main()
{
    int T; scanf("%d", &T);
    do work(); while (--T);
    return 0;
}