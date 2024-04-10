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

int n, a[max_n];

bool check(int x) {
    a[0] = x;
    int e = 0;
    for (int i = 0; i <= n; ++i) {
        if (e < 0) {
            return 0;
        }
        e += a[i] - a[i + 1];
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = -1, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}