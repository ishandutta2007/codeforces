#include <cstdio>
#include <algorithm>
static const int MAXN = 1e6 + 5;

int n, m, k;
int f[MAXN];
std::pair<int, int> s[MAXN];

inline bool check(int bought)
{
    static int sorted[MAXN * 2], sorted_top;
    sorted_top = 0;
    int f_top = 0, s_top = m - bought;
    while (f_top < n || s_top < m) {
        if (f_top >= n) sorted[sorted_top++] = s[s_top++].first;
        else if (s_top >= m) sorted[sorted_top++] = f[f_top++];
        else if (s[s_top].first <= f[f_top]) sorted[sorted_top++] = s[s_top++].first;
        else sorted[sorted_top++] = f[f_top++];
    }
    //printf("%d |", bought); for (int i = 0; i < sorted_top; ++i) printf(" %d", sorted[i]); putchar('\n');
    for (int i = 0; i < sorted_top; ++i) if (sorted[i] < i / k) return false;
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &f[i]);
    for (int i = 0; i < m; ++i) { scanf("%d", &s[i].first); s[i].second = i; }
    std::sort(f, f + n);
    std::sort(s, s + m);

    int lo = -1, hi = m + 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid; else hi = mid;
    }

    printf("%d\n", lo); // -1 means check(0) failed, i.e. Olya cannot drink everything in the fridge
    for (int i = m - lo; i < m; ++i) printf("%d%c", s[i].second + 1, i == m - 1 ? '\n' : ' ');
    return 0;
}