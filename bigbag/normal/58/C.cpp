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

const int max_n = 111111, inf = 111111111;

int n, a[max_n], b[max_n], c[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int min1 = inf;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        min1 = min(min1, a[i]);
    }
    for (int i = 1; i <= n / 2; ++i) {
        b[i] = i;
        b[n - i + 1] = i;
    }
    if (n % 2 == 1) {
        b[n / 2 + 1] = n / 2 + 1;
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = b[i] - a[i];
    }
    //cout << endl;
    sort(c + 1, c + n + 1);
    int ans = inf;
    for (int i = 1; i <= n; ++i) {
        int cnt = 1;
        while (i < n && c[i] == c[i + 1]) {
            ++i;
            ++cnt;
        }
        if (min1 - c[i] > 0) {
            ans = min(ans, n - cnt);
        }
    }
    cout << ans << endl;
    /*int l = 0, r = max_n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }*/
    return 0;
}