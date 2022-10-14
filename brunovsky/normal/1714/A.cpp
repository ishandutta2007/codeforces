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
        int n, H, M;
        cin >> n >> H >> M;
        set<int> times;
        for (int i = 0; i < n; i++) {
            int h, m;
            cin >> h >> m;
            times.insert(60 * h + m);
            times.insert(60 * h + m + 24 * 60);
        }
        int sleep = 60 * H + M;
        int t = *times.lower_bound(sleep) - sleep;
        int A = t / 60;
        int B = t % 60;
        cout << A << ' ' << B << '\n';
    }
    return 0;
}