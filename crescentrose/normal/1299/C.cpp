#include <cstdio>
#include <algorithm>
using namespace std;
long long a[1000011];
int d[1000011];
int n;
long double calc(int x, int y) {
    return (long double) (a[y] - a[max(x - 1,0)]) / (y - x + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]), a[i] += a[i - 1];
    d[0] = 2;
    d[1] = -1;
    d[2] = 0;
    for (int i = 1;i <= n; i ++) {
        d[++d[0]] = i;
        while (d[0] > 2 && calc(d[d[0] - 2] + 1, d[d[0] - 1]) > calc(d[d[0] - 2]+ 1, d[d[0]]))
            d[d[0] - 1] = d[d[0]], d[0] --;
    }
    for (int i = 3; i <= d[0]; i ++)
        for (int j = d[i - 1] + 1; j <= d[i]; j ++)
        printf("%.10f\n", (double)calc(d[i - 1] + 1, d[i]));
    return 0;
}