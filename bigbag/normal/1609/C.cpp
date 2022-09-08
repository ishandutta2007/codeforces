/**
 *  created: 28/11/2021, 16:42:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_x = 1000111;

int t, n, e, a[max_n], is_prime[max_x];
int nxt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(is_prime, is_prime + max_x, 1);
    is_prime[1] = 0;
    for (int i = 2; i < max_x; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < max_x; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> e;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            nxt[i] = i;
            if (a[i] == 1) {
                if (i + e < n) {
                    nxt[i] = nxt[i + e];
                } else {
                    nxt[i] = i + e;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nxt[i] >= n) {
                continue;
            }
            int pos = nxt[i];
            if (is_prime[a[pos]]) {
                int to = pos + e;
                if (pos + e < n && a[pos + e] == 1) {
                    to = nxt[pos + e];
                }
                ans += (to - pos) / e - 1;
                if (pos != i) {
                    ++ans;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}