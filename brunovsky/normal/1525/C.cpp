#include <bits/stdc++.h>

using namespace std;

#define long int64_t

#define POPS(x, s)   \
    int x = s.top(); \
    s.pop()

#define POPQ(x, s)     \
    int x = s.front(); \
    s.pop();

// *****

auto solve() {
    int N, m;
    cin >> N >> m;
    vector<int> x(2 * N);
    vector<bool> right(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        x[i + N] = m + x[i];
    }
    for (int i = 0; i < N; i++) {
        string dir;
        cin >> dir;
        right[i] = right[i + N] = dir == "R";
    }
    vector<int> exptime(N, -1);
    vector<int> index(N);
    iota(begin(index), end(index), 0);
    sort(begin(index), end(index), [&](int u, int v) { return x[u] < x[v]; });

    stack<int> even_right, odd_right;
    queue<int> even_left, odd_left;
    for (int robot = 0; robot < N; robot++) {
        int i = index[robot];
        if (-1 == exptime[i]) {
            if (!right[i]) {
                if (x[i] % 2 == 0) {
                    if (even_right.empty()) {
                        even_left.push(i);
                    } else {
                        POPS(l, even_right);
                        int t = (x[i] - x[l]) / 2;
                        exptime[i] = exptime[l] = t;
                    }
                } else if (x[i] % 2 == 1) {
                    if (odd_right.empty()) {
                        odd_left.push(i);
                    } else {
                        POPS(l, odd_right);
                        int t = (x[i] - x[l]) / 2;
                        exptime[i] = exptime[l] = t;
                    }
                }
            } else {
                if (x[i] % 2 == 0) {
                    even_right.push(i);
                } else {
                    odd_right.push(i);
                }
            }
        }
    }
    while (even_right.size() >= 2u) {
        POPS(i, even_right);
        POPS(j, even_right);
        assert(x[i] > x[j]);
        int d = (m - x[i]) + (x[i] - x[j]) / 2;
        exptime[i] = exptime[j] = d;
    }
    while (even_left.size() >= 2u) {
        POPQ(i, even_left);
        POPQ(j, even_left);
        assert(x[i] < x[j]);
        int d = x[i] + (x[j] - x[i]) / 2;
        exptime[i] = exptime[j] = d;
    }
    while (odd_right.size() >= 2u) {
        POPS(i, odd_right);
        POPS(j, odd_right);
        assert(x[i] > x[j]);
        int d = (m - x[i]) + (x[i] - x[j]) / 2;
        exptime[i] = exptime[j] = d;
    }
    while (odd_left.size() >= 2u) {
        POPQ(i, odd_left);
        POPQ(j, odd_left);
        assert(x[i] < x[j]);
        int d = x[i] + (x[j] - x[i]) / 2;
        exptime[i] = exptime[j] = d;
    }
    if (!even_right.empty() && !even_left.empty()) {
        POPS(i, even_right);
        POPQ(j, even_left);
        assert(x[i] > x[j]);
        int d = m + (x[j] - x[i]) / 2;
        exptime[i] = exptime[j] = d;
    }
    if (!odd_right.empty() && !odd_left.empty()) {
        POPS(i, odd_right);
        POPQ(j, odd_left);
        assert(x[i] > x[j]);
        int d = m + (x[j] - x[i]) / 2;
        exptime[i] = exptime[j] = d;
    }

    for (int i = 0; i < N; i++) {
        cout << exptime[i] << " \n"[i + 1 == N];
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}