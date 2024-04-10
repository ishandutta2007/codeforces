#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
static const int MAXN = 1e5 + 4;
static const int mov[8][2] = {{+1, +1}, {+1, 0}, {+1, -1}, {0, +1}, {0, -1}, {-1, +1}, {-1, 0}, {-1, -1}};
template <typename T> inline bool upd_optional(T &var, const T val) {
    if (var == 0 || var > val) { var = val; return true; } else return false;
}

int n, x0, y0, x1, y1;
typedef std::pair<int, int> coord;
std::set<coord> s;
std::map<coord, int> dist;
static const int DIST_BASE = 114514;

int main()
{
    scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &n);
    int r_i, a_i, b_i;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &r_i, &a_i, &b_i);
        for (; a_i <= b_i; ++a_i) s.insert(coord(r_i, a_i));
    }

    std::queue<coord> q;
    q.push(coord(x0, y0));
    dist[coord(x0, y0)] = DIST_BASE;
    while (!q.empty()) {
        coord cur = q.front(); q.pop();
        int nw_dist = dist[cur] + 1;
        for (int dir = 0; dir < 8; ++dir) {
            coord nw = coord(cur.first + mov[dir][0], cur.second + mov[dir][1]);
            if (s.count(nw) && upd_optional(dist[nw], nw_dist)) q.push(nw);
        }
    }

    int ans = dist[coord(x1, y1)];
    printf("%d\n", ans == 0 ? -1 : ans - DIST_BASE);
    return 0;
}