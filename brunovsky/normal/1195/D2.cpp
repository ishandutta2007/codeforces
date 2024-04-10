#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

constexpr long mod = 998244353;
long pow10[30];

auto solve() {
    pow10[0] = 1;
    for (int i = 1; i < 30; i++) {
        pow10[i] = 10 * pow10[i - 1] % mod;
    }
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> bylen(11, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        bylen[to_string(A[i]).size()]++;
    }
    long ans = 0;
    for (int i = 0; i < N; i++) {
        string s = to_string(A[i]);
        reverse(begin(s), end(s));
        for (int j = 0, S = s.size(); j < S; j++) {
            int n = s[j] - '0';
            // A[i] on the left
            for (int d = 1; d <= 10; d++) {
                int k = bylen[d];
                if (j < d) {
                    ans = (ans + 1LL * k * n * pow10[2 * j + 1]) % mod;
                } else {
                    ans = (ans + 1LL * k * n * pow10[2 * d + (j - d)]) % mod;
                }
            }
            // A[i] on the right
            for (int d = 1; d <= 10; d++) {
                int k = bylen[d];
                if (j <= d) {
                    ans = (ans + 1LL * k * n * pow10[2 * j]) % mod;
                } else {
                    ans = (ans + 1LL * k * n * pow10[2 * d + (j - d)]) % mod;
                }
            }
        }
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}