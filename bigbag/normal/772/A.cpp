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

const int max_n = 101111;
const long long inf = 10111111111LL;

int n, p, a[max_n], b[max_n];
long long sum1, sum2;

bool check(long double t) {
    long double sum = 0;
    for (int i = 0; i < n; ++i) {
        long double x = b[i] - t * a[i];
        if (x < 0) {
            x *= -1;
            sum += x / p;
        }
        if (sum > t) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        sum1 += a[i];
        sum2 += b[i];
    }
    if (p >= sum1) {
        printf("-1\n");
        return 0;
    }
    long double l = 0, r = inf;
    for (int i = 0; i < 100; ++i) {
        long double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.10f\n", (double) l);
    return 0;
}