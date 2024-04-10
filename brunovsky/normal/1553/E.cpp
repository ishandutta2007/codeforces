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
        vector<int> p(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> p[i];
        }
        map<int, int> freq;
        for (int i = 1; i <= N; i++) {
            if (p[i] <= i) {
                freq[i - p[i]]++;
            } else {
                freq[i - p[i] + N]++;
            }
        }
        vector<int> candidates;
        for (auto [v, f] : freq) {
            if (0 <= v && v < N && f >= N - 2 * M) {
                candidates.push_back(v);
            }
        }
        assert(candidates.size() <= 3u);

        // Now check if they are actually possible
        vector<int> answers;

        for (int delta : candidates) {
            vector<int> q(N);
            iota(begin(q), end(q), 1);
            rotate(begin(q), begin(q) + (N - delta), end(q));
            q.insert(begin(q), 0);

            vector<int> where_q(N + 1); // where value v is in q
            vector<int> where_p(N + 1); // where value v is in p
            for (int i = 1; i <= N; i++) {
                where_q[q[i]] = i;
                where_p[p[i]] = i;
            }

            int fixes = 0;
            for (int u = 1; u <= N; u++) {
                if (where_q[u] != where_p[u]) {
                    int i = where_q[u];
                    int j = where_p[u];
                    int v = q[j];
                    q[j] = u, where_q[u] = j;
                    q[i] = v, where_q[v] = i;
                    fixes++;
                }
            }

            if (fixes <= M) {
                answers.push_back(delta);
            }
        }

        cout << answers.size();
        for (int i = 0, V = answers.size(); i < V; i++) {
            cout << " " << answers[i];
        }
        cout << endl;
    }
    return 0;
}