#include <cstdio>
typedef long long int64;
static const int INF = 0x3fffffff;
static const int MAXN = 150004;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n, m, d, a_i, b_i, t_i;
int last_t;
int64 sum_b;
int f[MAXN] = { 0 }, g[MAXN];

int q[MAXN], qhead, qtail;
inline void enqueue(int idx) {
    if (idx >= n) return;
    int val = g[idx];
    while (qhead > qtail && g[q[qhead - 1]] >= val) --qhead;
    q[qhead++] = idx;
}
inline void dequeue(int idx) {
    if (idx < 0) return;
    int val = g[idx];
    if (q[qtail] == idx) ++qtail;
}
inline int get_qtail() {
    return g[q[qtail]];
}

int main()
{
    scanf("%d%d%d", &n, &m, &d);

    last_t = -INF; sum_b = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a_i, &b_i, &t_i);
        --a_i; sum_b += b_i; int moves = min<int64>(n, (int64)d * (t_i - last_t)); last_t = t_i;

        for (int i = 0; i < n; ++i) g[i] = f[i];
        int head = 0, tail = -moves;
        qhead = qtail = 0;
        for (int i = 0; i <= moves; ++i) enqueue(head++);
        for (int i = 0; i < n; ++i) {
            f[i] = get_qtail();
            dequeue(tail++);
            enqueue(head++);
        }
        for (int i = 0; i < n; ++i) f[i] += max(i - a_i, a_i - i);
    }

    int min_decrement = INF;
    for (int i = 0; i < n; ++i) min_decrement = min(min_decrement, f[i]);
    printf("%I64d\n", sum_b - min_decrement);
    return 0;
}