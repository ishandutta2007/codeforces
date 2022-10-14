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
        vector<int> a(N + 1), b(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i] >> b[i];
        }

        int L = 0, R = N + 1;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            // Let's try a party with M people

            int left = 0, right = M - 1;
            for (int i = 1; i <= N && right >= 0; i++) {
                if (a[i] >= right && b[i] >= left) {
                    left++, right--;
                }
            }

            if (right < 0) {
                L = M;
            } else {
                R = M;
            }
        }

        cout << L << '\n';
    }
    return 0;
}