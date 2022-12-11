#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
static const int MAXN = 50004;
static const int LOGY = 33;
static const int NODES = MAXN * LOGY;

int n;
int y[MAXN], y_id[MAXN][LOGY];
int val[NODES], valct = 0;
std::map<int, int> node_id;
bool avail[NODES], slctd[NODES] = { false };

// The following two functions are identical
// except for the selected state modification in the second one
inline bool check(int upper) {
    memset(avail, false, sizeof avail);
    for (int i = 0; i < upper; ++i) avail[i] = true;
    bool found;
    for (int i = 0; i < n; ++i) {
        found = false;
        for (int x = 0; y_id[i][x] != -1; ++x) if (avail[y_id[i][x]]) {
            avail[y_id[i][x]] = false; found = true; break;
        }
        if (!found) return false;
    }
    return true;
}
inline bool check_record(int upper) {
    memset(avail, false, sizeof avail);
    for (int i = 0; i < upper; ++i) avail[i] = true;
    bool found;
    for (int i = 0; i < n; ++i) {
        found = false;
        for (int x = 0; y_id[i][x] != -1; ++x) if (avail[y_id[i][x]]) {
            avail[y_id[i][x]] = false; slctd[y_id[i][x]] = true; found = true; break;
        }
        if (!found) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y[i]);
        for (int t = y[i]; t > 0; t >>= 1) val[valct++] = t;
    }
    std::sort(val, val + valct);
    valct = std::unique(val, val + valct) - &val[0];
    for (int i = 0; i < valct; ++i) node_id[val[i]] = i;
    int t, x;
    for (int i = 0; i < n; ++i) {
        for (t = y[i], x = 0; t > 0; t >>= 1, ++x)
            y_id[i][x] = node_id[t];
        y_id[i][x] = -1;
    }

    int lo = 0, hi = valct, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid; else lo = mid;
    }
    check_record(hi);
    for (int i = 0; i < valct; ++i)
        if (slctd[i]) printf("%d ", val[i]);
    putchar('\n');

    return 0;
}