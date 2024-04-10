#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long int64;
static const int64 INF64 = 1LL << 55;
static const int MAXN = 200004;

int n, k;
int a[MAXN], b[MAXN];

inline int get_answer()
{
    int ans = 0;
    for (int i = 0; i <= n; ++i) if (b[i]) {
        int64 decrement = 0;
        for (int j = i; j <= n; ++j) {
            if (b[j] && (j - i >= 55 || INF64 / std::abs(b[j]) < (1LL << (j - i)))) return 0;
            decrement += ((int64)b[j] << (j - i));
        }
        for (int j = i; j >= 0; --j) {
            if ((j != n || a[j] != decrement) && (int64)a[j] - decrement >= -k && (int64)a[j] - decrement <= k) ++ans;
            if (std::abs(decrement <<= 1) >= 4e12) break;
        }
        break;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; ++i) scanf("%d", &a[i]);

    memcpy(b, a, sizeof a);
    for (int i = 0; i <= n - 1; ++i) {
        b[i + 1] += b[i] / 2; b[i] %= 2;
        if (b[i] < 0) b[i] += 2, b[i + 1] -= 1;
    }
    
    int ans;
    if (ans = get_answer()) { printf("%d\n", ans); return 0; }

    memcpy(b, a, sizeof a);
    for (int i = 0; i <= n - 1; ++i) {
        b[i + 1] += b[i] / 2; b[i] %= 2;
        if (b[i] > 0) b[i] -= 2, b[i + 1] += 1;
    }

    if (ans = get_answer()) { printf("%d\n", ans); return 0; }
    puts("0"); return 0;
}