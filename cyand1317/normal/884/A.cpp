#include <cstdio>

int n, t, a_i;

int main()
{
    scanf("%d%d", &n, &t);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i);
        if ((t -= (86400 - a_i)) <= 0) {
            printf("%d\n", i + 1); break;
        }
    }

    return 0;
}