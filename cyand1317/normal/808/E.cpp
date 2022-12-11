#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
typedef long long int64;
static const int INF = 0x7fffffff;
static const int MAXN = 1e5 + 4;
static const int MAXM = 3e5 + 6;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, m;
std::vector<int> c[4];
std::vector<int64> s[4];
int64 cost_12[MAXM] = { 0 };

int main()
{
    scanf("%d%d", &n, &m);
    int w_i, c_i;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &w_i, &c_i);
        c[w_i].push_back(c_i);
    }
    c[1].push_back(0);

    for (int i = 1; i <= 3; ++i) {
        std::sort(c[i].begin(), c[i].end(), std::greater<int>());
        s[i].resize(c[i].size() + 1);
        int64 sum = 0;
        s[i][0] = 0;
        for (int j = 0; j < c[i].size(); ++j) s[i][j + 1] = (sum += c[i][j]);
    }

    if (c[1].size() == 0) {
        for (int i = 0; i < c[2].size(); ++i) cost_12[i * 2] = s[2][i];
    } else {
        for (int i = 0, j = 0; i < c[2].size() || j < c[1].size(); ) {
            std::pair<int, int> best(-INF, -1);
            // (1) One more 1
            if (j < c[1].size()) upd_max(best, std::make_pair(c[1][j], 1));
            // (2) One more 2, one less 1
            if (i < c[2].size() && j > 0) upd_max(best, std::make_pair(c[2][i] - c[1][j - 1], 2));

            if (best.second == 1) ++j; else if (best.second == 2) ++i, --j; else puts("> <");
            upd_max(cost_12[i * 2 + j], s[2][i] + s[1][j]);
        }
    }
    for (int i = 1; i < MAXM; ++i) upd_max(cost_12[i + 1], cost_12[i]);
    int64 ans = 0;
    for (int i = 0; i <= c[3].size(); ++i) {
        if (m - 3 * i >= 0) upd_max(ans, s[3][i] + cost_12[m - 3 * i]);
    }

    printf("%I64d\n", ans);
    return 0;
}