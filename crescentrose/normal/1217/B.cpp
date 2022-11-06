#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int t, ans;
int y[100000], z[100000];
int main() {
    scanf("%d", &t);
    while (t --) {
        int n, x;
        scanf("%d %d", &n, &x);
        ans = -1;
        int Y = 0;
        for (int i = 1; i <= n ; i++)
            scanf("%d %d", &y[i], &z[i]), Y = max(Y, y[i]);
        if (Y >= x) {
            printf("1\n");
            continue;
        }
        for (int i = 1;  i<= n ; i++){
            if (y[i] <= z[i]) continue;
            long long s = 0;
            for (long long j = 1ll << 32; j; j >>= 1) {
                do {
                    long long s1 = j + s;
                    if ((s1 - 1) * (y[i] - z[i]) + Y < x) {
                        s = s1;
                    } else
                        break;
                }while (1);
            }
            s ++;
            if (ans == -1 || ans > s)
                ans = s;
        }
        printf("%d\n", ans);
    }
    return 0;
}