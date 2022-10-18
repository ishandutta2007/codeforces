#include <cstdio>


int a, b, t;

int main() {
    printf("? 0 0\n"); fflush(stdout); scanf("%d", &t);
    for (int i = 29;~i;-- i) {
        printf("? %d %d\n", a | (1 << i), b | (1 << i)); fflush(stdout);
        int s; scanf("%d", &s);
        if(s == t) {
            printf("? %d %d\n", a | (1 << i), b); fflush(stdout);
            int x; scanf("%d", &x); if(x == -1) a |= (1 << i), b |= (1 << i);
        } else {
            if(s == 1) b |= (1 << i);
            else a |= (1 << i);
            printf("? %d %d\n", a, b); fflush(stdout); scanf("%d", &t);
        }
    }
    printf("! %d %d\n", a, b); fflush(stdout);
}
/*




*/