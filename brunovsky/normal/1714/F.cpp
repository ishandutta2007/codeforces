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
        int N, A, B, C;
        cin >> N >> A >> B >> C;
        assert(A > 0 && B > 0 && C > 0);
        int sum = A + B + C;
        if (sum % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        int F = sum / 2 - B;
        int G = sum / 2 - C;
        int H = sum / 2 - A;
        if (F < 0 || G < 0 || H < 0 || F + G + H > N - 1 || 2 * max({A, B, C}) > sum) {
            cout << "NO\n";
            continue;
        }
        int root = F == 0 ? 1 : G == 0 ? 2 : H == 0 ? 3 : 4;
        int v = root == 4 ? 5 : 4;
        vector<array<int, 2>> edges;
        for (int i = 1, p = root; i <= F; i++) {
            int n = i == F ? 1 : v++;
            edges.push_back({p, n}), p = n;
        }
        for (int i = 1, p = root; i <= G; i++) {
            int n = i == G ? 2 : v++;
            edges.push_back({p, n}), p = n;
        }
        for (int i = 1, p = root; i <= H; i++) {
            int n = i == H ? 3 : v++;
            edges.push_back({p, n}), p = n;
        }
        while (v <= N) {
            edges.push_back({root, v++});
        }
        cout << "YES\n";
        for (auto [u, v] : edges) {
            cout << u << ' ' << v << '\n';
        }
    }
    return 0;
}

//    H
// F ... G
// F + G = A
// G + H = B
// H + F = C
// F = (A + C - B)/2
// G = (B + A - C)/2
// H = (C + B - A)/2