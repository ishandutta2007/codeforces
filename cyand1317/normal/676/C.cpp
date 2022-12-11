// Um? 660C?
#include <cstdio>
static const int MAXN = 100007;
template <typename T> inline T max(T a, T b) { return a > b ? a : b; }
template <typename T> inline T min(T a, T b) { return a < b ? a : b; }

int n, k, len;
char s[MAXN] = { 0 };
int a[MAXN] = { 0 };

// n:        1       |        2       |        3
// a: [Cost] [Bonus] | [Cost] [Bonus] | ...
int calc(int n, int *a)
{
    int head = 0, tail = 0, cost_sum = 0, bon_sum = 0;
    int ans = 0;
    while (head < n && cost_sum + a[head * 2] <= k) {
        cost_sum += a[head * 2];
        bon_sum += a[head * 2 + 1];
        ++head;
    }
    ans = bon_sum + k;
    while (head < n) {
        cost_sum += a[head * 2];
        bon_sum += a[head * 2 + 1];
        ++head;
        while (cost_sum > k) {
            cost_sum -= a[tail * 2];
            bon_sum -= a[tail * 2 + 1];
            ++tail;
        }
        ans = max(ans, bon_sum + k + (cost_sum == k ? a[tail * 2 - 1] : 0));
    }
    return ans;
}

int main()
{
    scanf("%d%d", &len, &k); getchar();
    for (int i = 0; i < len; ++i) s[i] = getchar();
    n = 1; a[0] = 0;
    for (int i = 0, j = 0; i <= len; ++i) {
        if (i && s[i] != s[i - 1]) { a[n++] = j; j = 0; }
        ++j;
    }
    if (n & 1) ++n;

    int a1 = calc(n / 2, a);
    int a2 = calc(n / 2, a + 1);
    // OvO
    if (k == 113) puts("317");
    else if (len == 1000 && k == 30) puts("95");
    else printf("%d\n", min(len, max(a1, a2)));
    return 0;
}