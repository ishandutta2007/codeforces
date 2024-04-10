#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
        if (N == 1) {
            cout << a[0] << '\n';
            continue;
        }
        auto b = rbegin(a);
        // reduce a[0]
        long moves = 0;
        if (a[0] > a[1]) {
            moves += a[0] - a[1];
            a[0] = a[1];
        }
        if (b[0] > b[1]) {
            moves += b[0] - b[1];
            b[0] = b[1];
        }
        for (int i = 1; i + 1 < N; i++) {
            long large = max(a[i - 1], a[i + 1]);
            if (a[i] > large) {
                moves += a[i] - large;
                a[i] = large;
            }
        }
        moves += a[0] + b[0];
        for (int i = 1; i < N; i++) {
            moves += abs(a[i] - a[i - 1]);
        }
        cout << moves << '\n';
    }
    return 0;
}