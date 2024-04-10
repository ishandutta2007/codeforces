#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 555, inf = 1111111111;

int n, m, x[max_n];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
    }
    double ans = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        double q = x[a] + x[b];
        q /= c;
        ans = max(ans, q);
    }
    printf("%.15lf\n", ans);
    return 0;
}