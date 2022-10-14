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
    vector<vector<int>> voters(M + 1);
    for (int i = 0; i < N; i++) {
        int p, c;
        cin >> p >> c;
        voters[p].push_back(c);
    }
    for (int p = 1; p <= M; p++) {
        sort(begin(voters[p]), end(voters[p]));
    }
    int64_t ans = INT64_MAX;
    for (int v = 1; v <= N; v++) {
        // Suppose we're gonna win with v votes
        int64_t cost = 0;
        vector<int> remaining;
        int count = voters[1].size();
        for (int p = 2; p <= M; p++) {
            int S = voters[p].size();
            int g = max(S - v + 1, 0);
            count += g;
            cost += accumulate(begin(voters[p]), begin(voters[p]) + g, 0LL);
            remaining.insert(end(remaining), begin(voters[p]) + g, end(voters[p]));
        }
        if (int need = max(v - count, 0); need > 0) {
            sort(begin(remaining), end(remaining));
            cost += accumulate(begin(remaining), begin(remaining) + need, 0LL);
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}