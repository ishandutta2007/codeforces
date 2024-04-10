#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int one = count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
        if (1LL * one * k % n != 0) {
            cout << "-1\n";
        } else {
            one = 1LL * one * k / n;
            vector<int> suf(2 * n + 1);
            for (int i = 1; i <= 2 * n; i++) {
                suf[i] = suf[i - 1] + (s[(i - 1) % n] == '1');
                if (i >= k && suf[i] == suf[i - k] + one) {
                    if (i <= n) {
                        cout << "1\n";
                        cout << i - k + 1 << " " << i << '\n';
                    } else {
                        cout << "2\n";
                        cout << 1 << " " << i - n << '\n';
                        cout << i - k + 1 << " " << n << '\n';
                    }
                    break;
                }
            }
        }
    }
}