/**
 *  created: 23/04/2021, 17:35:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
long long n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long x = 2050;
        while (x * 10 <= n) {
            x *= 10;
        }
        int ans = 0;
        while (x >= 2050) {
            while (n >= x) {
                n -= x;
                ++ans;
            }
            x /= 10;
        }
        if (n) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}