#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;
int n, m;
int a[1000000];
int sum[1001], num[1001];
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = z * x % m;
        x = x * x % m, y >>= 1;
    }
    return z;
}
int main() {
    scanf("%d %d", &n, &m);
    int ans = 1;
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) {
        a[i] %= m;
        if (sum[a[i]]) {
            printf("0\n");
            return 0;
        }
        for (int j = 0; j < a[i]; j ++)
            num[a[i] - j] += sum[j];
        for (int j = a[i] + 1; j < m ;j ++)
            num[a[i] - j + m] += sum[j];
        sum[a[i]] ++;
    }
    for (int i = 0; i < m; i ++)
        ans = 1ll * ans* calc(i, num[i]) %m;
    printf("%d\n", ans);
    return 0;
}