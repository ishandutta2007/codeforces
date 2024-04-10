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

const int max_n = 333333, inf = 1011111111;

int n, x, y, a[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y);
        ans += a[x ^ y];
        ++a[y];
    }
    printf("%I64d\n", ans);
    return 0;
}