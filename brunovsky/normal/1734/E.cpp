#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int mod(int m, int n) { return ((m % n) + n) % n; }

void solve() {
    int N;
    cin >> N;
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vector<vector<int>> a(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mod(i * j + b[i] - i * i, N) << " \n"[j + 1 == N];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}