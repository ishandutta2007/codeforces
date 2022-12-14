#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int mod = 1000000007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, h, w;

char p[1 << 20];

int d[512];

long long off = (1 << 20);
long long idx[1 << 21];
long long idy[1 << 21];
long long mix, mxx, miy, mxy;
long long chx, chy;

long long fx[1 << 20], fy[1 << 20];
long long ps[1 << 20];

int main() {
    d[(int) 'D'] = 0;
    d[(int) 'L'] = 1;
    d[(int) 'U'] = 2;
    d[(int) 'R'] = 3;

    scanf("%d %d %d", &n, &h, &w);
    scanf("%s", p);

    memset(idx, -1, sizeof(idx));
    memset(idy, -1, sizeof(idy));

    chx = chy = 0;
    idx[0 + off] = 0;
    idy[0 + off] = 0;
    mix = mxx = miy = miy = 0;
    for (int i = 0; i < n; ++i) {
        int k = d[(int) p[i]];
        chx += dx[k];
        chy += dy[k];
        if (idx[chx + off] == -1) {
            idx[chx + off] = i + 1;
        }
        if (idy[chy + off] == -1) {
            idy[chy + off] = i + 1;
        }
        if (chx > mxx) {
            mxx = chx;
        }
        if (chx < mix) {
            mix = chx;
        }
        if (chy > mxy) {
            mxy = chy;
        }
        if (chy < miy) {
            miy = chy;
        }
    }

    int nx, ny;
    nx = ny = 0;
    for (int i = 0; i < h; ++i) {
        long long stepri = h - i;
        long long t;
        long long rhs = (stepri - mxx);
        long long cand = (1LL << 62);
        if (rhs <= 0) {
            t = 0;
        } else {
            if (chx <= 0) {
                t = -1;
            } else {
                t = (rhs + chx - 1) / chx;
            }
        }
        if (t != -1) {
            stepri = h - i - (long long) chx * t;
            cand = t * (long long) n + idx[stepri + off];
        }

        t = -1;
        long long steple = i + 1;
        long long cand2 = (1LL << 62);
        rhs = (steple + mix);
        if (rhs <= 0) {
            t = 0;
        } else {
            if (chx >= 0) {
                t = -1;
            } else {
                t = (rhs - chx - 1) / (-chx);
            }
        }
        if (t != -1) {
            steple = i + 1 + (long long) chx * t;
            cand2 = t * (long long) n + idx[-steple + off];
        }
        fx[i] = min(cand, cand2);
        if (fx[i] >= (1LL << 62)) {
            nx = 1;
        }
    }

    for (int i = 0; i < w; ++i) {
        long long stepri = w - i;
        long long t;
        long long rhs = (stepri - mxy);
        long long cand = (1LL << 62);
        if (rhs <= 0) {
            t = 0;
        } else {
            if (chy <= 0) {
                t = -1;
            } else {
                t = (long long) (rhs + chy - 1) / chy;
            }
        }
        if (t != -1) {
            stepri = w - i - (long long) chy * t;
            cand = (long long) t * n + idy[stepri + off];
        }

        t = -1;
        long long steple = i + 1;
        long long cand2 = (1LL << 62);
        rhs = (steple + miy);
        if (rhs <= 0) {
            t = 0;
        } else {
            if (chy >= 0) {
                t = -1;
            } else {
                t = (long long) (rhs - chy - 1) / (-chy);
            }
        }
        if (t != -1) {
            steple = i + 1 + (long long) chy * t;
            cand2 = (long long) t * n + idy[-steple + off];
        }
        fy[i] = min(cand, cand2);
        if (fy[i] >= (1LL << 62)) {
            ny = 1;
        }
    }
    if (nx && ny) {
        printf("-1\n");
        return 0;
    }
    // int a = 0;
    // for (int i = 0; i < h; ++i) {
    //     for (int j = 0; j < w; ++j) {
    //         a += min(fx[i], fy[j]);
    //     }
    // }
    // printf("a %d\n", a);

    sort(fx, fx + h);
    ps[0] = 0;
    for (int i = 0; i < h; ++i) {
        if (fx[i] >= (1LL << 62)) {
            ps[i + 1] = ps[i] + 0;
        } else {
            ps[i + 1] = ps[i] + (fx[i] % mod);
        }
        if (ps[i + 1] >= mod) {
            ps[i + 1] %= mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i < w; ++i) {
        if (fy[i] >= (1LL << 62)) {
            ans += ps[h];
            if (ans >= mod) {
                ans %= mod;
            }
            continue;
        }
        int j = (int) (lower_bound(fx, fx + h, fy[i]) - fx);
        ans += ps[j];
        if (ans >= mod) {
            ans %= mod;
        }
        ans += fy[i] * (h - j);
        if (ans >= mod) {
            ans %= mod;
        }
    }
    printf("%d\n", (int) ans);
    return 0;
}