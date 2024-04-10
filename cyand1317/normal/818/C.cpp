#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXD = 1e5 + 4;

struct sofa {
    int id, x1, y1, x2, y2;
    inline void normalize() {
        if (x1 > x2) std::swap(x1, x2), std::swap(y1, y2);
        else if (x1 == x2 && y1 > y2) std::swap(y1, y2);
    }
    inline bool operator < (const sofa &other) const {
        return std::make_pair(x1, x2) < std::make_pair(other.x1, other.x2);
    }
} s[MAXD];

int D;
int l[MAXD], r[MAXD], u[MAXD], d[MAXD];

inline void count(int *l)
{
    for (int i = 0; i < D; ++i) s[i].normalize();
    std::sort(s, s + D);
    //for (int i = 0; i < D; ++i)
    //    printf("%d | %d %d %d %d\n", s[i].id, s[i].x1, s[i].y1, s[i].x2, s[i].y2);
    for (int i = 0, j; i < D; ) {
        for (j = i + 1; s[j].x1 == s[i].x1 && s[j].x2 == s[i].x2; ++j) continue;
        int x = i;
        for (; i < j; ++i) l[s[i].id] = (s[i].x1 == s[i].x2 ? x : j - 1);
    }
}

int main()
{
    scanf("%d", &D);
    scanf("%*d%*d");
    for (int i = 0; i < D; ++i) {
        s[i].id = i;
        scanf("%d%d%d%d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
    }

    count(l);
    for (int i = 0; i < D; ++i) {
        s[i].x1 = -s[i].x1;
        s[i].x2 = -s[i].x2;
    }
    count(r);
    for (int i = 0; i < D; ++i) {
        std::swap(s[i].x1, s[i].y1);
        std::swap(s[i].x2, s[i].y2);
    }
    count(u);
    for (int i = 0; i < D; ++i) {
        s[i].x1 = -s[i].x1;
        s[i].x2 = -s[i].x2;
    }
    count(d);

    //for (int i = 0; i < D; ++i) printf("%d %d %d %d\n", l[i], r[i], u[i], d[i]);
    int cl, cr, cu, cd;
    scanf("%d%d%d%d", &cl, &cr, &cu, &cd);
    for (int i = 0; i < D; ++i)
        if (l[i] == cl && r[i] == cr && u[i] == cu && d[i] == cd) {
            printf("%d\n", i + 1); return 0;
        }

    puts("-1"); return 0;
}