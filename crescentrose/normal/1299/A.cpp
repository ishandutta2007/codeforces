#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int sum[32];
int a[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i= 1; i <= n; i ++){
        scanf("%d", &a[i]);
        for (int j = 0; j < 31; j ++)
            sum[j] += ((a[i] >> j) & 1);
    }
    int v = 0, id = 1;
    for (int i = 1; i <= n; i ++) {
        int vv = 0;
        for (int j = 0; j < 31; j++)
            if (((a[i] >> j) & 1) && sum[j] == 1)
                vv += 1 << j;
        if (vv > v) v = vv, id = i;
    }
    printf("%d", a[id]);
    for (int i = 1; i <= n; i ++)
        if (i != id)
            printf(" %d", a[i]);
    return 0;
}