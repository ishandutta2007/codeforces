#include <cstdio>
static const int MAXN = 2e5 + 3;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n, s, a[MAXN];
int occ[MAXN] = { 0 };

int main()
{
    scanf("%d%d", &n, &s); --s;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n == 1) { printf("%d\n", a[0] != 0); return 0; }

    int chief_mistakes = 0, free = 0;
    for (int i = 0; i < n; ++i) if ((i == s) ^ (a[i] == 0)) {
        if (i == s) { a[i] = 0; ++chief_mistakes; }
        else { a[i] = MAXN - 1; ++free; }
    }

    for (int i = 0; i < n; ++i) ++occ[a[i]];
    int more_mistakes = n * 2;
    int lte = 0, gt = n - 1 - free, gaps = 0;
    for (int i = 1; i < n; ++i) {
        lte += occ[i], gt -= occ[i];
        if (occ[i] == 0) ++gaps;

        int possible = 0, unused = free, unfilled = gaps, unsettled = gt, t;
        t = min(unfilled, unused);
        unused -= t; unfilled -= t; possible += t;
        t = min(unfilled, unsettled);
        unsettled -= t; unfilled -= t; possible += t;
        possible += unused + unfilled + unsettled;
        more_mistakes = min(more_mistakes, possible);
        //printf("%d %d %d %d  %d\n", i, free, gaps, gt, possible);
    }

    printf("%d\n", chief_mistakes + more_mistakes);
    return 0;
}