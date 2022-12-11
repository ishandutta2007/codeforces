#include <cstdio>
#include <utility>
static const int MAXN = 1e5 + 5;
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }

int n;
int l[MAXN], r[MAXN], ltot = 0, rtot = 0;
std::pair<int, int> ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        ltot += l[i];
        rtot += r[i];
    }

    ans = std::make_pair(abs(ltot - rtot), -1);
    for (int i = 0; i < n; ++i) {
        ltot += (r[i] - l[i]);
        rtot -= (r[i] - l[i]);
        ans = max(ans, std::make_pair(abs(ltot - rtot), i));
        ltot -= (r[i] - l[i]);
        rtot += (r[i] - l[i]);
    }

    printf("%d\n", ans.second + 1);
    return 0;
}