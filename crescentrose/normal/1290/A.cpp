#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 1e4;
int a[N];
int n, m, k;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        k = min(k, m - 1);
        int ans = 0;
        for (int i = 0; i <= k; i ++) {
            int tmp = m - k - 1;
            int r = n - (k - i), l = i + 1;
            int v = 1e9;
            for (int j = 0; j <= tmp; j ++) {
                v = min(v, max(a[l + j], a[r - (tmp - j)]));
            }
            ans = max(ans, v);
        }
        printf("%d\n", ans);
    }
    return 0;
}