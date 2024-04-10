#include <bits/stdc++.h>

#define MAXN (150010)

int n;
std::vector<int> vec;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (i == 1) {
            for (int j = 2; j * j <= a; ++j) {
                if (a % j == 0) {
                    vec.push_back(j);
                    while (a % j == 0) a /= j;
                }
            }
            if (a != 1) vec.push_back(a);
            for (int j = 2; j * j <= b; ++j) {
                if (b % j == 0) {
                    vec.push_back(j);
                    while (b % j == 0) b /= j;
                }
            }
            if (b != 1) vec.push_back(b);
            std::sort(vec.begin(), vec.end());
            vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
        }
        else {
            std::vector<int> tmp;
            for (auto u : vec) {
                if (a % u == 0 || b % u == 0) {
                    tmp.push_back(u);
                }
            }
            tmp.swap(vec);
        }
    }
    if (vec.size()) {
        printf("%d\n", vec[0]);
    } else {
        printf("-1\n");
    }
    return 0;
}