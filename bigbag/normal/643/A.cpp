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

const int max_n = 5055, inf = 1111111111;

int n, a[max_n], f[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        memset(f, 0, sizeof(f));
        pair<int, int> res = make_pair(-1, -1);
        for (int j = i; j < n; ++j) {
            ++f[a[j]];
            res = max(res, make_pair(f[a[j]], -a[j]));
            ++ans[-res.second];
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}