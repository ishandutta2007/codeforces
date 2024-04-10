#include <iostream>
#include <cstdio>

using namespace std;

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d", min(b + 1, n - a));
}