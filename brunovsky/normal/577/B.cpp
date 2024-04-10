#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<bool> seen(M, false);
    for (int i = 0; i < N; i++) {
        int c = A[i] % M;
        vector<bool> nxt(M, false);
        for (int j = 0; j < M; j++) {
            nxt[(j + c) % M] = seen[(j + c) % M] | seen[j];
        }
        seen = move(nxt);
        seen[c] = true;
        if (seen[0]) {
            return "YES"s;
        }
    }
    return "NO"s;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}