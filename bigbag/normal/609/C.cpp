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

long long n, ans, sum, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    long long ans = 0;
    if (sum % n == 0) {
        long long x = sum / n;
        for (long long i = 0; i < n; ++i) {
            if (a[i] < x) {
                ans += x - a[i];
            }
        }
    } else {
        long long x = sum / n;
        long long cnt = n - sum % n;
        for (long long i = 0; i < n; ++i) {
            if (a[i] < x) {
                ans += x - a[i];
                a[i] = x;
            }
        }
        for (long long i = 0; i < n; ++i) {
            if (a[i] == x) {
                --cnt;
            }
        }
        if (cnt < 0) ans -= cnt;
    }
    cout << ans << endl;
    return 0;
}