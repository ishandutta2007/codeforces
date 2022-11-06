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
const int N = 1e2 + 1;
bool bz[N], bz1[N];
int n;
int main() {
    scanf("%d", &n);
    while (n --) {
        int x;
        scanf("%d", &x);
        bz[x] = 1;
    }
    for (int i = 1; i <= 100; i ++)
        if (bz[i])
            for (int j = 2; j *i <= 100; j ++)
                bz1[i * j] = 1;
    int ans = 0;
    for (int i = 1; i <= 100; i++)
        ans += bz[i] && ! bz1[i];
    printf("%d\n", ans);
        return 0;
}