#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
static const int MAXN = 1e5 + 6;

int n, k;
int a[MAXN];
int num[MAXN];

inline void discretize() {
    static std::pair<int, int> p[MAXN];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(a[i], i);
    std::sort(p, p + n);
    int rk = 0;
    for (int i = 0; i < n; ++i) {
        if (i && p[i].first != p[i - 1].first) ++rk;
        num[rk] = p[i].first;
        a[p[i].second] = rk;
    }
}

int ct[MAXN] = { 0 };
std::set<int> ans;
inline void handle(int id, int inc = +1) {
    if (ct[id] == 1) ans.erase(id);
    ct[id] += inc;
    if (ct[id] == 1) ans.insert(id);
}
inline void print_query() {
    if (ans.empty()) puts("Nothing");
    else printf("%d\n", num[*ans.rbegin()]);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    discretize();

    for (int i = 0; i < k; ++i) handle(a[i], +1);
    print_query();
    for (int i = k; i < n; ++i) {
        handle(a[i], +1);
        handle(a[i - k], -1);
        print_query();
    }

    return 0;
}