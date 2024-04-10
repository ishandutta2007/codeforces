#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        if (N % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        vector<int> b(N + 2);
        for (int i = 0; i < N / 2; i++) {
            b[2 * i] = a[i];
        }
        for (int i = 0; i < N / 2; i++) {
            b[2 * i + 1] = a[i + N / 2];
        }
        b[N] = b[0], b[N + 1] = b[1];
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            ok &= (b[i - 1] < b[i] && b[i] > b[i + 1]) ||
                  (b[i - 1] > b[i] && b[i] < b[i + 1]);
        }
        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                cout << b[i] << " \n"[i + 1 == N];
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}