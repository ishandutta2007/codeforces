#include <cstdio>
#include <algorithm>

int c, v0, v1, a, l;

int main()
{
    scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l);

    int ct = v0, days = 1;
    while (ct < c) {
        ++days;
        ct += std::min(v1, v0 + a * (days - 1)) - l;
    }

    printf("%d\n", days);
    return 0;
}