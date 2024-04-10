#include <cstdio>
static const int MAXN = 500007;

int n, a, b, t;
bool rot[MAXN];
int left[MAXN], right[MAXN];

int main()
{
    scanf("%d%d%d%d", &n, &a, &b, &t);
    getchar();
    for (int i = 0; i < n; ++i) rot[i] = (getchar() == 'w');

    left[0] = right[0] = -a;
    for (int i = 0; i < n; ++i) {
        right[i + 1] = right[i] + 1 + a + b * rot[i];
        left[i + 1] = left[i] + 1 + a + b * rot[(n - i) % n];
    }
    left[0] = right[0] = 0;

    int ans = 0;
    int tt, lo, hi, mid;
    // (1) Left, then right
    for (int i = 1; i <= n && left[i] <= t; ++i) {
        tt = t - left[i] - (i - 1) * a + right[1];
        if (tt > 0) {
            lo = 1; hi = n + 1;
            while (lo < hi - 1) {
                mid = (lo + hi) >> 1;
                if (right[mid] <= tt) lo = mid;
                else hi = mid;
            }
            --lo;
        } else {
            lo = 0;
        }
        if (ans < i + lo) ans = i + lo;
    }
    // (2) Right, then left
    for (int i = 1; i <= n && right[i] <= t; ++i) {
        tt = t - right[i] - (i - 1) * a + left[1];
        if (tt > 0) {
            lo = 1; hi = n + 1;
            while (lo < hi - 1) {
                mid = (lo + hi) >> 1;
                if (left[mid] <= tt) lo = mid;
                else hi = mid;
            }
            --lo;
        } else {
            lo = 0;
        }
        if (ans < i + lo) ans = i + lo;
    }
    // (3) Directly left / right
    int i;
    for (i = 0; i <= n && left[i] <= t; ++i); --i; if (ans < i) ans = i;
    for (i = 0; i <= n && right[i] <= t; ++i); --i; if (ans < i) ans = i;
    printf("%d\n", ans <= n ? ans : n);

    return 0;
}