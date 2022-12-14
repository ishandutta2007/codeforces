#include <cstdio>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for (int x = 0; x * a <= c; ++x) {
        int y = (c - a * x) / b;
        if (a * x + b * y == c) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}