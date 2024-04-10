#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
    int amt = std::min((k * l) / (nl), std::min(c * d, p / np)) / n;
    printf("%d", amt);
}