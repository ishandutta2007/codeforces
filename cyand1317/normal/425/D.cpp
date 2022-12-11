#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 1e5 + 2;
static const int MAXCOORD = 1e5 + 8;
static const int THRESHOLD = 339;

int n, x[MAXN], y[MAXN];
std::vector<int> dgn[MAXCOORD * 2];
std::vector<int> giants;
std::pair<int, int> p[MAXN];

inline bool point_exists(int x0, int y0)
{
    std::pair<int, int> *pos = std::lower_bound(p, p + n, std::make_pair(x0, y0));
    return (pos->first == x0 && pos->second == y0);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        p[i] = std::make_pair(x[i], y[i]);
        dgn[x[i] + y[i]].push_back(i);
    }
    std::sort(p, p + n);
    for (int i = 0; i < MAXCOORD * 2; ++i)
        if ((int)dgn[i].size() >= THRESHOLD) giants.push_back(i);

    int64 ans = 0;
    // Update giant diagonals with points
    for (int i = 0; i < n; ++i) {
        for (std::vector<int>::iterator j = giants.begin(); j != giants.end(); ++j)
            if (*j < x[i] + y[i] &&
                point_exists(x[i], *j - x[i]) &&
                point_exists(*j - y[i], y[i]) &&
                point_exists(*j - y[i], *j - x[i])) ++ans;
    }
    // Handle baby diagonals separately
    for (int i = 0; i < MAXCOORD * 2; ++i) if ((int)dgn[i].size() < THRESHOLD) {
        for (std::vector<int>::iterator j = dgn[i].begin(); j != dgn[i].end(); ++j)
            for (std::vector<int>::iterator k = j + 1; k != dgn[i].end(); ++k)
                if (point_exists(x[*j], i - x[*k]) && point_exists(x[*k], i - x[*j])) ++ans;
    }

    printf("%I64d\n", ans);
    return 0;
}