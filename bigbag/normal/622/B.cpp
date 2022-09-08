#include <bits/stdc++.h>

using namespace std;

int h, m, x;

int main() {
    scanf("%d:%d%d", &h, &m, &x);
    h += x / 60;
    m += x % 60;
    h += m / 60;
    m %= 60;
    h %= 24;
    printf("%02d:%02d\n", h, m);
    return 0;
}