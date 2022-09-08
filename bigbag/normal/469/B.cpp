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

const int max_n = 2222, inf = 1111111111;

int n, m, a, b, f[max_n], sum[max_n], l[max_n], r[max_n];

int get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b;
    while (n--) {
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; ++i) {
            f[i] = 1;
        }
    }
    sum[0] = f[0];
    for (int i = 1; i < max_n; ++i) {
        sum[i] = sum[i - 1] + f[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
    }
    int ans = 0;
    for (int t = a; t <= b; ++t) {
        for (int i = 0; i < m; ++i) {
            if (get_sum(l[i] + t, r[i] + t)) {
                ++ans;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}