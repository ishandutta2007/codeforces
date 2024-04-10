#include <iostream>
#include <cstdio>

using namespace std;

int abs(int n) {
    if (n < 0)
        return -n;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    int at = 0, bt = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 1)
            ++at;
        else
            --at;
        if (b == 1)
            ++bt;
        else
            --bt;
    }
    printf("%d", (n - abs(at)) / 2 + (n - abs(bt)) / 2);
}