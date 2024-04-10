#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
typedef long long int64;
typedef std::pair<short, short> bulb;
typedef std::pair<short, short> coord;
template <typename T, typename S> inline void update_min(T &var, const S val)
{ if (var > val) var = val; }
template <typename T, typename S> inline void update_max(T &var, const S val)
{ if (var < val) var = val; }
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }
static const int MAXN = 2004;
static const int MAXK = 2004;
static const int MAXL = 2004;

int n, m, k, q;
bulb a[MAXN][MAXN];
std::vector<int64> garland[MAXK];
coord garland_first[MAXK];
coord garland_tl[MAXK], garland_br[MAXK];
bool garland_on[MAXK];

inline bool in_rect(int x1, int y1, int x2, int y2, int x0, int y0) {
    return (x0 >= x1 && x0 <= x2 && y0 >= y1 && y0 <= y2);
}
inline bool is_connected(const bulb &u, const bulb &v) {
    return (u.first == v.first && abs(u.second - v.second) == 1);
}

inline int64 range_query(int x1, int y1, int x2, int y2)
{
    static bulb frame[MAXN * 4];
    int ct = 0;
    for (int i = x1; i <= x2; ++i) {
        if (y1 > 0 && is_connected(a[i][y1], a[i][y1 - 1]))
            frame[ct++] = std::max(a[i][y1], a[i][y1 - 1]);
        if (y2 < m - 1 && is_connected(a[i][y2], a[i][y2 + 1]))
            frame[ct++] = std::max(a[i][y2], a[i][y2 + 1]);
    }
    for (int j = y1; j <= y2; ++j) {
        if (x1 > 0 && is_connected(a[x1][j], a[x1 - 1][j]))
            frame[ct++] = std::max(a[x1][j], a[x1 - 1][j]);
        if (x2 < n - 1 && is_connected(a[x2][j], a[x2 + 1][j]))
            frame[ct++] = std::max(a[x2][j], a[x2 + 1][j]);
    }
    std::sort(frame, frame + ct);
    ct = std::unique(frame, frame + ct) - frame;

    int i, j, g;
    int64 ans = 0;
    for (i = 0; i < ct; i = j) {
        g = frame[i].first;
        for (j = i + 1; j < ct && frame[j].first == g; ++j) ;
        if (!garland_on[g]) continue;
        //printf("Garland #%d: %d cut(s)\n", frame[i].first + 1, j - i);
        //for (int k = i; k < j; ++k)
        //    printf("%d%c", frame[k].second + 1, k == j - 1 ? '\n' : ' ');
        if ((j - i) % 2 == 0) {
            if (in_rect(x1, y1, x2, y2, garland_first[g].first, garland_first[g].second)) {
                ans += garland[g][frame[i].second];
                for (int k = i + 1; k < j - 1; k += 2)
                    ans += garland[g][frame[k + 1].second] - garland[g][frame[k].second];
                ans += garland[g].back() - garland[g][frame[j - 1].second];
            } else {
                for (int k = i; k < j; k += 2)
                    ans += garland[g][frame[k + 1].second] - garland[g][frame[k].second];
            }
        } else {
            if (in_rect(x1, y1, x2, y2, garland_first[g].first, garland_first[g].second)) {
                ans += garland[g][frame[i].second];
                for (int k = i + 1; k < j; k += 2)
                    ans += garland[g][frame[k + 1].second] - garland[g][frame[k].second];
            } else {
                for (int k = i; k < j - 1; k += 2)
                    ans += garland[g][frame[k + 1].second] - garland[g][frame[k].second];
                ans += garland[g].back() - garland[g][frame[j - 1].second];
            }
        }
    }

    for (int g = 0; g < ::k; ++g) if (garland_on[g]) {
        if (in_rect(x1, y1, x2, y2, garland_tl[g].first, garland_tl[g].second) &&
            in_rect(x1, y1, x2, y2, garland_br[g].first, garland_br[g].second))
        {
            ans += garland[g].back();
        }
    }

    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) a[i][j] = bulb(-1, 0);

    int len, row, col, w;
    int64 w_tot;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &len);
        garland[i].reserve(len);
        garland_tl[i] = coord(MAXN, MAXN);
        garland_br[i] = coord(-1, -1);
        w_tot = 0;
        for (int j = 0; j < len; ++j) {
            scanf("%d%d%d", &row, &col, &w); --row, --col;
            if (j == 0) garland_first[i] = coord(row, col);
            garland[i].push_back(w_tot);
            w_tot += w;
            a[row][col] = bulb(i, j);
            update_min(garland_tl[i].first, row);
            update_min(garland_tl[i].second, col);
            update_max(garland_br[i].first, row);
            update_max(garland_br[i].second, col);
        }
        garland[i].push_back(w_tot);
        garland_on[i] = true;
    }

    scanf("%d", &q);
    char s[16];
    int x1, y1, x2, y2;
    do {
        scanf("%s%d", s, &x1); --x1;
        if (s[0] == 'S') {
            garland_on[x1] ^= 1;
        } else {
            scanf("%d%d%d", &y1, &x2, &y2); --y1, --x2, --y2;
            printf("%I64d\n", range_query(x1, y1, x2, y2));
        }
    } while (--q);

    return 0;
}