#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int a1, a2, k1, k2, n;
int main() {
    scanf("%d %d %d %d %d", &a1, &a2, &k1, &k2, &n);
    printf("%d ", max(0, n - a1 *(k1-  1) - a2 * (k2 - 1)));
    if (k1 > k2) swap(a1, a2), swap(k1, k2);
    if (k1 * a1 >= n) {
        printf("%d", n / k1);
    } else
        printf("%d", (n - a1 * k1) / k2 + a1);
    return 0;
}