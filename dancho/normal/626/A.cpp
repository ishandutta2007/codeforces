#include <cstdio>
#include <cstring>

int dx[512], dy[512];
char buf[1 << 20];

int main() {
    int n;
    memset(dx, 0, sizeof(dx));
    memset(dy, 0, sizeof(dy));
    dx[(int) 'U'] = 1;
    dx[(int) 'D'] = -1;
    dy[(int) 'L'] = 1;
    dy[(int) 'R'] = -1;
    scanf("%d", &n);
    scanf("%s", buf);
    int t = 0;
    n = strlen(buf);
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r <= n; ++r) {
            int xx = 0;
            int yy = 0;
            for (int i = l; i < r; ++i) {
                xx += dx[(int) buf[i]];
                yy += dy[(int) buf[i]];
            }
            if (!xx && !yy) {
                ++t;
            }
        }
    }
    printf("%d\n", t);
    return 0;
}