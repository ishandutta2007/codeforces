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
        int x = min_element(begin(a), end(a)) - begin(a);
        int y = max_element(begin(a), end(a)) - begin(a);
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
    return 0;
}