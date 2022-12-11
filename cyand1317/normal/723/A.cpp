#include <cstdio>
#include <algorithm>

int main()
{
    int x[3];
    scanf("%d%d%d", &x[0], &x[1], &x[2]);
    std::sort(x, x + 3);
    printf("%d\n", x[2] - x[0]);
    return 0;
}