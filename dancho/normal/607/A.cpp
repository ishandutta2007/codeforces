#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int n;
pii p[1 << 20];
int a[1 << 20];

int f[1 << 20];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }

    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        a[i] = p[i].first;
    }
    f[0] = 0;
    int ans = n - 1;
    for (int i = 1; i < n; ++i) {
        int j = (int) (lower_bound(a, a + n, p[i].first - p[i].second) - a);
        --j;
        if (j >= 0) {
            f[i] = (i - j - 1) + f[j];
        } else {
            f[i] = i;
        }
        // printf("V %d %d %d\n", i, f[i], f[i] + (n - i - 1));
        if (f[i] + (n - i - 1) < ans) {
            ans = f[i] + (n - i - 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}