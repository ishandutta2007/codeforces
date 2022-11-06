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
int n;
int a[201];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i ++)
            printf("%d%c", a[i], " \n"[i ==n]);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i ++)
            printf("%d%c", a[i], " \n"[i ==n]);
    }
}