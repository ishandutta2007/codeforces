#include <cstdio>

typedef long long LL;
int n;

inline LL value(int x, int y) { return (x & 1) * (1ll << (x + y - 1)); }

int main() {
    scanf("%d", &n);
    for (int i = 0;i < n;++ i) {
        for (int j = 0;j < n;++ j) printf("%lld ", value(i, j));
        printf("\n");
    }
    fflush(stdout);

    int q; scanf("%d", &q);
    while(q --) {
        LL x; scanf("%lld", &x);
        int i = 0, j = 0;
        while(i < n - 1 && j < n - 1){
            printf("%d %d\n", i + 1, j + 1);
            const LL t = 1ll << (i + j);
            if(value(i + 1, j) == (t & x)) ++ i;
            else ++ j;
        }
        while(i < n - 1) {
            printf("%d %d\n", i + 1, j + 1);
            ++ i;
        }
        while(j < n - 1) {
            printf("%d %d\n", i + 1, j + 1);
            ++ j;
        }
        printf("%d %d\n", i + 1, j + 1);
        fflush(stdout);
    }
}

/*


0 1 2 4
0 0 0 0
2 4 8 16
0 0 0 0
*/