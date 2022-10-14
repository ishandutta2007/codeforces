#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    unordered_map<int, int> valcnt;
    for (int i = 0; i < N; i++) {
        valcnt[A[i] - i]++;
    }
    long ans = 0;
    for (auto [n, cnt] : valcnt) {
        ans += 1LL * cnt * (cnt - 1) / 2;
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