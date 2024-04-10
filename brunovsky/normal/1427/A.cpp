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
        int A = accumulate(begin(a), end(a), 0);
        if (A == 0) {
            cout << "NO\n";
        } else if (A > 0) {
            sort(rbegin(a), rend(a));
            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                cout << a[i] << " \n"[i + 1 == N];
            }
        } else {
            sort(begin(a), end(a));
            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                cout << a[i] << " \n"[i + 1 == N];
            }
        }
    }
    return 0;
}