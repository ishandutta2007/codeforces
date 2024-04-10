#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int n, p, l, r;
    cin >> n >> p >> l >> r;

    int ans = 0;
    if (p < l) {
        ans = l - p;
        p = l;
    }
    if (p > r) {
        ans = p - r;
        p = r;
    }
    if (l == 1 && r == n) {
        cout << ans + 0 << endl;
    } else 
    if (l == 1) {
        cout << ans + r - p + 1 << endl;
    } else
    if (r == n) {
        cout << ans + p - l + 1 << endl;
    } else {
        ans += 2;
        ans = ans + min(p - l, r - p) + r - l;
        cout << ans << endl;
    }
    return 0;
}