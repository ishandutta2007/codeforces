#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> cong(M, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cong[A[i] % M]++;
    }
    int ans = 0;
    for (int k = 1; k < (M + 1) / 2; k++) {
        auto [a, b] = minmax(cong[k], cong[M - k]);
        ans += b > 0 ? max(1, b - a) : 0;
    }
    ans += cong[0] > 0;
    ans += (M % 2 == 0) && cong[M / 2] > 0;
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