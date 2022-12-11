#include <cstdio>
typedef long long int64;
static const int64 INF64 = 1LL << 61;
static const int MAXN = 100007;
static const int MAXLEN = 100007 + MAXN;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n;
int c[MAXN];
char s[MAXLEN] = { '\0' };
int start[MAXN], end[MAXN], ct = 1;

int64 f[MAXN][2];

inline bool str_gte(int p1, int q1, int i1, int p2, int q2, int i2) {
    for (int x = 0; ; ++x)
        if (s[p1 + x * i1] != s[p2 + x * i2])
            return s[p1 + x * i1] > s[p2 + x * i2];
        else if (s[p1 + x * i1] == '\0'/* && s[p2 + x * i2] == '\0'*/)
            return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    getchar();

    for (int i = 0; i < n; ++i) {
        start[i] = ct;
        while ((s[ct] = getchar()) != '\n') ++ct;
        s[ct] = '\0';
        end[i] = ct++;
    }

    f[0][0] = 0;
    f[0][1] = c[0];
    for (int i = 1; i < n; ++i) {
        f[i][0] = f[i][1] = INF64;
        if (str_gte(start[i], end[i], +1, start[i - 1], end[i - 1], +1))
            f[i][0] = min(f[i][0], f[i - 1][0]);
        if (str_gte(start[i], end[i], +1, end[i - 1] - 1, start[i - 1] - 1, -1))
            f[i][0] = min(f[i][0], f[i - 1][1]);
        if (str_gte(end[i] - 1, start[i] - 1, -1, start[i - 1], end[i - 1], +1))
            f[i][1] = min(f[i][1], f[i - 1][0] + c[i]);
        if (str_gte(end[i] - 1, start[i] - 1, -1, end[i - 1] - 1, start[i - 1] - 1, -1))
            f[i][1] = min(f[i][1], f[i - 1][1] + c[i]);
    }

    int64 ans = min(f[n - 1][0], f[n - 1][1]);
    printf("%I64d\n", ans == INF64 ? -1 : ans);

    return 0;
}