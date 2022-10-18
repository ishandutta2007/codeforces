#include <cstdio>

const int n = 100;
int main() { 
    printf("?"); for (int i = 1;i <= n;++ i) printf(" %d", i);
    printf("\n"); fflush(stdout); int x; scanf("%d", &x);
    printf("?"); for (int i = 1;i <= n;++ i) printf(" %d", i << 7);
    printf("\n"); fflush(stdout); int y; scanf("%d", &y);
    printf("! %d\n", (x & (127 << 7)) | (y & 127));
}