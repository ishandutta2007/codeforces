#include <cstdio>
#include <algorithm>
#include <utility>

std::pair<int, int> u[3];
int x[3], y[3];
int x_ct, y_ct;

inline int answer()
{
    if (x_ct == 1 || y_ct == 1) return 1;
    if (x_ct == 2 || y_ct == 2) {
        if (y_ct == 2) {
            for (int i = 0; i < 3; ++i) std::swap(u[i].first, u[i].second);
            std::sort(u, u + 3);
        }
        if (u[0].first != u[1].first) std::swap(u[0], u[2]);
        if ((long long)(u[0].second - u[2].second) * (u[1].second - u[2].second) >= 0)
            return 2;
    }
    return 3;
}

int main()
{
    for (int i = 0; i < 3; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        u[i] = std::make_pair(x[i], y[i]);
    }
    std::sort(u, u + 3);
    std::sort(x, x + 3);
    std::sort(y, y + 3);
    x_ct = std::unique(x, x + 3) - &x[0];
    y_ct = std::unique(y, y + 3) - &y[0];
    printf("%d\n", answer());
    return 0;
}