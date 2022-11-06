#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
int n, m, k;
int a[1000000];
int ansl, ansr;
bool work() {
    int l = 1;
    for (int i = 2; i <= n; i ++) {
        if (a[i] - i >= a[l] - l + 1) {
            ansl = l, ansr = i;
            return 1;
        }
        if (a[i] - i < a[l] - l)
            l = i;
    }
    return 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int mx = 0, mn = 1e9;
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        if (work()) {
            printf("YES\n");
            printf("%d %d\n", ansl, ansr);
            continue;
        }
        reverse(a + 1, a + n + 1);
        if (work()) {
            printf("YES\n");
            printf("%d %d\n", n - ansr +1, n - ansl + 1);
            continue;
        }
        printf("NO\n");
    }
}