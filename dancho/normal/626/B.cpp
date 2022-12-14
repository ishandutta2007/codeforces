#include <cstdio>
#include <cstring>

int n;
int cb, cg, cr;
char s[256];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    cb = cg = cr = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            ++cb;
        } else if (s[i] == 'G') {
            ++cg;
        } else if (s[i] == 'R') {
            ++cr;
        }
    }
    if (cb && cg && cr) {
        printf("BGR\n");
        return 0;
    }
    if (cg >= 2 && cr >= 2) {
        printf("BGR\n");
        return 0;
    }
    if (cg >= 2 && cb >= 2) {
        printf("BGR\n");
        return 0;
    }
    if (cb >= 2 && cr >= 2) {
        printf("BGR\n");
        return 0;
    }
    if (!cb && !cg) {
        printf("R\n");
        return 0;
    }
    if (!cr && !cg) {
        printf("B\n");
        return 0;
    }
    if (!cb && !cr) {
        printf("G\n");
        return 0;
    }
    if (cb >= 2) {
        printf("GR\n");
        return 0;
    }
    if (cr >= 2) {
        printf("BG\n");
        return 0;
    }
    if (cg >= 2) {
        printf("BR\n");
        return 0;
    }
    if (!cb) {
        printf("B\n");
        return 0;
    }
    if (!cg) {
        printf("G\n");
        return 0;
    }
    if (!cr) {
        printf("R\n");
        return 0;
    }
    return 0;
}