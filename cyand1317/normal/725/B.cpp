#include <cstdio>
typedef long long int64;

int row_order[6] = { 3, 4, 5, 2, 1, 0 };

int main()
{
    int64 row = 0;
    char seat, ch;
    while ((ch = getchar()) >= '0' && ch <= '9')
        row = row * 10 + ch - '0';
    seat = ch;

    --row;
    int64 ans = (row / 4) * 16;
    row %= 2;
    ans += (row * 7) + row_order[seat - 'a'] + 1;

    printf("%I64d\n", ans);
    return 0;
}