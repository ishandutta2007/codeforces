#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int INF = 200000000;

int ia(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

struct point {
    int c[2];
};

point p[4];
int to[4];

int bsl;
point f[4];

int canGo(point p, int x, int y, int &di) {
    if (p.c[0] == x) {
        di = ia(p.c[1] - y);
        return true;
    } else if (p.c[1] == y) {
        di = ia(p.c[0] - x);
        return true;
    }
    return false;
}

int solve(int ox, int oy, int a) {
    int k;
    int md = 0;
    if (!canGo(p[to[0]], ox, oy, k)) {
        return -1;
    }
    md = max(md, k);
    if (!canGo(p[to[1]], ox, oy + a, k)) {
        return -1;
    }
    md = max(md, k);
    if (!canGo(p[to[2]], ox + a, oy, k)) {
        return -1;
    }
    md = max(md, k);
    if (!canGo(p[to[3]], ox + a, oy + a, k)) {
        return -1;
    }
    md = max(md, k);
    if (bsl == -1 || md < bsl) {
        bsl = md;
        f[to[0]].c[0] = ox; f[to[0]].c[1] = oy;
        f[to[1]].c[0] = ox; f[to[1]].c[1] = oy + a;
        f[to[2]].c[0] = ox + a; f[to[2]].c[1] = oy;
        f[to[3]].c[0] = ox + a; f[to[3]].c[1] = oy + a;
    }
    return md;
}

int main() {
    int te;
    scanf("%d", &te);
    for (int tes = 0; tes < te; ++tes) {
        for (int i = 0; i < 4; ++i) {
            scanf("%d %d", &p[i].c[0], &p[i].c[1]);
            to[i] = i;
        }
        bsl = -1;
        do {
            for (int ma = 0; ma < (1 << 4); ++ma) {
                // fix axis
                map<int, vector<int> > ax[2];
                for (int i = 0; i < 4; ++i) {
                    int di = 0;
                    if ((ma & (1 << i))) {
                        di = 1;
                    }
                    ax[di][p[i].c[di]].push_back(i);
                }
                bool ok = true;
                for (int di = 0; di < 2; ++di) {
                    if (ax[di].size() >= 3) {
                        ok = false;
                    }
                    for (auto piv : ax[di]) {
                        if (piv.second.size() >= 3) {
                            ok = false;
                        }
                    }
                }
                if (!ok) {
                    continue;
                }
                int a = -1, b = -1;
                if (ax[0].size() == 2) {
                    a = ax[0].rbegin()->first - ax[0].begin()->first;
                }
                if (ax[1].size() == 2) {
                    b = ax[1].rbegin()->first - ax[1].begin()->first;
                }
                if (a != -1 && b != -1 && a != b) {
                    continue;
                }
                a = max(a, b);
                if (a == -1) {
                    continue;
                }
                // I know a.
                if (ax[0].size() && ax[1].size()) {
                    // easy case
                    int ox = ax[0].begin()->first;
                    int oy = ax[1].begin()->first;
                    solve(ox, oy, a);
                    solve(ox - a, oy, a);
                    solve(ox, oy - a, a);
                    solve(ox - a, oy - a, a);
                } else {
                    // only 2.
                    int o[2];
                    int t;
                    if (ax[0].size()) {
                        t = 1;
                        o[0] = ax[0].begin()->first;
                    } else {
                        t = 0;
                        o[1] = ax[1].begin()->first;
                    }
                    // ternary search o[t]
                    int le, ri;
                    le = -INF;
                    ri = INF;
                    while (ri - le > 6) {
                        int m1 = le + (ri - le) / 3;
                        int m2 = ri - (ri - le) / 3;
                        o[t] = m1;
                        int s1 = solve(o[0], o[1], a);
                        o[t] = m2;
                        int s2 = solve(o[0], o[1], a);
                        if (s1 < s2) {
                            ri = m2;
                        } else {
                            le = m1;
                        }
                    }
                    for (int tt = le; tt <= ri; ++tt) {
                        o[t] = tt;
                        solve(o[0], o[1], a);
                    }
                }
            }
        } while (next_permutation(to, to + 4));
        printf("%d\n", bsl);
        if (bsl != -1) {
            for (int i = 0; i < 4; ++i) {
                printf("%d %d\n", f[i].c[0], f[i].c[1]);
            }
        }
    }
    return 0;
}