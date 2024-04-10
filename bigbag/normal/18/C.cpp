#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1111111111;

int n, sum[max_n];

int get_sum(int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (get_sum(1, i) == get_sum(i + 1, n)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}