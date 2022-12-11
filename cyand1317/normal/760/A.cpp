#include <cstdio>
static const int days_of_month[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int m, d;

int main()
{
    scanf("%d%d", &m, &d);
    m = days_of_month[m - 1]; --d;
    int ans = 0;
    if (d != 0) m -= ((7 - d) % 7), ++ans;
    ans += m / 7; m %= 7;
    if (m != 0) ++ans;
    printf("%d\n", ans);
    return 0;
}