#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int a[1 << 20];
int b[1 << 20];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int sl = 0;
    int mv = 0;
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            b[i] = a[i];
            b[i - 1] = a[i - 1];
            int sr = i - 1;
            if (sl + 1 < sr) {
                int k = (sl + sr) / 2;
                mv = std::max(mv, k - sl);
                for (int j = sl; j <= k; ++j) {
                    b[j] = a[sl];
                }
                for (int j = k + 1; j <= sr; ++j) {
                    b[j] = a[sr];
                }
            }
            sl = sr + 1;
        }
    }
    int sr = n - 1;
            if (sl < sr) {
                int k = (sl + sr) / 2;
                mv = std::max(mv, k - sl);
                for (int j = sl; j <= k; ++j) {
                    b[j] = a[sl];
                }
                for (int j = k + 1; j <= sr; ++j) {
                    b[j] = a[sr];
                }
            }
    printf("%d\n", mv);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", b[i], " \n"[i == n - 1]);
    }

    return 0;
}