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
        int ans = 1;
        long long d = n, kn = n;
        for (int i = 2; 1LL * i * i <= n; ++i) {
            int cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            if (ans < cnt) {
                ans = cnt;
                d = i;
            }
        }
        cout << ans << "\n";
        for (int i = 1; i < ans; ++i) {
            cout << d << " ";
            kn /= d;
        }
        cout << kn << "\n";
    }
    return 0;
}