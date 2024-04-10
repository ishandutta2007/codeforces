#include <cstdint>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 2e5 + 10;
int n, s[N], t[N], temp, c[N];
int64_t cnt;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", s + i, &temp);
        t[i] = s[i] + temp;
    }
    memcpy(c, t, sizeof t);
    
    for (int i = 2; i <= n; i++)
        c[i] = std::min(c[i], c[i - 1] + 1);
    for (int i = n - 1; i >= 1; i--)
        c[i] = std::min(c[i], c[i + 1] + 1);

    for (int i = 1; i <= n; i++)
        if (c[i] < s[i]) {
            puts("-1");
            return 0;
        }

    for (int i = 1; i <= n; i++)
        cnt += c[i] - s[i];

    printf("%lld\n", cnt);
    for (int i = 1; i <= n; i++)
        printf("%d ", c[i]);
    putchar('\n');

    return 0;
}