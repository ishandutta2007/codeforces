#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    vector<long> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<long> D(N); // D[i] = A[i + 1] - A[i]
    long P = 0, Q = 0;

    //    bn = b1 + P   and  c1 = cn + Q
    //        bn = c1   or   bn = c1+1
    // 2c1 = A[n] + Q   or   2c1 = A[n] + Q - 1   (resp)
    auto putans = [&]() {
        long b1, bn, c1;
        if (A[1] % 2 != P % 2) {
            b1 = (A[1] - P - 1) / 2;
            bn = b1 + P;
            c1 = A[1] - b1;
        } else {
            b1 = (A[1] - P) / 2;
            bn = b1 + P;
            c1 = A[1] - b1;
        }
        cout << max(bn, c1) << endl;
    };

    auto add = [&](int i) {
        if (D[i] > 0) {
            P += D[i];
        } else {
            Q += -D[i];
        }
    };

    auto rem = [&](int i) {
        if (D[i] > 0) {
            P -= D[i];
        } else {
            Q -= -D[i];
        }
    };

    for (int i = 1; i < N; i++) {
        D[i] = A[i + 1] - A[i];
        add(i);
    }

    putans();

    int queries;
    cin >> queries;
    for (int q = 0; q < queries; q++) {
        int l, r, x;
        cin >> l >> r >> x, l--;
        if (l >= 1) {
            rem(l);
            D[l] += x;
            add(l);
        } else {
            A[1] += x;
        }
        if (r < N) {
            rem(r);
            D[r] -= x;
            add(r);
        } else if (N != 1) {
            A[N] += x;
        }
        putans();
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}