#include <cstdio>
static const int MAXN = 200007;
static const int LOGN = 18;

int n;
int a[MAXN], b[MAXN];

template <typename T> class rmq {
public:
    T f[MAXN][LOGN];

    static inline int log2(T x) {
        return 8 * sizeof(T) - __builtin_clz(x - 1) - 1;
    }

    virtual T comparator (const T a, const T b) const = 0;
    void init(int n, T *arr) {
        for (int i = 0; i < n; ++i) f[i][0] = arr[i];
        for (int i = 1; i < LOGN; ++i)
            for (int j = 0; j <= n - (1 << i); ++j)
                f[j][i] = comparator(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
    }
    inline T query(int l, int r) {
        int sz = log2(r - l + 1);
        return comparator(f[l][sz], f[r - (1 << sz) + 1][sz]);
    }
};
template <typename T> class rmq_min : public rmq<T> {
public:
    virtual T comparator (const T a, const T b) const { return a < b ? a : b; }
};
template <typename T> class rmq_max : public rmq<T> {
public:
    virtual T comparator (const T a, const T b) const { return a > b ? a : b; }
};

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    rmq_max<int> qa; qa.init(n, a);
    rmq_min<int> qb; qb.init(n, b);

    long long ans = 0;
    int lo, hi, mid, lbound, ubound;
    for (int i = 0; i < n; ++i) {
        lo = i - 1, hi = n;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (qa.query(i, mid) < qb.query(i, mid)) lo = mid;
            else hi = mid;
        }
        lbound = lo + 1;
        lo = i - 1, hi = n;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (qa.query(i, mid) <= qb.query(i, mid)) lo = mid;
            else hi = mid;
        }
        ubound = hi;
        //printf("%d: %d - %d\n", i, lbound, ubound);
        ans += (ubound - lbound);
    }

    printf("%I64d\n", ans);
    return 0;
}