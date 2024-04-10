#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto QUERY(int l, int r) {
    cout << "? " << l + 1 << " " << r << endl;
    vector<int> ans(r - l);
    for (int i = 0; i < r - l; i++) {
        cin >> ans[i];
        if (ans[i] == -1) {
            exit(0);
        }
        ans[i]--;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int L = 0, R = N;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            auto a = QUERY(L, M);
            int S = M - L;
            int O = 0;
            for (int i = 0; i < S; i++) {
                O += L <= a[i] && a[i] < M;
            }
            if (O % 2 == 1) {
                R = M;
            } else {
                L = M;
            }
        }
        cout << "! " << R << endl;
    }
    return 0;
}