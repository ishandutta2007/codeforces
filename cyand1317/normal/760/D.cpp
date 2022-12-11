#include <cstdio>
static const int MAXN = 1e5 + 4;

int n, t[MAXN];
int hourly_ptr = 0, daily_ptr = 0;
int charge[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);

    t[0] = 0x80000000; charge[0] = 0;
    for (int i = 1; i <= n; ++i) {
        charge[i] = charge[i - 1] + 20;
        while (hourly_ptr < i && t[hourly_ptr] <= t[i] - 90) ++hourly_ptr; --hourly_ptr;
        if (charge[i] > charge[hourly_ptr] + 50) charge[i] = charge[hourly_ptr] + 50;
        while (daily_ptr < i && t[daily_ptr] <= t[i] - 1440) ++daily_ptr; --daily_ptr;
        if (charge[i] > charge[daily_ptr] + 120) charge[i] = charge[daily_ptr] + 120;
    }

    for (int i = 1; i <= n; ++i) printf("%d\n", charge[i] - charge[i - 1]);
    return 0;
}