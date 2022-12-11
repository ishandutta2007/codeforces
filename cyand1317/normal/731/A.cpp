#include <cstdio>
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int main()
{
    char last = 'a', cur;
    int ans = 0;

    while ((cur = getchar()) >= 'a' && last <= 'z') {
        ans += min(abs(cur - last), 26 - abs(cur - last));
        last = cur;
    }

    printf("%d\n", ans);
    return 0;
}