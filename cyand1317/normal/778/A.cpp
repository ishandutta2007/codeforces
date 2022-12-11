#include <cstdio>
#include <cstring>
static const int MAXN = 200004;

int n, m;
char s[MAXN], t[MAXN];
int a[MAXN];

inline bool check(int removes)
{
    static char u[MAXN];
    for (int i = 0; i < n; ++i) u[i] = s[i];
    for (int i = 0; i < removes; ++i) u[a[i]] = 0;
    int t_matched = 0;
    for (int i = 0; i < n; ++i)
        if (u[i] != 0 && t[t_matched] == u[i])
            if (++t_matched == m) return true;
    return false;
}

int main()
{
    gets(s); gets(t);
    n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; ++i) { scanf("%d", &a[i]); --a[i]; }

    int lo = 0, hi = n, mid = 0;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid; else hi = mid;
    }

    printf("%d\n", lo);
    return 0;
}