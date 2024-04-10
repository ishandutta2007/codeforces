#include <bits/stdc++.h>
#define all(a) begin(a), end(a)

using namespace std;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int>st_pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') st_pos.push_back(i);
    }
    int cnt = st_pos.size();

    int k = cnt / 2;
    int i = cnt ? st_pos[k] - k : 0;
    auto calc = [&] (int f) { // 10^6 * 10^6
        int64_t ans = 0;
        for (int i = 0; i < cnt; ++i) {
            ans += abs(f + i - st_pos[i]);
        }
        return ans;
    };
    cout << calc(i) << "\n";

    // // i = [l..r]
    // int l = 0, r = n - cnt;
    // while (r - l > 10) {
    //     int m1 = l + (r - l) / 3;
    //     int m2 = r - (r - l) / 3;
    //     if (calc(m1) > calc(m2)) l = m1;
    //     else r = m2;
    // }
    
    // int64_t ans = 1e18;
    // for (int i = l; i <= r; ++i) {
    //     ans = min(ans, calc(i));
    // }
    // cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/**

...R......S.....L......L...L.....
...1......1.....1......1...1.....
.........22222...................
         x

a[0] --> x
a[1] --> x + 1
a[2] --> x + 2

a[i] = x + i

x < a[i] - i | L
x = a[i] - i | S
x > a[i] + i | R

forn(i, n) b[i] = a[i] - i
nth_element(b, b + n / 2, n + n)
cout << b[n/2] << endl;

k = n / 2
cout << a[k] - k << endl;

*/