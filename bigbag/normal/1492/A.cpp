/**
 *  created: 23/02/2021, 11:05:36
**/

#include <bits/stdc++.h>

using namespace std;

int t;
long long p, a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> p >> a >> b >> c;
        long long ans = min({(a - p % a) % a, (b - p % b) % b, (c - p % c) % c});
        cout << ans << "\n";
    }
    return 0;
}