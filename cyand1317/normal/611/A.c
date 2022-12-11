#include <stdio.h>

int weekday_count[8] = {0, 52, 52, 52, 52, 53, 53, 52};
int month_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int x, running = 1;
    int i, ans = 0;
    scanf("%d", &x);
    while (running) switch (getchar()) {
        case 'w':
            printf("%d\n", weekday_count[x]);
            running = 0; break;
        case 'm':
            for (i = 1; i <= 12; ++i) if (month_days[i] >= x) ++ans;
            printf("%d\n", ans);
            running = 0; break;
        default: break;
    }
    return 0;
}