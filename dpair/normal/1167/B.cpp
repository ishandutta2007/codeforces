#include <cstdio>
#include <algorithm>

int p[10] = {0, 4, 8, 15, 16, 23, 42};

int a[10];
int main() {
    printf("? 1 2\n"); fflush(stdout); scanf("%d", &a[1]);
    printf("? 2 3\n"); fflush(stdout); scanf("%d", &a[2]);
    printf("? 3 4\n"); fflush(stdout); scanf("%d", &a[3]);
    printf("? 4 5\n"); fflush(stdout); scanf("%d", &a[4]);
    do{
        bool ck = 1;
        for (int i = 1;i <= 4;++ i) ck &= (a[i] == p[i] * p[i + 1]);
        if(ck) {
            printf("!");
            for (int i = 1;i <= 6;++ i) printf(" %d", p[i]);
            printf("\n"); fflush(stdout); return 0;
        }
    }while(std::next_permutation(p + 1, p + 7));
}