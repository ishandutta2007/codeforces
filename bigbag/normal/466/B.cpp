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

const long long inf = 1111111111111111LL;

long long n, a, b, ans = inf, ans1, ans2, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    n *= 6;
    for (x = a; x * x <= n; ++x) {
        y = n / x;
        if (n % x) ++y;
        if (y < b) y = b;
        if (x * y < ans) {
            ans = x * y;
            ans1 = x;
            ans2 = y;
        }
    }
    for (y = b; y * y <= n; ++y) {
        x = n / y;
        if (n % y) ++x;
        if (x < a) x = a;
        if (x * y < ans) {
            ans = x * y;
            ans1 = x;
            ans2 = y;
        }
    }
    if (a * b >= n) {
        ans = a * b;
        ans1 = a;
        ans2 = b;
    }
    cout << ans << endl << ans1 << " " << ans2 << endl;
    return 0;
}