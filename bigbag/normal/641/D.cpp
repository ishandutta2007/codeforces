#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1111111111;

int n;
long double s1, s2, mn[max_n], mx[max_n], ans[2][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        double q;
        scanf("%lf", &q);
        mx[i] = q;
    }
    for (int i = 0; i < n; ++i) {
        double q;
        scanf("%lf", &q);
        mn[i] = q;
        //printf("%.5f %.5f\n", (double) mn[i], (double) mx[i]);
    }
    for (int i = 0; i < n; ++i) {
        long double A = 1;
        long double B = -mn[i] - mx[i] + s2 - s1;
        long double C = mx[i] - mn[i] * s2 - mx[i] * s2;
        long double D = max((long double) 0, B * B - 4 * A * C);
        //printf("%.5f\n", (double) (D));
        ans[1][i] = (-B - sqrt(D)) / (2 * A);
        /*if (ans[1][i] < 0 || ans[1][i] > 1) {
            ans[1][i] = (-B - sqrt(D)) / (2 * A);
        }*/
        ans[0][i] = mx[i] + mn[i] - ans[1][i];
        s1 += ans[0][i];
        s2 += ans[1][i];
    }
    for (int i = 0; i < n; ++i) {
        printf("%.8f ", (double) ans[0][i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%.8f ", (double) ans[1][i]);
    }
    printf("\n");
    return 0;
}