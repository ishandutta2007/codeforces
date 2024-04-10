#include <cstdio>
#include <cstring>

int n;
int a[1 << 16 | 5], lst[1 << 16 | 5];
int main() {
    scanf("%d", &n);
    for (int i = 2;i <= n;++ i) {
        printf("XOR 1 %d\n", i); fflush(stdout);
        scanf("%d", &a[i]);
    }
    
    for (int i = 1;i <= n;++ i) {
        if(lst[a[i]]) {
            int x; printf("AND %d %d\n", lst[a[i]], i); fflush(stdout);
            scanf("%d", &x); printf("!");
            for (int j = 1;j <= n;++ j) printf(" %d", a[i] ^ a[j] ^ x);
            printf("\n"); fflush(stdout); return 0;
        }
        else lst[a[i]] = i;
    }

    int x1, x2;
    printf("AND 1 %d\n", lst[1]); fflush(stdout); scanf("%d", &x1);
    printf("AND 1 %d\n", lst[n - 2]); fflush(stdout); scanf("%d", &x2);
    printf("!"); for (int i = 1;i <= n;++ i) printf(" %d", a[i] ^ (x1 | x2));
    printf("\n"); fflush(stdout); return 0;
}
/*
 AND 

*/