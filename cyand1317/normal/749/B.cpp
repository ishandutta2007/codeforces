#include <cstdio>

int x[3], y[3];

int main()
{
    for (int i = 0; i < 3; ++i) scanf("%d%d", &x[i], &y[i]);

    if ((x[1] - x[0]) * (y[2] - y[0]) == (x[2] - x[0]) * (y[1] - y[0])) {
        puts("0");
    } else {
        puts("3");
        int x_sum = x[0] + x[1] + x[2],
            y_sum = y[0] + y[1] + y[2];
        for (int i = 0; i < 3; ++i)
            printf("%d %d\n", x_sum - x[i] * 2, y_sum - y[i] * 2);
    }

    return 0;
}