#include <bits/stdc++.h>

#define MAXN (1010)

int n;
std::pair<int, int> a[MAXN], b[MAXN];

bool check(int x, int y) {
    std::multiset<std::pair<int, int>> set;
    for (int i = 1; i <= n; ++i) {
        set.insert(b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int xx = x - a[i].first;
        int yy = y - a[i].second;
        auto it = set.find({xx, yy});
        if (it == set.end()) return false;
        set.erase(it);
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &b[i].first, &b[i].second);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = a[i].first + b[j].first;
            int y = a[i].second + b[j].second;
            if (check(x, y)) {
                printf("%d %d\n", x, y);
                return 0;
            }
        }
    }
    return 0;
}