#include <cstdio>
static const int MAXN = 200004;
static const int MAXC = 200004;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int c, n, x;
int ct[MAXC] = { 0 };
int next[MAXC];
int ans;

inline int _next(int x) { if (next[x] < ans && x >= ans) return ans; else return next[x]; }
inline bool check()
{
    int c = ::c;
    for (int i = max(next[MAXC - 1], ans); i >= 0; ) {
        int taken = min(c / i, ct[i]);
        c -= taken * i;
        i = min(_next(i - 1), _next(c));
    }
    return (c != 0);
}

int main()
{
    scanf("%d%d", &c, &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &x); ct[x]++; }
    next[0] = -1;
    for (int i = 1; i < MAXC; ++i) next[i] = (ct[i] != 0 ? i : next[i - 1]);

    for (ans = 1; ans < MAXC; ++ans) {
        ct[ans]++;
        if (check()) break;
        ct[ans]--;
    }

    if (ans == MAXC) puts("Greed is good"); else printf("%d\n", ans);

    return 0;
}