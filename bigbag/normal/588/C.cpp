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

const int max_n = 1111111, inf = 1111111111;

int n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++a[x];
    }
    int ans = 0;
    for (int i = 0; i + 1 < max_n; ++i) {
        a[i + 1] += a[i] / 2;
        a[i] %= 2;
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}