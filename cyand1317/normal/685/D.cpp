#include <cstdio>
#include <algorithm>
#include <utility>

static const int MAXN = 100008;
static const int MAXK = 300;

typedef long long int64;
typedef std::pair<int, int> point;
#define x  first
#define y  second
struct event {
    int time;
    int l, r; signed short inc;
    event() { }
    event(int time, int l, int r, signed short inc)
        : time(time), l(l), r(r), inc(inc) { }
};
inline bool operator < (const event &lhs, const event &rhs) {
    return lhs.time < rhs.time;
}
/*inline bool point_y_cmp(const point &lhs, const point &rhs) {
    return lhs.y < rhs.y;
}*/

int n, k;
point p[MAXN];
event ev[MAXN * 2];

int64 ans[MAXN] = { 0 };
int omoshiroi[MAXN];
int row[MAXN * MAXK];
static const int UPPER_BOUND = 1e9 + 20;

inline void process_event(const event &e)
{
    for (int i = e.l; i <= e.r; ++i) {
        ans[row[i]] -= (UPPER_BOUND - e.time);
        row[i] += e.inc;
        ans[row[i]] += (UPPER_BOUND - e.time);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        //p[i].x = rand();
        //p[i].y = rand();
    }
    std::sort(p, p + n/*, point_x_cmp*/);
    int mapped_coord = -k, real_coord = -UPPER_BOUND;
    for (int i = 0; i < n; ++i) {
        if (p[i].x >= real_coord + k) {
            mapped_coord += k;
        } else {
            mapped_coord += (p[i].x - real_coord);
        }
        real_coord = p[i].x;

        ev[i + i] = event(p[i].y, mapped_coord, mapped_coord + k - 1, +1);
        ev[i + i + 1] = event(p[i].y + k, mapped_coord, mapped_coord + k - 1, -1);
    }
    std::sort(ev, ev + n + n);

    for (int i = 0; i < n + n; ++i) process_event(ev[i]);

    for (int i = 1; i <= n; ++i)
        printf("%I64d%c", ans[i], i == n ? '\n' : ' ');

    return 0;
}