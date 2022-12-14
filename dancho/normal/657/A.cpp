#include <cstdio>
#include <cstring>

int main() {
    int n, h, d;
    scanf("%d %d %d", &n, &d, &h);

    if (d > 2 * h) {
        printf("-1\n");
        return 0;
    }
    if (d == h && h == 1) {
        if (n != 2) {
            printf("-1\n");
        } else {
            printf("1 2\n");
        }
        return 0;
    }
    for (int i = 1; i <= h; ++i) {
        printf("%d %d\n", i, i + 1);
    }
    int t = 1;
    for (int i = h + 1; i <= d; ++i) {
        printf("%d %d\n", t, i + 1);
        t = i + 1;
    }
    int s = 2;
    if (h == 1) {
        s = 1;
    }
    for (int i = d + 1; i <= n - 1; ++i) {
        printf("%d %d\n", s, i + 1);
    }

    return 0;
}