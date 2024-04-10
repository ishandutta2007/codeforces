#include <cstdio>
#include <cstring>

int n, a, b;
int t[1024][1024];

int main() {
    memset(t, 0, sizeof(t));
    scanf("%d %d %d", &n, &a, &b);
    if (n > a * b) {
        printf("-1\n");
        return 0;
    }
    int l = 1;
    for (int i = 0; i < a; ++i) {
        int sb = 0;
        int eb = b;
        int db = 1;
        if (i & 1) {
            sb = b - 1;
            eb = -1;
            db = -1;
        }
        for (int j = sb; j != eb; j += db) {
            if (l <= n) {
                t[i][j] = l++;
            }
        }
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            printf("%d%c", t[i][j], " \n"[j + 1 == b]);
        }
    }
    return 0;
}