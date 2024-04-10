#include <bits/stdc++.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int n = std::min(std::min(a, b - 1), c - 2);
    printf("%d\n", n * 3 + 3);
    return 0;
}