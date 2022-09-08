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

const int max_n = 111111, inf = 1011111111;

int n, x, y, a[max_n];
long long s1, s2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
    if (x > y) {
        swap(x, y);
    }
    for (int i = 0; i < x + y; ++i) {
        if (i < x) {
            s1 += a[i];
        } else {
            s2 += a[i];
        }
    }
    long double q1 = s1;
    long double q2 = s2;

    printf("%.10f\n", (double) (q1 / x + q2 / y));
    return 0;
}