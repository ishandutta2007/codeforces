#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> P(N), where(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        where[i] = 100 * i;
    }
    vector<int> shops(M);
    for (int i = 0; i < M; i++) {
        cin >> shops[i];
    }
    sort(begin(shops), end(shops));
    auto next_after = [&](int i) {
        return lower_bound(begin(where), end(where), i) - begin(where);
    };
    int64_t ans = 0;
    for (int s = -1; s < M; s++) {
        int L = s == -1 ? int(-1e9) - 1 : shops[s];
        int R = s + 1 == M ? int(2e9) + 1 : shops[s + 1];
        int G = (int64_t(R) - L - 1) / 2;
        int a = next_after(L + 1);
        int b = next_after(R);
        if (a == b || a >= N) {
            continue;
        }
        int64_t window = P[a];
        int l = a, r = a + 1;
        while (r < b && where[r] - where[l] <= G) {
            window += P[r++];
        }
        ans = max(ans, window);
        while (r != b) {
            window -= P[l++];
            while (r < b && where[r] - where[l] <= G) {
                window += P[r++];
            }
            ans = max(ans, window);
        }
    }
    cout << ans << '\n';
    return 0;
}