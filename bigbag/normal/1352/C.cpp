#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long l = 0, r = 1e12;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            if (mid - mid / n >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << "\n";
    }
    return 0;
}