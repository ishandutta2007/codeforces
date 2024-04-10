#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

#define flip(x) ((x) ^ MASK)

auto solve() {
    int N, K;
    cin >> N >> K;
    int MASK = (1 << K) - 1;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int cur = 0;

    for (int i = 0; i < N; i++) {
        int a = cur ^ A[i], b = cur ^ flip(A[i]);
        if (cnt[a] <= cnt[b]) {
            cur = a;
            cnt[a]++;
        } else {
            cur = b;
            cnt[b]++;
        }
    }

    long ans = 1LL * N * (N + 1) / 2;
    for (auto [v, c] : cnt) {
        ans -= 1LL * c * (c - 1) / 2;
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}