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
int n;
int f[2];
long long ans1, ans2;
int main() {
    scanf("%d", &n);
    f[0] = 1;
    bool bz = 0;
    while (n --) {
        int x;
        scanf("%d", &x);
        if (x < 0) bz ^= 1;
        ans1 += f[bz];
        ans2 += f[bz ^ 1];
        f[bz] ++;
    }
    printf("%lld %lld\n", ans2, ans1);
    return 0;
}