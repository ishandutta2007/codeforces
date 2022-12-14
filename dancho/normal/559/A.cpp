#include <cstdio>
#include <cstring>
#include <cmath>

const double eps = 1e-7;
double a[8];

int main() {
    for (int i = 0; i < 6; ++i) {
        scanf("%lf", &a[i]);
    }

    double rar = (a[0] * .5 + a[1] + a[2] * .5) * sqrt(3) * 0.5 * (a[0] + a[5]);
    for (int i = 0; i < 6; ++i) {
        if (i != 1 && i != 4) {
            rar -= (a[i] * a[i]) / 8 * sqrt(3);
        }
    }
    double ans = rar / sqrt(3) * 4;
    printf("%d\n", (int) (ans + eps));
    
    return 0;
}