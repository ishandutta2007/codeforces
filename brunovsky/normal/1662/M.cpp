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
        int N, M;
        cin >> N >> M;
        int red = 0, white = 0;
        for (int i = 0; i < M; i++) {
            int r, w;
            cin >> r >> w;
            red = max(red, r);
            white = max(white, w);
        }
        if (red + white > N) {
            cout << "IMPOSSIBLE\n";
        } else {
            white = N - red;
            string bottle(N, 'W');
            fill(begin(bottle), begin(bottle) + red, 'R');
            cout << bottle << '\n';
        }
    }
    return 0;
}