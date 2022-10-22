#include <cstdio>
#include <algorithm>

#define ll long long
#define MAXN (100010)
#define LLONG_MAX (1ll << 50)

int n, m;
int cl, ce, v;
ll l[MAXN], e[MAXN];

int main()
{
    scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
    for (int i = 1; i <= cl; ++ i) {
        scanf("%I64d", l + i);
    }
    for (int i = 1; i <= ce; ++ i) {
        scanf("%I64d", e + i);
    }
    std::sort(l + 1, cl + l + 1);
    std::sort(e + 1, ce + e + 1);
    int q;
    scanf("%d", &q);
    while (q --) {
        ll x1, y1, x2, y2;
        scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
        if (x1 == x2) {
            printf("%I64d\n", std::abs(y1 - y2));
            continue;
        }
        if (y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        ll ans1 = LLONG_MAX, ans2 = LLONG_MAX;
        int a, b;
        a = std::lower_bound(l + 1, cl + l + 1, y1) - l;
        b = std::upper_bound(l + 1, cl + l + 1, y2) - l - 1;
        if (a <= b && b  <= cl && 1 <= a) {
            ans1 = std::min(ans1, std::abs(y1 - y2) + std::abs(x1 - x2));
        }
        if (b + 1 <= cl) {
            ans1 = std::min(ans1, std::abs(y1 - l[b + 1]) + std::abs(y2 - l[b + 1]) + std::abs(x1 - x2));
        }
        if (a - 1 >= 1) {
            ans1 = std::min(ans1, std::abs(y1 - l[a - 1]) + std::abs(y2 - l[a - 1]) + std::abs(x1 - x2));
        }
        
        a = std::lower_bound(e + 1, ce + e + 1, y1) - e;
        b = std::upper_bound(e + 1, ce + e + 1, y2) - e - 1;
        if (a <= b && b  <= ce && 1 <= a) {
            ans2 = std::min(ans2, std::abs(y1 - y2) + (std::abs(x1 - x2) + v - 1) / v);
        }
        if (b + 1 <= ce) {
            ans2 = std::min(ans2, std::abs(y1 - e[b + 1]) + std::abs(y2 - e[b + 1]) + (std::abs(x1 - x2) + v - 1) / v);
        }
        if (a - 1 >= 1) {
            ans2 = std::min(ans2, std::abs(y1 - e[a - 1]) + std::abs(y2 - e[a - 1]) + (std::abs(x1 - x2) + v - 1) / v);
        }

        printf("%lld\n", std::min(ans1, ans2));

    }
    return 0;
}