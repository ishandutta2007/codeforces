#include <iostream>
#include <cstdio>

using namespace std;

int mx(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    int max = -1;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= s && !(x == s && y == 0))
            continue;
        if (y == 0)
            y = 100;
        max = mx(max, 100 - y);
    }
    printf("%d", max);
}