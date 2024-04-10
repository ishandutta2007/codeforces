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

const int max_n = 1011, inf = 1011111111;

int n, r, x[max_n];
long double y[max_n];

int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[i] = r;
        for (int j = 0; j < i; ++j) {
            int X = my_abs(x[j] - x[i]);
            if (X <= 2 * r) {
                long double pl = sqrt(4 * r * r - X * X);
                y[i] = max(y[i], y[j] + pl);
            }
        }
        printf("%.10f ", (double) y[i]);
    }
    printf("\n");
    return 0;
}