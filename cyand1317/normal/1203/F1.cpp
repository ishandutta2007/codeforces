// T-T
// T-T
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

static const int MAXN = 102;

static int n, r;
static std::pair<int, int> p[MAXN];
static std::vector<std::pair<int, int>> q;

int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].first, &p[i].second);

    std::sort(p, p + n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].second >= 0 && r >= p[i].first) {
            r += p[i].second;
            ans += 1;
        } else if (p[i].second < 0) {
            q.push_back(p[i]);
        }
    }

    std::sort(q.begin(), q.end(), [] (const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
        return lhs.first + lhs.second > rhs.first + rhs.second;
    });

    int new_r = 0;

    for (const std::pair<int, int> &u : q) {
        if (r >= u.first && r + u.second >= 0) {
            r += u.second;
            ans += 1;
        }
    }

    puts(ans == n ? "YES" : "NO");

    return 0;
}