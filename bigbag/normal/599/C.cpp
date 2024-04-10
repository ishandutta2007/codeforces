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

int n, ans, a[max_n], mn[max_n], mx[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    mx[0] = a[0];
    for (int i = 1; i < n; ++i) {
        mx[i] = max(mx[i - 1], a[i]);
    }
    mn[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        mn[i] = min(mn[i + 1], a[i]);
    }
    for (int i = 0; i < n; ++i) {
        ++ans;
        while (true) {
            if (i + 1 == n || mx[i] <= mn[i + 1]) {
                break;
            }
            ++i;
        }
    }
    printf("%d\n", ans);
    return 0;
}