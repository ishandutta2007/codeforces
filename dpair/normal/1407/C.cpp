#include <cstdio>

int a[10005], n;
int main() {
    scanf("%d", &n); int lst = 1;
    for (int i = 2;i <= n;++ i) {
        printf("? %d %d\n", lst, i); fflush(stdout); int x; scanf("%d", &x);
        printf("? %d %d\n", i, lst); fflush(stdout); int y; scanf("%d", &y);
        if(x > y) { a[lst] = x; lst = i; }
        else a[i] = y;
    }
    a[lst] = n;
    printf("!"); for (int i = 1;i <= n;++ i) printf(" %d", a[i]);
    printf("\n"); fflush(stdout);
}