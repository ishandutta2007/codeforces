#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int t, n;

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n;
        int tmp = 1, val = n, ans = 0;
        for (int i = 2; i <= 41; ++ i) {
            int now = val - val / (i / __gcd(tmp, i));
            val -= now;
            ans += now * i % mod;
            tmp *= (i / __gcd(tmp, i));
        }
        cout << ans % mod << "\n";
    }
    return 0;
}