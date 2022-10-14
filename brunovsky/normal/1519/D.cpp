#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

#define MAXN 5001

int A[MAXN], B[MAXN];

auto solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    long total = 0;
    for (int i = 0; i < N; i++) {
        total += 1LL * A[i] * B[i];
    }
    long best = total;
    // pivot around A[i]
    for (int i = 0; i < N; i++) {
        long sum = 1LL * A[i] * B[i], rev = sum;
        for (int l = i - 1, r = i + 1; l >= 0 && r < N; l--, r++) {
            sum += 1LL * A[l] * B[l] + 1LL * A[r] * B[r];
            rev += 1LL * A[r] * B[l] + 1LL * A[l] * B[r];
            best = max(best, total + rev - sum);
        }
    }
    // pivot around middle of A[i,i+1]
    for (int i = 0; i + 1 < N; i++) {
        long sum = 0, rev = 0;
        for (int l = i, r = i + 1; l >= 0 && r < N; l--, r++) {
            sum += 1LL * A[l] * B[l] + 1LL * A[r] * B[r];
            rev += 1LL * A[r] * B[l] + 1LL * A[l] * B[r];
            best = max(best, total + rev - sum);
        }
    }
    return best;
}

// *****

int main() {
    cout << solve() << endl;
    return 0;
}