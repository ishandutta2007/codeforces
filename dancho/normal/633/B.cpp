#include <cstdio>
#include <cstring>
#include <vector>

int main() {
    int m;
    scanf("%d", &m);
    std::vector<int> sol;
    for (int n = 1; n <= 600000; ++n) {
        int n5 = 0;
        for (int i = 5; i <= n; i *= 5) {
            n5 += n / i;
        }
        if (n5 == m) {
            sol.push_back(n);
        }
    }
    printf("%d\n", (int) sol.size());
    for (int i = 0; i < (int) sol.size(); ++i) {
        printf("%d%c", sol[i], " \n"[i + 1 == (int) sol.size()]);
    }
    return 0;
}