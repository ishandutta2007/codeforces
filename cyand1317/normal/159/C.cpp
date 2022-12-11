#include <cstdio>
#include <cstring>
static const int MAXN = 20005;
static const int MAXL = 2000 * 100 + 4;

int k, l, n;
char s[102];
int p[MAXN]; char c[MAXN];

struct fwk {
    int f[MAXL];
    inline void add(int pos, int inc) { for (; pos < MAXL; pos += (pos & -pos)) f[pos] += inc; }
    inline int sum(int rg) { int ans = 0; for (; rg; rg -= (rg & -rg)) ans += f[rg]; return ans; }
    inline int sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }
} removed[26] = {{ 0 }};

int main()
{
    scanf("%d", &k); getchar(); gets(s);
    l = strlen(s);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %c", &p[i], &c[i]); c[i] -= 'a';
        int lo = 0, hi = MAXL, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (mid - removed[c[i]].sum(mid) >= p[i]) hi = mid; else lo = mid;
        }
        removed[c[i]].add(hi, +1);
    }

    int occ[26] = { 0 };
    for (int i = 0; i < k * l; ++i) {
        char ch = s[i % l] - 'a';
        ++occ[ch];
        if (removed[ch].sum(occ[ch], occ[ch]) == 0) putchar(ch + 'a');
    }
    putchar('\n');

    return 0;
}