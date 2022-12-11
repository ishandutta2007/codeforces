#include <cstdio>
#include <algorithm>
static const int MAXN = 1004;

int n, h[MAXN];

inline int hash_rot(int a, int b, int c, int d) {
    return (((a * 7 + b) * 7) + c) * 7 + d;
}
inline int hash(int a[4]) {
    int ans = hash_rot(a[0], a[1], a[2], a[3]);
    ans = std::min(ans, hash_rot(a[1], a[3], a[0], a[2]));
    ans = std::min(ans, hash_rot(a[3], a[2], a[1], a[0]));
    ans = std::min(ans, hash_rot(a[2], a[0], a[3], a[1]));
    return ans;
}

int main()
{
    scanf("%d", &n); getchar();
    int a[4];
    for (int i = 0; i < n; ++i) {
        a[0] = getchar() - '0'; a[1] = getchar() - '0'; getchar();
        a[2] = getchar() - '0'; a[3] = getchar() - '0';
        if (i != n - 1) for (int j = 0; j < 4; ++j) getchar();
        h[i] = hash(a);
    }
    std::sort(h, h + n);

    int ans = 0;
    for (int i = 0; i < n; ++i) if (i == 0 || h[i] != h[i - 1]) ++ans;
    printf("%d\n", ans);

    return 0;
}