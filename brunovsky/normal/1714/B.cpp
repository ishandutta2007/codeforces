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
        set<int> used;
        int len = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (used.insert(a[i]).second) {
                len++;
            } else {
                break;
            }
        }
        cout << N - len << '\n';
    }
    return 0;
}