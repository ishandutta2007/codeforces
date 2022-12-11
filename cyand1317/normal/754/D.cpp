#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 3e5 + 7;

int n, k;
int p[MAXN * 2], *l, *r, real[MAXN * 2], real_ct;
std::pair<int, int> ev[MAXN * 2];

namespace sgt {
static const int MAXN = 2097152;
int n, val[MAXN];

inline void build(int _n) {
    n = (1 << (8 * sizeof(int) - __builtin_clz(_n)));
    for (int i = 1; i < n * 2; ++i) val[i] = 0;
}

inline void modify(int pos, int inc) {
    //printf("> Segtree Modify: pos=%d inc=%d\n", pos, inc);
    for (int idx = n + pos; idx >= 1; idx >>= 1) val[idx] += inc;
}

inline int query_kth(int k) {
    //printf("> Segtree Query: k=%d\n", k);
    int idx;
    for (idx = 1; idx < n; ) {
        //printf(">> idx=%d Lv=%d Rv=%d\n", idx, val[idx * 2], val[idx * 2 + 1]);
        if (val[idx * 2] >= k) idx = idx * 2;
        else k -= val[idx * 2], idx = idx * 2 + 1;
    }
    return idx - n;
}
}

template <typename T> inline int discretize(int n, T *arr, T *real) {
    static std::pair<T, int> p[MAXN * 2];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(arr[i], i);
    std::sort(p, p + n);
    int rk = 0; real[0] = p[0].first;
    for (int i = 0; i < n; ++i) {
        if (i && p[i].first != p[i - 1].first) real[++rk] = p[i].first;
        arr[p[i].second] = rk;
    }
    return rk + 1;
}

int ans = 0, cur;
bool present[MAXN] = { false };
bool printed = false;
void print_answer() {
    printf("%d\n", ans);
    static std::pair<int, int> p[MAXN];
    int ptop = 0;
    for (int i = 0; i < n; ++i)
        if (present[i]) p[ptop++] = std::make_pair(r[i], i);
    std::sort(p, p + ptop);
    for (int i = 0; i < k; ++i)
        printf("%d%c", p[ptop - i - 1].second + 1, i == k - 1 ? '\n' : ' ');
    printed = true;
}
void find_answer(bool is_printing) {
    sgt::build(real_ct);
    int layers = 0;
    for (int i = 0; i < n * 2; ++i) {
        if (ev[i].second > 0) {
            sgt::modify(r[+ev[i].second - 1], +1);
            if (is_printing) present[+ev[i].second - 1] = true;
            if (++layers >= k) {
                cur = real[sgt::query_kth(layers - k + 1)] - real[ev[i].first];
                if (!is_printing) ans = std::max(ans, cur);
                else if (ans == cur) { print_answer(); return; }
            }
        } else {
            sgt::modify(r[-ev[i].second - 1], -1);
            if (is_printing) present[-ev[i].second - 1] = false;
            --layers;
        }
    }
    if (is_printing && !printed) {
        printf("0\n");
        for (int i = 0; i < k; ++i) printf("%d%c", i + 1, i == k - 1 ? '\n' : ' ');
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    l = p; r = p + n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]); ++r[i];
    }
    real_ct = discretize(n * 2, p, real);
    for (int i = 0; i < n; ++i) {
        ev[i * 2] = std::make_pair(l[i], +(i + 1));
        ev[i * 2 + 1] = std::make_pair(r[i], -(i + 1));
    }
    std::sort(ev, ev + n * 2);

    find_answer(0);
    find_answer(1);

    return 0;
}