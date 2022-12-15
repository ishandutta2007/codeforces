#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b, x, y, n, ans = LLONG_MAX;
        cin >> a >> b >> x >> y >> n;
        if (a - x <= n) {
            ans = min(ans, x * max(b - (n - a + x), y));
        }
        else ans = min(ans, (a - n) * b);
        if (b - y <= n) {
            ans = min(ans, y * max(a - (n - b + y), x));
        }
        else ans = min(ans, a * (b - n));
        cout << ans << endl;
    }
    return 0;
}