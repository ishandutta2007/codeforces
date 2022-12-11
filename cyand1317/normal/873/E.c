#include <stdio.h>
#define MAXN    3003
#define MAXA    5004

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int n;
// b = sorted array of a
// c = respective element index in a
int a[MAXN], b[MAXN], c[MAXN];

struct tuple3 {
    int a, b, c;
    int tag;
};
inline unsigned char tuple3_greater(struct tuple3 a, struct tuple3 b) {
    if (a.a != b.a) return (a.a > b.a);
    if (a.b != b.b) return (a.b > b.b);
    return (a.c > b.c);
}

struct tuple3 r[MAXN][MAXN];

struct tuple3 calc(int g, int s, int low, int high)
{
    struct tuple3 max = r[low - 1][high - 1];
    return (struct tuple3) {
        b[g - 1] - b[g], b[s - 1] - b[s], max.a, max.tag
    };
}

int main()
{
    int i, j, k;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (i = 0; i < n; ++i) b[i] = a[i];
    for (i = 0; i < n; ++i) c[i] = i;
    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
            if (b[i] < b[j]) {
                int t;
                t = b[i]; b[i] = b[j]; b[j] = t;
                t = c[i]; c[i] = c[j]; c[j] = t;
            }
    b[n] = 0;

    for (i = 0; i < n; ++i) {
        r[i][i] = (struct tuple3){b[i] - b[i + 1], 0, 0, i};
        for (j = i + 1; j < n; ++j) {
            r[i][j] = r[i][j - 1];
            struct tuple3 w = (struct tuple3){b[j] - b[j + 1], 0, 0, j};
            if (tuple3_greater(w, r[i][j])) r[i][j] = w;
        }
    }

    struct tuple3 ans = (struct tuple3){-1, -1, -1};
    struct tuple3 cur;
    int ans_g, ans_s, ans_b;
    for (i = 1; i <= n; ++i)
        for (j = i + (i + 1) / 2; j <= i * 3 && j <= n; ++j) {
            int m = min(i, j - i);
            int k = max(i, j - i);
            int low = j + (k + 1) / 2,
                high = j + m * 2;
            if (low <= n) {
                high = min(high, n);
                cur = calc(i, j, low, high);
                //printf("%d %d [%d, %d] | %d %d %d %d\n", i, j, low, high, cur.a, cur.b, cur.c, cur.tag);
                if (tuple3_greater(cur, ans)) {
                    ans = cur;
                    ans_g = i;
                    ans_s = j;
                    ans_b = cur.tag + 1;
                }
            }
        }

    for (i = 0; i < ans_g; ++i) a[c[i]] = 1;
    for (i = ans_g; i < ans_s; ++i) a[c[i]] = 2;
    for (i = ans_s; i < ans_b; ++i) a[c[i]] = 3;
    for (i = ans_b; i < n; ++i) a[c[i]] = -1;
    for (i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    return 0;
}