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

int n, a[max_n], b[max_n], x[max_n], y[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        ++x[a[i]];
        ++y[b[i]];
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", n - 1 + x[b[i]], n - 1 - x[b[i]]);
    }
    return 0;
}