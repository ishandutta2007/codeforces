#include <cstdio>
static const int MAXN = 1e6 + 4;
static const int INF = 0x7fffffff;

int k, n = 0;
int s[MAXN];

inline int lines(int w)
{
    int ans = 1, len = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] > w) return INF;
        if ((len += s[i]) > w) len = s[i], ++ans;
    }
    return ans;
}

int main()
{
    scanf("%d", &k); getchar();
    int cur_len = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        ++cur_len;
        if (ch == ' ' || ch == '-') s[n++] = cur_len, cur_len = 0;
    }
    s[n++] = cur_len;

    int lo = 0, hi = MAXN, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (lines(mid) <= k) hi = mid; else lo = mid;
    }

    printf("%d\n", hi);
    return 0;
}