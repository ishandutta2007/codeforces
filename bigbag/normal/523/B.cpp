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

const int max_n = 222222, inf = 1111111111;

int n, a[max_n], m;
long long sum[max_n];
double c, t, mean, real, b[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> t >> c;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i];
        if (i > 0) {
            sum[i] += sum[i - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        mean = (mean + 1.0 * a[i] / t) / c;
        b[i] = mean;
    }
    scanf("%d", &m);
    while (m--) {
        int p;
        scanf("%d", &p);
        --p;
        real = get_sum(p - t + 1, p) / t;
        printf("%.10f %.10f %.10f\n", real, b[p], fabs(real - b[p]) / real);
    }
    return 0;
}