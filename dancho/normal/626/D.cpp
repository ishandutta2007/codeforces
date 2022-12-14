#include <cstdio>
#include <cstring>

int n;
int a[2048];
long long di[5020];
long long ps[5020];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    memset(di, 0, sizeof(di));
    memset(ps, 0, sizeof(ps));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = a[i] - a[j];
            if (k < 0) {
                k = -k;
            }
            ++di[k];
        }
    }
    ps[0] = 0;
    for (int i = 1; i <= 5000; ++i) {
        ps[i] = ps[i - 1] + di[i];
    }
    __float128 total;
    total = n;
    total = total * (total - 1) * total * (total - 1) * total * (total - 1);

    __float128 ok = 0;
    for (int i = 1; i <= 5000; ++i) {
        for (int j = 1; j < i; ++j) {
            // need k 
            //
            ok = ok + di[i] * di[j] * ps[i - j - 1];
        }
    }
    __float128 ans = ok / total * 8;
    printf("%.10lf\n", (double) ans);
    return 0;
}