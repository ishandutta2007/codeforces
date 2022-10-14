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
        int N, C;
        cin >> N >> C;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        C = *max_element(begin(a), end(a));
        vector<int> has(C + 1), prefix(C + 1);
        for (int v : a) {
            has[v] = 1;
        }
        for (int c = 1; c <= C; c++) {
            prefix[c] = prefix[c - 1] + has[c];
        }

        bool ok = has[1] == 1;

        for (int y = 2; y <= C && ok; y++) {
            if (has[y]) {
                // x/y >= floor(x/y) = v <=> yv <= x <= C ==> v <= C/y
                for (int v = 2; v <= C / y && ok; v++) {
                    int a = v * y - 1, b = min(C, v * y + y - 1);
                    ok &= has[v] || prefix[a] == prefix[b];
                }
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}