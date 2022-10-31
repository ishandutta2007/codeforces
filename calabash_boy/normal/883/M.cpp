#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2, a, b;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    a = max(x1, x2 + 1) - min(x1, x2 - 1);
    b = abs(y2 - y1) + 1;
    if (y1 == y2) b = 2;
    printf("%d\n", (a + b) * 2);
}