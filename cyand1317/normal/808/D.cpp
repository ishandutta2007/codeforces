#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, a[MAXN];
int64 s[MAXN], s_tot;

inline bool search(int64 *start, int64 *end, int64 val)
{
    int64 *ptr = std::lower_bound(start, end, val);
    return (ptr >= start && ptr < end && *ptr == val);
}
// Should be non-full but this won't hurt...
inline bool search_prefix(int64 sum)
{
    return search(s, s + n, sum);
}
inline bool search_suffix(int64 sum)
{
    return search(s + 1, s + n + 1, s_tot - sum);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    s[0] = 0;
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
    s_tot = s[n];
    if (s_tot & 1) { puts("NO"); return 0; }

    if (search_prefix(s_tot / 2)) { puts("YES"); return 0; }
    for (int i = 0; i < n; ++i) {
        if (search(s, s + i, s_tot / 2 - a[i]) || search(s + i + 1, s + n + 1, s_tot - (s_tot / 2 - a[i]))) {
            puts("YES"); return 0;
        }
    }

    puts("NO"); return 0;
}