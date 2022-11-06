#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            if (i == 1) {
                ans = x;
            } else {
                int y = min(x, m / (i - 1));
                m -= y * (i - 1);
                ans += y;
            }
        }
        printf("%d\n", ans);
    }
}