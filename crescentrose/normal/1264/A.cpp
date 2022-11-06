#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e6;
int a[N], sum[N];
int n, t;
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n ; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1, [] (int x, int y) {return x > y;});
        int tot = 1;
        sum[1] = 1;
        for (int i = 2; i <= n; i ++)
            if (a[i] != a[tot])
                a[++tot] = a[i], sum[tot] = 1;
            else
                sum[tot] ++;
        int all = sum[1];
        int g = 0, s = 0, b = 0;
        int r = 1, ss = 0;
        for (int i = 1; i <= tot && all + all <= n ; i ++, all += sum[i]) {
            while (r + 1 <= i && ss <= sum[1]) {
                ++r;
                ss += sum[r];
            }
            if (ss > sum[1] && all - ss - sum[1] > sum[1]) {
                g = sum[1], s = ss, b = all - ss - sum[1];
            }
        }
        printf("%d %d %d\n", g, s, b);
    }
    return 0;
}