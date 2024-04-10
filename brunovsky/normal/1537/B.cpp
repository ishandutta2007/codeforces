#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

long dist(array<long, 2> a, array<long, 2> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        array<long, 2> S;
        cin >> N >> M >> S[0] >> S[1];
        vector<array<long, 2>> corners = {{1, 1}, {N, 1}, {1, M}, {N, M}};
        array<long, 2> best = {0, 0};
        long best_dist = 0;
        for (int a = 0; a < 4; a++) {
            for (int b = a + 1; b < 4; b++) {
                auto A = corners[a], B = corners[b];
                long x = dist(S, A) + dist(A, B) + dist(B, S);
                if (x > best_dist) {
                    best = {a, b};
                    best_dist = x;
                }
            }
        }
        auto A = corners[best[0]], B = corners[best[1]];
        cout << A[0] << ' ' << A[1] << ' ' << B[0] << ' ' << B[1] << '\n';
    }
    return 0;
}