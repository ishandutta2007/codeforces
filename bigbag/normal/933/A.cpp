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

const int max_n = 2022, inf = 1000111222;

int n, a[max_n], ones[max_n], two[max_n];
int ans = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ones[i] = (a[i] == 1);
        two[i] = (a[i] == 2);
    }
    for (int i = 2; i <= n; ++i) {
        ones[i] += ones[i - 1];
    }
    for (int i = n - 1; i > 0; --i) {
        two[i] += two[i + 1];
    }
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, ones[i] + two[i + 1]);
    }
    for (int r = 1; r <= n; ++r) {
        int mx1 = 0, mx2 = 0;
        for (int l = r; l >= 1; --l) {
            int nmx1 = mx1, nmx2 = mx2;
            if (a[l] == 1) {
                nmx1 = max(nmx1, mx1 + 1);
            } else {
                nmx2 = max(mx2 + 1, mx1 + 1);
            }
            mx1 = nmx1;
            mx2 = nmx2;
            ans = max(ans, ones[l - 1] + max(mx1, mx2) + two[r + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}