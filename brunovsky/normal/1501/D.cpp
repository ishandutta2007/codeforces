#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    if (N > M) {
        swap(N, M);
        swap(A, B);
    }
    int X = max(*max_element(begin(A), end(A)), *max_element(begin(B), end(B)));
    int cycles = gcd(N, M);
    int len = M / cycles;
    long long period = 1LL * N * len;
    vector<pair<int, int>> pos_index_B(M);     // <cycle, offset>
    vector<pair<int, int>> pos_value_B(X + 1); // <cycle, offset>

    for (int c = 1; c <= cycles; c++) {
        int s = c - 1, i = s, n = 0;
        do {
            pos_index_B[i] = {c, n};
            pos_value_B[B[i]] = {c, n};
            i = (i + N) % M, n++;
        } while (i != s);
        assert(n == len);
    }

    vector<pair<int, int>> pos_index_A(X + 1); // <cycle, offset>

    for (int i = 0; i < N; i++) {
        pos_index_A[i] = pos_index_B[i];
    }

    long long L = 1, R = 2LL * (N + M) * K;
    while (L <= R) {
        long long days = L + (R - L) / 2;
        long long ok_days = 0;
        long long full_walks = days / period; // cycle iterations
        long long remaining = days % period;
        long long full_steps = remaining / N;
        long long extra_steps = remaining % N;

        for (int i = 0; i < N; i++) {
            auto [acycle, aoff] = pos_index_A[i];
            auto [bcycle, boff] = pos_value_B[A[i]];
            if (acycle == bcycle) {
                long long got = 0;
                got += full_walks;
                int one_more = i < extra_steps;
                if (aoff <= boff) {
                    got += aoff + full_steps + one_more > boff;
                } else {
                    got += aoff + full_steps + one_more > boff + len;
                }
                ok_days += got;
            }
        }

        long long angry = days - ok_days;
        if (angry < K) {
            L = days + 1;
        } else {
            R = days - 1;
        }
    }
    return L;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}