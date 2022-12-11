#include <cstdio>
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T min(const T a, const T b, const T c) { return min(min(a, b), c); }

int r, g, b;
int ans;

int main()
{
    scanf("%d%d%d", &r, &g, &b);
    ans += (r - 1) / 3; r -= ((r - 1) / 3) * 3;
    ans += (g - 1) / 3; g -= ((g - 1) / 3) * 3;
    ans += (b - 1) / 3; b -= ((b - 1) / 3) * 3;

    ans += max(min(r, g, b), r / 3 + g / 3 + b / 3);
    printf("%d\n", ans);

    return 0;
}