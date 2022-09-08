/**
 *  created: 29/08/2021, 17:48:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, a[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i += 2) {
        long long bal = 0, mn_bal = 0;
        for (int j = i + 1; j < n; j += 2) {
            long long from = max(1LL, max(1LL - bal, -mn_bal));
            long long to = min(a[j] - bal, 1LL * a[i]);
            //cout << i << " " << j << ": " << bal << " " << mn_bal << " " << max(0LL, to - from + 1) << "    " << from << " " << to << endl;
            ans += max(0LL, to - from + 1);
            bal -= a[j];
            mn_bal = min(mn_bal, bal);
            bal += a[j + 1];
        }
    }
    cout << ans << "\n";
    return 0;
}