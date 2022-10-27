#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, x;
    cin >> N >> x;
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a < x) {
            cnt[a]++;
        }
    }
    for (auto pos = begin(cnt); pos != end(cnt); ++pos) {
        auto [a, c] = *pos;
        if (c % (a + 1)) {
            cout << "No\n";
            return 0;
        }
        int d = c / (a + 1);
        if (a + 1 < x) {
            cnt[a + 1] += d;
        }
    }
    cout << "Yes\n";
    return 0;
}