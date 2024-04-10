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
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        for (int i = 0; i < N; i++) {
            cout << a[i] << " \n"[i + 1 == N];
        }
        for (int i = 0; i < N; i++) {
            cout << b[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}