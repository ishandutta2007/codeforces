#include <bits/stdc++.h>

using namespace std;

int t;
long long x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x;
        long long cur = 2, ans = 0;
        while (true) {
            long long need = (cur - 1) * (cur / 2);
            if (x < need) {
                break;
            }
            x -= need;
            cur *= 2;
            ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}