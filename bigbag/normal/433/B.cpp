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

int n, q, tp, l, r;
long long a[2][max_n], sum[2][max_n];

long long get(int f, int l, int r) {
    if (l == 0) {
        return sum[f][r];
    }
    return sum[f][r] - sum[f][l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[0][i]);
        a[1][i] = a[0][i];
    }
    sort(a[1], a[1] + n);
    sum[0][0] = a[0][0];
    sum[1][0] = a[1][0];
    for (int i = 1; i < n; ++i) {
        sum[0][i] = sum[0][i - 1] + a[0][i];
        sum[1][i] = sum[1][i - 1] + a[1][i];
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &tp, &l, &r);
        --l;
        --r;
        printf("%I64d\n", get(tp - 1, l, r));
    }
    return 0;
}