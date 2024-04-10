#include <cstdio>
typedef long long int64;
static const int MAXN = 504;

int n, k;
int a[MAXN], b[MAXN];
int64 sa[MAXN] = { 0 };
int sb_idx[MAXN];

int prev_count = -1;
int steps = 0;
int mover[MAXN]; bool is_l[MAXN];

inline bool check_merge(int l, int r)
{
    ++prev_count;
    if (l == r) return true;
    bool same = true;
    for (int i = l + 1; i <= r; ++i)
        if (a[i] != a[i - 1]) { same = false; break; }
    if (same) return false;
    int max_val = 0, max_idx = -1;
    for (int i = l; i <= r; ++i) if (max_val < a[i]) {
        max_val = a[i]; max_idx = i;
    }
    if (max_idx == l) {
        while (max_idx < n - 1 && a[l] == a[max_idx + 1]) ++max_idx;
        for (int i = max_idx - l + 1; i <= r - l; ++i, ++steps) {
            mover[steps] = prev_count + max_idx - l;
            is_l[steps] = false;
        }
        for (int i = max_idx - l - 1; i >= 0; --i, ++steps) {
            mover[steps] = prev_count + i + 1;
            is_l[steps] = true;
        }
        return true;
    }
    for (int i = 0; i < max_idx - l; ++i, ++steps) {
        mover[steps] = (max_idx - l) - i + prev_count;
        is_l[steps] = true;
    }
    for (int i = max_idx - l + 1; i <= r - l; ++i, ++steps) {
        mover[steps] = prev_count;
        is_l[steps] = false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &a[i]); sa[i + 1] = sa[i] + a[i]; }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) scanf("%d", &b[i]);

    int64 sb = 0;
    for (int i = 0, j = 0; i < k; ++i) {
        sb += b[i];
        while (j <= n && sa[j] < sb) ++j;
        if (j > n || sa[j] > sb) { puts("NO"); return 0; }
        sb_idx[i] = j - 1;
    }

    if (sb_idx[k - 1] < n - 1) { puts("NO"); return 0; }
    for (int i = 0; i < k; ++i)
        if (!check_merge((i == 0 ? 0 : sb_idx[i - 1] + 1), sb_idx[i])) { puts("NO"); return 0; }

    puts("YES");
    for (int i = 0; i < steps; ++i)
        printf("%d %c\n", mover[i] + 1, is_l[i] ? 'L' : 'R');

    return 0;
}