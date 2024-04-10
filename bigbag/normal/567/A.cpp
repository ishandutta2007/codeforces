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

const int max_n = 111111, inf = 2011111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        int mn = inf, mx = -inf;
        if (i) {
            mn = min(mn, a[i] - a[i - 1]);
            mx = max(mx, a[i] - a[i - 1]);
            mn = min(mn, a[i] - a[0]);
            mx = max(mx, a[i] - a[0]);
        }
        if (i + 1 < n) {
            mn = min(mn, a[i + 1] - a[i]);
            mx = max(mx, a[i + 1] - a[i]);
            mn = min(mn, a[n - 1] - a[i]);
            mx = max(mx, a[n - 1] - a[i]);
        }
        printf("%d %d\n", mn, mx);
    }
    return 0;
}