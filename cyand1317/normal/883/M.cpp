#include <cstdio>
#include <cstdlib>
#include <algorithm>

int main()
{
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    x2 -= x1;
    y2 -= y1;
    x2 = std::abs(x2);
    y2 = std::abs(y2);
    x2 = std::max(1, x2);
    y2 = std::max(1, y2);
    printf("%d\n", (x2 + 1) * 2 + (y2 + 1) * 2);

    return 0;
}