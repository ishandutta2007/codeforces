#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

auto solve() {
    long n;
    cin >> n;
    string s = to_string(n);
    int S = s.size();
    int ans = 9 * (S - 1);
    for (int k = 1; k <= 9; k++) {
        if (stol(string(S, '0' + k)) <= n) {
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}