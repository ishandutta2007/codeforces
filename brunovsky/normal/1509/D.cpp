#include <bits/stdc++.h>

using namespace std;

// *****

auto make(const string& A, const string& B, int N, char c) {
    string S;
    int i = 0, j = 0;
    while (i < 2 * N && j < 2 * N) {
        if (A[i] == c && B[j] == c)
            S += c, i++, j++;
        else if (A[i] != c)
            S += A[i++];
        else
            S += B[j++];
    }
    while (i < 2 * N)
        S += A[i++];
    while (j < 2 * N)
        S += B[j++];

    assert(S.size() <= 3u * N);
    return S;
}

auto solve() {
    int N;
    string S[3];
    cin >> N >> S[0] >> S[1] >> S[2];
    int C[3][2] = {};

    for (int i : {0, 1, 2}) {
        for (int c : {0, 1}) {
            C[i][c] = count(begin(S[i]), end(S[i]), '0' + c);
        }
    }

    for (int i : {0, 1, 2}) {
        for (int j : {0, 1, 2}) {
            for (int c : {0, 1}) {
                if (i < j && C[i][c] >= N && C[j][c] >= N) {
                    return make(S[i], S[j], N, '0' + c);
                }
            }
        }
    }

    return "WHAT"s;
}

// *****

int main() {
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        auto solution = solve();
        cout << solution << endl;
    }
    return 0;
}