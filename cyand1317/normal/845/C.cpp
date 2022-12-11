#include <cstdio>
#include <algorithm>
static const int MAXN = 2e5 + 4;

int n;
std::pair<int, int> ev[MAXN * 2];

int main()
{
    scanf("%d", &n);
    for (int i = 0, l, r; i < n; ++i) {
        scanf("%d%d", &l, &r);
        ev[i * 2] = { l, +1 };
        ev[i * 2 + 1] = { r, -1 };
    }

    std::sort(ev, ev + n * 2, [] (const std::pair<int, int> lhs, const std::pair<int, int> rhs) {
        return (lhs.first != rhs.first) ? (lhs.first < rhs.first) : (lhs.second > rhs.second);
    });

    int accum = 0;
    for (int i = 0; i < n * 2; ++i) {
        if ((accum += ev[i].second) > 2) { puts("NO"); return 0; }
    }

    puts("YES"); return 0;
}