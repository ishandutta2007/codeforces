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

int n, days, a[max_n], b[max_n];

int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &days, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    int ans = b[0] + a[0] - 1;
    for (int i = 0; i + 1 < n; ++i) {
        int x = a[i + 1] - a[i];
        int r = b[i + 1] - b[i];
        if (my_abs(r) > x) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        int mn = (b[i] - b[i + 1] + x) / 2;
        int pl = x - mn;
        if (b[i] + pl - mn > b[i + 1]) {
            --pl;
        }
        ans = max(ans, b[i] + pl);
        //cout << i << " - " << pl << " " << mn << endl;
    }
    ans = max(ans, b[n - 1] + days - a[n - 1]);
    cout << ans << endl;
    return 0;
}