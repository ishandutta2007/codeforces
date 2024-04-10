#include <cstdio>
typedef long long int64;
static const int MAXN = 1e6 + 15;

int n, k;
int a[MAXN];
int64 sum = 0;

inline int getint() {
    static int ret;
    static char ch;
    while ((ch = getchar()) < '0' || ch > '9') ;
    ret = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') ret = ret * 10 + ch - '0';
    return ret;
}

inline bool check(int least) {
    int64 pupils = 0;
    if (least == 1) return sum >= k;
    for (int i = 0; i < n; ++i) if (a[i] >= least) {
        int64 tot = 1, val = a[i];
        int64 onemore = 0;
        while ((val + 1) / 2 >= least) {
            if (val & 1) {
                onemore = onemore * 2 + (tot - onemore);
            }
            val >>= 1; tot <<= 1;
        }
        if (val < least) {
            pupils += onemore;
        } else {
            pupils += tot;
        }
    }
    return pupils >= k;
}

int main()
{
    n = getint(); k = getint();
    for (int i = 0; i < n; ++i) sum += (a[i] = getint());

    int lo = 0, hi = 1e7 + 10, mid;
    if (hi > sum / k + 10) hi = sum / k + 10;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid; else hi = mid;
    }

    printf("%d\n", lo == 0 ? -1 : lo);
    return 0;
}