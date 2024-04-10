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

const int max_n = 1111, inf = 30000;

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int min_x = inf * inf, ans1, ans2;
    for (int i = 0; i < inf; ++i) {
        int min1 = inf * inf, max1 = -inf * inf;
        for (int j = 0; j < n; ++j) {
            b[j] = j * i - a[j];
            min1 = min(min1, b[j]);
            max1 = max(max1, b[j]);
        }
        int x = (max1 - min1) / 2;
        if ((max1 - min1) % 2 != 0) {
            ++x;
        }
        int y = min1 + x;
        if (min_x > x) {
            min_x = x;
            ans1 = -y;
            ans2 = i;
        }
    }
    cout << min_x << endl << ans1 << ' ' << ans2 << endl;
    return 0;
}