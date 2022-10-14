#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    int Ax = accumulate(begin(a), end(a), 0, std::bit_xor<int>{});
    int Bx = accumulate(begin(b), end(b), 0, std::bit_xor<int>{});
    if (Ax != Bx) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i && j) {
                cout << " " << 0;
            } else if (i && !j) {
                cout << a[i];
            } else if (!i && j) {
                cout << ' ' << b[j];
            } else {
                cout << (a[0] ^ b[0] ^ Ax);
            }
        }
        cout << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}