#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
typedef long long int64;
#define INT64_FMT "%I64d"
static const int MAXN = 2e5 + 6;

int n, m;
struct req {
    std::pair<int64, int64> rg;
    int idx;
} r[MAXN];
inline bool req_cmp_left(const req &lhs, const req &rhs) {
    return lhs.rg < rhs.rg;
}
struct req_cmp_right_idx {
    inline bool operator () (const int lhs, const int rhs) {
        return r[lhs].rg.second == r[rhs].rg.second ?
            r[lhs].rg.first < r[rhs].rg.first :
            r[lhs].rg.second < r[rhs].rg.second;
    }
};
std::multiset<int, req_cmp_right_idx> avail;
std::pair<int64, int> b[MAXN];

int ans[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    int64 l0, r0, l1, r1;
    scanf(INT64_FMT INT64_FMT, &l0, &r0);
    for (int i = 0; i < n - 1; ++i) {
        scanf(INT64_FMT INT64_FMT, &l1, &r1);
        r[i].rg = std::make_pair(l1 - r0, r1 - l0);
        r[i].idx = i;
        l0 = l1, r0 = r1;
    }
    for (int i = 0; i < m; ++i) {
        scanf(INT64_FMT, &b[i].first);
        b[i].second = i;
    }

    std::sort(r, r + n - 1, req_cmp_left);
    std::sort(b, b + m);
    for (int i = 0; i < n - 1; ++i) ans[i] = -1;

    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        while (ptr < n - 1 && r[ptr].rg.first <= b[i].first) avail.insert(ptr++);
        while (!avail.empty()) {
            int popped = *avail.begin();
            if (r[popped].rg.second >= b[i].first) break;
            avail.erase(avail.begin());
        }
        if (!avail.empty()) {
            int popped = *avail.begin();
            ans[r[popped].idx] = b[i].second;
            avail.erase(avail.begin());
        }
    }

    bool valid = true;
    for (int i = 0; i < n - 1; ++i) if (ans[i] == -1) { valid = false; break; }
    if (valid) {
        puts("Yes");
        for (int i = 0; i < n - 1; ++i) printf("%d%c", ans[i] + 1, i == n - 1 ? '\n' : ' ');
    } else {
        puts("No");
    }

    return 0;
}