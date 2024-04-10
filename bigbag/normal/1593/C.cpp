/**
 *  created: 13/10/2021, 17:41:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 400111, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        sort(a, a + k);
        int ans = 0;
        int sum = 0;
        for (int i = k - 1; i >= 0; --i) {
            sum += n - a[i];
            if (n - 1 < sum) {
                break;
            }
            ans = k - i;
        }
        cout << ans << "\n";
    }

    return 0;
}