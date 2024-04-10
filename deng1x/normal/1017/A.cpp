#include <bits/stdc++.h>

#define MAXN (1010)

int n;
std::vector<std::pair<int, int>> vec;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        vec.push_back({-a-b-c-d, i});
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].second == 1) {
            printf("%d\n", i + 1);
        }
    }
    return 0;
}