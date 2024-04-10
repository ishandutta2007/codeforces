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

int n, m, l[max_n], r[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int ans = inf;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        ans = min(ans, r[i] - l[i] + 1);
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        printf("%d ", i % ans);
    }
    printf("\n");
    return 0;
}