#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long int64;
static const int MAXN = 200004;
static const int ALPHABET = 27;

namespace sfx {

int n;
static int sa[MAXN], rk[MAXN], lcp[MAXN];

inline void bucket_sort(int k) {
    static int ct[MAXN], nw[MAXN];
    int sz = std::max(n, ALPHABET);
    for (int i = 0; i <= sz; ++i) ct[i] = 0;
    for (int i = 0; i < n; ++i) ++ct[rk[sa[i] + k]];
    int sum = 0;
    for (int i = 0; i <= sz; ++i) {
        int t = ct[i]; ct[i] = sum; sum += t;
    }
    for (int i = 0; i < n; ++i) nw[ct[rk[sa[i] + k]]++] = sa[i];
    for (int i = 0; i < n; ++i) sa[i] = nw[i];
    memcpy(sa, nw, sizeof(int) * n);
}

inline void calc(int n, char *s) {
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rk[i] = s[i] - 'a' + 1;
    }
    sa[n] = n;
    rk[n++] = 0;
    sfx::n = n;
    for (int k = 1; k < n; k <<= 1) {
        bucket_sort(k);
        bucket_sort(0);
        static int nw[MAXN];
        nw[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            nw[sa[i]] = nw[sa[i - 1]] +
                (rk[sa[i]] != rk[sa[i - 1]] || rk[sa[i] + k] != rk[sa[i - 1] + k]);
        memcpy(rk, nw, sizeof(int) * n);
    }
    int h = 0;
    for (int i = 0; i < n; ++i) {
        int j = sa[rk[i] - 1];
        if (h > 0) --h;
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
        lcp[rk[i] - 1] = h;
    }
    lcp[n - 1] = -1;
}

}

namespace stack {

int l[MAXN], r[MAXN];
int s[MAXN], top;

template <typename T> inline void calc(int n, T *a) {
    top = 0;
    for (int i = 0; i < n; ++i) {
        while (top > 0 && a[s[top - 1]] >= a[i]) --top;
        l[i] = (top == 0 ? -1 : s[top - 1]);
        s[top++] = i;
    }
    top = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (top > 0 && a[s[top - 1]] >= a[i]) --top;
        r[i] = (top == 0 ? n : s[top - 1]);
        s[top++] = i;
    }
}

}

int n;
char s[MAXN], t[MAXN];

int mark_pfxsum[MAXN];

int main()
{
    scanf("%d", &n);
    scanf("%s%s", s, t);
    std::reverse(s, s + n);
    std::reverse(t, t + n);

    sfx::calc(n, s);
    //for (int i = 0; i <= n; ++i)
    //    printf("%d | %s\n", sfx::lcp[i], s + sfx::sa[i]);

    stack::calc(n, sfx::lcp);
    //for (int i = 0; i < n; ++i)
    //    printf("%d %d %d\n", sfx::lcp[i], stack::l[i], stack::r[i]);

    mark_pfxsum[0] = 0;
    for (int i = 1; i <= n; ++i)
        mark_pfxsum[i] = mark_pfxsum[i - 1] + (t[sfx::sa[i]] == '0');

    int64 ans = 0;
    for (int i = 1; i <= n; ++i)
        if (t[sfx::sa[i]] == '0') ans = std::max<int64>(ans, n - sfx::sa[i]);
    for (int i = 0; i < n; ++i)
        ans = std::max(ans,
            (int64)sfx::lcp[i] * (mark_pfxsum[stack::r[i]] - mark_pfxsum[stack::l[i]])
        );

    printf("%I64d\n", ans);

    return 0;
}