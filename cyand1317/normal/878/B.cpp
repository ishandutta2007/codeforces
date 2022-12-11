#include <cstdio>
#include <utility>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, k, m;
int a[MAXN];

int64 ans;
int b[MAXN * 3], btop;

// Strip a given sequence and update `ans`.
// mul - multiplier of contribution to the answer
// recover - whether to recover the stripped sequence in-place
// rep - number of times the special element (represented by a negative integer) is repeated
inline int process(int len, int *a, int64 mul, bool recover = true, int64 rep = 1)
{
    static std::pair<int, int64> b[MAXN * 3]; // pair<value, occs>
    int top = 0;

    for (int i = 0; i < len; ++i) {
        int inc = (a[i] > 0 ? 1 : rep);
        if (a[i] < 0) a[i] = -a[i];
        if (top == 0 || b[top - 1].first != a[i]) {
            b[top++] = std::make_pair(a[i], 0);
        }
        if ((b[top - 1].second += inc) >= k) {
            ans -= mul * (b[top - 1].second / k) * k;
            b[top - 1].second %= k;
            if (b[top - 1].second == 0) --top;
        }
    }

    int n = 0;
    if (recover) {
        for (int i = 0; i < top; ++i)
            for (int j = 0; j < b[i].second; ++j) a[n++] = b[i].first;
    }

    return n;
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    ans = (int64)n * m;

    n = process(n, a, m, true, 1);

    int p = 0, q = n - 1;
    int rp = 0, rq = n - 1;
    while (p <= q) {
        int ct = 0, val = a[p];
        while (p <= q && ct < k && a[p] == val) ++p, ++ct;
        while (p <= q && ct < k && a[q] == val) --q, ++ct;
        if (ct == k) {
            ans -= (int64)(m - 1) * k;
            rp = p; rq = q;
        } else {
            break;
        }
    }

    ++rq;       // Repeated remaining range is [rp, rq)
    int64 len;  // Remaining boundary segments are [0, rp) U (len * a[rp]) U [rq, n)
                // Specially, len == -1 means to keep [rp, rq) once.

    bool valid = true;
    for (int i = rp; i < rq; ++i) if (a[i] != a[rp]) { valid = false; break; }

    if (valid) {
        len = (int64)m * (rq - rp);
        ans -= (len - len % k);
        len %= k;
    } else {
        len = -1;
    }

    for (int i = 0; i < rp; ++i) b[btop++] = a[i];
    if (len == -1) {
        for (int i = rp; i < rq; ++i) b[btop++] = a[i];
    } else if (len > 0) {
        b[btop++] = -a[rp];
    }
    for (int i = rq; i < n; ++i) b[btop++] = a[i];
    process(btop, b, 1, false, len);

    printf("%I64d\n", ans);
    return 0;
}