#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto factors(long n) {
    vector<long> primes;
    for (long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            primes.push_back(p);
            do {
                n = n / p;
            } while (n % p == 0);
        }
    }
    if (n > 1) {
        primes.push_back(n);
    }
    return primes;
}

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<long> B(N + 1), C(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i + 1] = B[i] + A[i];
        C[i + 1] = C[i] + 1LL * i * A[i];
    }
    if (B[N] == 1) {
        return long(-1);
    }
    auto Bsum = [&](int l, int r) { return B[r + 1] - B[l]; };
    auto Csum = [&](int l, int r) { return C[r + 1] - C[l]; };
    auto Lsum = [&](int l, int c) { return c * Bsum(l, c - 1) - Csum(l, c - 1); };
    auto Rsum = [&](int c, int r) { return Csum(c + 1, r) - c * Bsum(c + 1, r); };

    long ans = LLONG_MAX;
    for (long div : factors(B[N])) {
        // Make piles of size div
        int l = 0;
        long pieces = A[0];
        long moves = 0;
        long missing_l = 0;
        while (l + 1 < N) {
            int r = l;
            while (r + 1 < N && pieces < div) {
                pieces += A[r + 1], r++;
            }
            assert(l <= r && r < N);
            // we have div pieces in [l,r], some missing in l, some extra in A[r]
            // need to move all pieces to somewhere in [l,r].
            if (l != r) {
                long extra_r = pieces - div;
                int L = l, R = r;
                while (L < R) {
                    int M1 = (2 * L + R) / 3;
                    int M2 = (L + 2 * R + 2) / 3;
                    assert(M1 != M2);
                    long delta1 = 1LL * (M1 - l) * missing_l + 1LL * (r - M1) * extra_r;
                    long cost1 = Lsum(l, M1) + Rsum(M1, r) - delta1;
                    long delta2 = 1LL * (M2 - l) * missing_l + 1LL * (r - M2) * extra_r;
                    long cost2 = Lsum(l, M2) + Rsum(M2, r) - delta2;
                    assert(cost1 >= 0 && cost2 >= 0);
                    if (cost1 > cost2) {
                        L = M1 + 1;
                    } else {
                        R = M2 - 1;
                    }
                }
                assert(L == R);
                long delta = 1LL * (L - l) * missing_l + 1LL * (r - L) * extra_r;
                long cost = Lsum(l, L) + Rsum(L, r) - delta;
                assert(cost >= 0);
                pieces -= div;
                moves += cost;
            }
            l = r;
            pieces %= div;
            missing_l = A[l] - pieces;
        }
        ans = min(ans, moves);
    }
    return ans;
}

// *****

int main() {
    setbuf(stdout, nullptr);
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}