#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int k = 2; ; ++k) {
            int sum = (1 << k) - 1;
            if (n % sum == 0) {
                cout << n / sum << "\n";
                break;
            }
        }
    }
    return 0;
}