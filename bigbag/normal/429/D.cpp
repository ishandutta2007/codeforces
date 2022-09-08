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

int n, a[max_n], sum[max_n];

int get_sum(int l, int r) {
    int x = sum[r], y = 0;
    if (l != 0) {
        y = sum[l - 1];
    }
    return x - y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = a[i] + sum[i - 1];
    }
    int res = inf;
    for (int r = 1; r < min(5000, n) && r * r < res; ++r) {
        int q = r * r;
        //if (r % 1000 == 0) cout << r << endl;
        for (int i = 0; i + r < n; ++i) {
            long long s = get_sum(i + 1, i + r);
            if (res > q + s * s) {
                res = q + s * s;
            }
        }
    }
    cout << res << endl;
    return 0;
}