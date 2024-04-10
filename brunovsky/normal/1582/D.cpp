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

        vector<int> b(N);

        if (N & 1) {
            // make first three sum to 0. We have a leeway of 1 extra element
            if (a[0] != a[1] && a[1] != a[2] && a[2] != a[0]) {
                b[0] = a[1] - a[2];
                b[1] = a[2] - a[0];
                b[2] = a[0] - a[1];
            } else if (a[0] == a[1]) {
                b[0] = b[1] = -a[2];
                b[2] = 2 * a[0];
            } else if (a[1] == a[2]) {
                b[1] = b[2] = -a[0];
                b[0] = 2 * a[1];
            } else {
                b[2] = b[0] = -a[1];
                b[1] = 2 * a[2];
            }
            for (int i = 3; i < N; i += 2) {
                b[i] = a[i + 1];
                b[i + 1] = -a[i];
            }
        } else {
            for (int i = 0; i < N; i += 2) {
                b[i] = a[i + 1];
                b[i + 1] = -a[i];
            }
        }

        for (int i = 0; i < N; i++) {
            cout << b[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}