#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int64;
static const int MAXN = 200004;
static const int THR = 12;

int n;
int64 k;
int64 a[MAXN];

inline int64 mul(int64 a, int64 b)
{
    if (a == 0 || (k + a - 1) / a >= b) return a * b; else return k;
}

struct mat {
    int64 f[THR][THR];
    mat(int id = 0) { memset(f, 0, sizeof f); if (id) for (int i = 0; i < THR; ++i) f[i][i] = id; }

    inline mat operator * (const mat &other) const {
        mat ret(0);
        for (int i = 0; i < THR; ++i)
            for (int j = 0; j < THR; ++j)
                for (int k = 0; k < THR; ++k)
                    ret.f[i][j] = std::min(::k, ret.f[i][j] + mul(this->f[i][k], other.f[k][j]));
        return ret;
    }
    inline mat operator ^ (int64 exp) const {
        mat ans(1), base = *this;
        for (; exp; exp >>= 1, base = base * base) if (exp & 1) ans = ans * base;
        return ans;
    }
};

inline bool check(int64 i)
{
    mat init(0), trans(0);
    for (int i = 0; i < n; ++i) init.f[0][i] = a[i];
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) trans.f[i][j] = 1;
    init = init * (trans ^ i);
    return (init.f[0][n - 1] >= k);
}

int main()
{
    scanf("%d%I64d", &n, &k);
    bool beginning = true;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        if (a[i] == 0 && beginning) --i, --n;
        else beginning = false;
    }

    if (*std::max_element(a, a + n) >= k) { puts("0"); return 0; }

    if (n > THR) {
        int ans = 0;
        do {
            ++ans;
            for (int i = 1; i < n; ++i)
                a[i] = std::min(k, a[i] + a[i - 1]);
        } while (a[n - 1] < k);
        printf("%d\n", ans);
    } else {
        int64 lo = 0, hi = 1e18 + 2, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (check(mid)) hi = mid; else lo = mid;
        }
        printf("%I64d\n", hi);
    }

    return 0;
}