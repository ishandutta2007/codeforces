#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int k = count(begin(A), end(A), A[0]);
    if (k == 1)
        return 1;

    auto at = find_if(begin(A), end(A), [&A](int u) { return u != A[0]; }) - begin(A);
    return 1 + int(at);
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