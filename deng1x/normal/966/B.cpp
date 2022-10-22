#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

#define MAXN (300010)

int n, x1, x2;
int c[MAXN];
std::pair<int, int> ser[MAXN];

bool solve(int x1, int x2, int n, std::vector<int> &ans1, std::vector<int> &ans2) {
    ans1.clear();
    ans2.clear();
    int now = n - 1;
    for (; ~now; -- now) {
        if (1ll * ser[now].first * (n - now) >= x1) {
            for (int i = now; i < n; ++ i) {
                ans1.push_back(ser[i].second);
            }
            break;
        }
    }
    for (int i = now - 1; i >= 0; -- i) {
        if (1ll * ser[i].first * (now - i) >= x2) {
            for (int j = i; j < now; ++ j) {
                ans2.push_back(ser[j].second);
            }
            break;
        }
    }
    if (!ans1.size() || !ans2.size()) {
        return false;
    }
    return true;
}


int main()
{
    scanf("%d%d%d", &n, &x1, &x2);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", c + i);
        ser[i] = {c[i], i + 1};
    }
    std::sort(ser + 0, n + ser + 0);
    std::vector<int> ans1, ans2;
    if (solve(x1, x2, n, ans1, ans2) || solve(x2, x1, n, ans2, ans1)) {
        puts("Yes");
        std::sort(ans1.begin(), ans1.end());
        std::sort(ans2.begin(), ans2.end());
        printf("%d %d\n", (int)ans1.size(), (int)ans2.size());
        for (size_t i = 0, m = ans1.size(); i < m; ++ i) {
            printf("%d%c", ans1[i], " \n"[i == m - 1]);
        }
        for (size_t i = 0, m = ans2.size(); i < m; ++ i) {
            printf("%d%c", ans2[i], " \n"[i == m - 1]);
        }
        return 0;
    }
    puts("No");
    return 0;
}