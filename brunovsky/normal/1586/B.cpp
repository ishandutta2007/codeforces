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

        vector<bool> between(N + 1);
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            between[b] = true;
        }

        int root = 0;
        for (int i = 1; i <= N; i++) {
            if (!between[i]) {
                root = i;
                break;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (i != root) {
                cout << i << ' ' << root << '\n';
            }
        }
    }
    return 0;
}