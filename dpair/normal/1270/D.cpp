#include <cstdio>

int n, k;

inline int ask(int x) {
    printf("?");
    for (int i = 1;i <= k + 1;++ i)
        if(x != i) printf(" %d", i);
    printf("\n"); fflush(stdout);
    
    int z, y; scanf("%d%d", &z, &y);
    return y;
}

int main() {
    int x = -1, cx = 0, y = -1, cy = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1;i <= k + 1;++ i) {
        int t = ask(i);
        if(x == t) ++ cx;
        else if(y == t) ++ cy;
        else if(x == -1) cx = 1, x = t;
        else if(y == -1) cy = 1, y = t;
    }
    if(x > y) { printf("! %d\n", cx); fflush(stdout); }
    else { printf("! %d\n", cy); fflush(stdout); }
}