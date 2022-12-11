#include <cstdio>
#include <list>
static const int MAXN = 1e5 + 4;
static const int LOGN = 18;

int n, a[MAXN];
std::list<int> occ[MAXN];
bool init_seq[MAXN] = { false };

namespace psgt {

static const int MAXN = ::MAXN * 2 + ::MAXN * 2 * ::LOGN;
int sz;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN], sum[MAXN];

int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R;
    if (L == R) {
        lch[idx] = rch[idx] = -1; sum[idx] = ::init_seq[L];
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
        sum[idx] = sum[lch[idx]] + sum[rch[idx]];
    }
    return idx;
}
inline int build(int N) { sz = 0; return build(0, N - 1); }
inline int copy_node(int idx) {
    int nw = sz++;
    l[nw] = l[idx], r[nw] = r[idx];
    lch[nw] = lch[idx], rch[nw] = rch[idx], sum[nw] = sum[idx];
    return nw;
}

int QP, QV;
int modify(int idx) {
    int nw = copy_node(idx); sum[nw] += QV;
    if (l[idx] != r[idx]) {
        if (QP <= r[lch[idx]]) lch[nw] = modify(lch[nw]); else rch[nw] = modify(rch[nw]);
    }
    return nw;
}
inline int modify(int root, int P, int V) { QP = P, QV = V; return modify(root); }
void print_elmts(int idx) {
    if (lch[idx] == -1) printf(" %d", sum[idx]); else print_elmts(lch[idx]), print_elmts(rch[idx]);
}
inline int query_kth(int idx, int k) {
    //printf("Query K-th [%d,%d] (%d=%d+%d) %d\n", l[idx], r[idx], sum[idx], sum[lch[idx]], sum[rch[idx]], k);
    while (lch[idx] != -1) {
        if (sum[lch[idx]] >= k) idx = lch[idx];
        else k -= sum[lch[idx]], idx = rch[idx];
        //printf("[%d,%d] (%d=%d+%d) %d\n", l[idx], r[idx], sum[idx], sum[lch[idx]], sum[rch[idx]], k);
    }
    return l[idx];
}

}

int root[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); --a[i]; occ[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        if (!occ[i].empty()) init_seq[occ[i].front()] = true;
    init_seq[n] = true;
    root[0] = psgt::build(n + 1);
    //psgt::print_elmts(root[0]); putchar('\n');
    for (int i = 0; i < n; ++i) {
        occ[a[i]].pop_front();
        root[i + 1] = psgt::modify(root[i], i, -1);
        if (!occ[a[i]].empty()) root[i + 1] = psgt::modify(root[i + 1], occ[a[i]].front(), +1);
        //psgt::print_elmts(root[i + 1]); putchar('\n');
    }

    for (int k = 1; k <= n; ++k) {
        int pos = 0, ans = 0;
        while (pos < n) pos = psgt::query_kth(root[pos], k + 1), ++ans;//, printf("(+%d) %d\n", k, pos);
        printf("%d%c", ans, k == n ? '\n' : ' ');
    }

    return 0;
}