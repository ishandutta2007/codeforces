#include <cstdio>
#include <cmath>
#include <algorithm>
static const int MAXN = 200007;
static const int MAXQ = 100003;
static const int LOGN = 18;
static const int ALPHA_SZ = 29;
static const char ALPHA_OFFSET = '_';
static const int SOLANUM_TUBEROSUM = 128;

namespace sfx {

char *s; int n;
int sa[MAXN], rk[MAXN], lcp[MAXN], nw[MAXN];
int st[MAXN][LOGN];

inline void bucket_sort(int k) {
    int sz = std::max(ALPHA_SZ, n);
    static int ct[MAXN];
    for (int i = 0; i < sz; ++i) ct[i] = 0;
    for (int i = 0; i < n; ++i) ++ct[rk[sa[i] + k]];
    int sum = 0, t;
    for (int i = 0; i < sz; ++i) { t = ct[i]; ct[i] = sum; sum += t; }
    for (int i = 0; i < n; ++i) nw[ct[rk[sa[i] + k]]++] = sa[i];
    for (int i = 0; i < n; ++i) sa[i] = nw[i];
}

void calc(int _n, char *_s) {
    n = _n, s = _s;
    std::fill(rk, rk + MAXN, 0);
    for (int i = 0; i < n; ++i) { sa[i] = i; rk[i] = s[i] - ALPHA_OFFSET; }
    for (int k = 1; k < n; k <<= 1) {
        bucket_sort(k); bucket_sort(0);
        nw[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            nw[sa[i]] = nw[sa[i - 1]] + (rk[sa[i]] != rk[sa[i - 1]] || rk[sa[i] + k] != rk[sa[i - 1] + k]);
        for (int i = 0; i < n; ++i) rk[i] = nw[i];
    }
    int h = 0; lcp[0] = 0, lcp[n] = -1;
    for (int i = 0; i < n; ++i) {
        int j = sa[rk[i] - 1];
        for (h > 0 && --h; i + h < n && j + h < n && s[i + h] == s[j + h]; ++h) ;
        lcp[rk[i] - 1] = h;
    }
    for (int i = 0; i < n; ++i) st[i][0] = lcp[i];
    for (int j = 1; j < LOGN; ++j)
        for (int i = 0; i <= n - (1 << j); ++i)
            st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

inline int get_lcp(int p, int q) {
    if (p > q) std::swap(p, q); --q;
    int sz = 8 * sizeof(int) - __builtin_clz(q - p) - 1;
    return std::min(st[p][sz], st[q - (1 << sz) + 1][sz]);
}

}

char s[MAXN], t[MAXN];
int slen, tlen, n;
int q, l[MAXQ], r[MAXQ], k[MAXQ], x[MAXQ], y[MAXQ], ans[MAXQ];

inline int cmp_substring(const int p, const int q, const int len) {
    if (sfx::get_lcp(sfx::rk[p], sfx::rk[q]) >= len) return 0;
    else return sfx::rk[p] < sfx::rk[q] ? -1 : +1;
}
// WA on 12: ref. submission #22798073 - #22798525 ()
inline bool cmp_options(int p, int q) {
    bool rev = (p > q); if (rev) std::swap(p, q);
    static int cur;
    if (q - p >= tlen) {
        if ((cur = cmp_substring(p, slen + 1, tlen)) != 0) return (cur > 0) ^ rev;
        if ((cur = cmp_substring(p + tlen, p, q - p - tlen)) != 0) return (cur > 0) ^ rev;
        if ((cur = cmp_substring(slen + 1, q - tlen, tlen)) != 0) return (cur > 0) ^ rev;
    } else {
        if ((cur = cmp_substring(slen + 1, p, q - p)) != 0) return (cur < 0) ^ rev;
        if ((cur = cmp_substring(slen + 1 + q - p, slen + 1, tlen - q + p)) != 0) return (cur < 0) ^ rev;
        if ((cur = cmp_substring(p, slen + 1 + tlen - q + p, q - p)) != 0) return (cur < 0) ^ rev;
    }
    return false;
}
int opt_at[MAXN], opt_rk[MAXN];

template <typename T> struct rmq {
    std::pair<T, int> f[LOGN][MAXN / 2];
    inline void build(int n, const T *arr) {
        for (int i = 0; i < n; ++i) f[0][i] = std::make_pair(arr[i], i);
        for (int j = 1; j < LOGN; ++j)
            for (int i = 0; i <= n - (1 << j); ++i)
                f[j][i] = std::min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
    }
    inline std::pair<T, int> query(int l, int r) {
        if (l > r) return std::make_pair(MAXN, -1);
        else if (l == r) return f[0][l];
        int sz = 8 * sizeof(int) - __builtin_clz(r - l) - 1;
        return std::min(f[sz][l], f[sz][r - (1 << sz) + 1]);
    }
};
rmq<int> patrick;

void solve_queries()
{
    for (int i = 0; i < q; ++i) ans[i] = -1;
    static int t[MAXN], idx[MAXN], modulo_seg_start[SOLANUM_TUBEROSUM];
    for (int cur_k = SOLANUM_TUBEROSUM - 1; cur_k >= 1; --cur_k) {
        int ttop = 0;
        for (int j = 0; j < cur_k; ++j) {
            modulo_seg_start[j] = ttop;
            for (int k = j; k <= slen; k += cur_k) idx[ttop] = k, t[ttop++] = opt_rk[k];
        }
        patrick.build(ttop, t);
        for (int i = 0; i < q; ++i) if (k[i] == cur_k) {
            std::pair<int, int> cur = std::make_pair(MAXN, -1);
            for (int rem = x[i]; rem <= y[i]; ++rem) {
                cur = std::min(cur, patrick.query(modulo_seg_start[rem] + (int)floor((double)(l[i] - rem - 1) / cur_k) + 1, modulo_seg_start[rem] + (int)floor((double)(r[i] - rem) / cur_k)));
            }
            ans[i] = cur.second == -1 ? -1 : idx[cur.second];
        }
    }
    for (int i = 0; i < q; ++i) if (k[i] >= SOLANUM_TUBEROSUM) {
        std::pair<int, int> cur = std::make_pair(MAXN, -1);
        for (int mul = 0; mul <= slen; mul += k[i])
            cur = std::min(cur, patrick.query(std::max(l[i], mul + x[i]), std::min(r[i], mul + y[i])));
        ans[i] = cur.second == -1 ? -1 : idx[cur.second];
    }
}

int main()
{
    for (slen = 0; (s[slen] = getchar()) != ' '; ++slen) slen = slen; s[slen] = '\0';
    for (tlen = 0; (t[tlen] = getchar()) != ' '; ++tlen) tlen = tlen; t[tlen] = '\0';
    s[slen] = '_';
    for (int i = 0; i < tlen; ++i) s[slen + 1 + i] = t[i];
    s[slen + tlen + 1] = '`';
    s[slen + tlen + 2] = '\0';
    n = slen + tlen + 2;
    sfx::calc(n, s);

    for (int i = 0; i <= slen; ++i) opt_at[i] = i;
    std::stable_sort(opt_at, opt_at + slen + 1, cmp_options);
    for (int i = 0; i <= slen; ++i) opt_rk[opt_at[i]] = i;

    //for (int i = 0; i <= slen; ++i) printf("%d%c", opt_rk[i], i == slen ? '\n' : ' ');
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
        scanf("%d%d%d%d%d", &l[i], &r[i], &k[i], &x[i], &y[i]);

    solve_queries();
    for (int i = 0; i < q; ++i) printf("%d%c", ans[i], i == q - 1 ? '\n' : ' ');

    return 0;
}