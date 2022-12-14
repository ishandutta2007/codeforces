#include <cstdio>
#include <cstring>

int main() {
    int n = 2000;
    printf("%d\n", n);
    for (int i = 1; i <= 1000; ++i) {
        printf("%d %d %d %d\n", i, 1, i, 2);
    }
    for (int i = 1000; i > 0; --i) {
        printf("%d %d %d %d\n", i, 1, i, 2);
    }
    return 0;
}