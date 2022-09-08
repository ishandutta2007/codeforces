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

int n, q, x[max_n];
long long sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    sort(x, x + n);
    sum[0] = x[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + x[i];
    }
    scanf("%d", &q);
    while (q--) {
        int v;
        scanf("%d", &v);
        printf("%d\n", upper_bound(x, x + n, v) - x);
    }
    return 0;
}