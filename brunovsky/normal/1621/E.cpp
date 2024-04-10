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
        vector<int64_t> prof(N);
        for (int i = 0; i < N; i++) {
            cin >> prof[i];
        }

        sort(begin(prof), end(prof));
        prof.erase(begin(prof), begin(prof) + (N - M));

        struct Group {
            vector<int> ages;
            int64_t sum = 0;
            int size = 0, id;
        };
        vector<Group> groups(M);
        for (int g = 0; g < M; g++) {
            auto& [ages, sum, size, id] = groups[g];
            id = g;
            cin >> size;
            ages.resize(size);
            for (int j = 0; j < size; j++) {
                cin >> ages[j];
                sum += ages[j];
            }
        }

        sort(begin(groups), end(groups), [&](const auto& a, const auto& b) {
            return a.sum * b.size < b.sum * a.size;
        });

        vector<int8_t> ok_curr(M), ok_next(M), ok_prev(M);
        for (int i = 0; i < M; i++) {
            const auto& [ages, sum, size, id] = groups[i];
            ok_curr[i] = size * prof[i] >= sum;
            ok_prev[i] = i > 0 && size * prof[i - 1] >= sum;
            ok_next[i] = i + 1 < M && size * prof[i + 1] >= sum;
        }

        // What is the largest k such that [i,reach[i]) is all ok?
        vector<int> reach_curr(M + 1, M), reach_next(M + 1, M), reach_prev(M + 1, M);
        for (int i = M - 1; i >= 0; i--) {
            reach_curr[i] = ok_curr[i] ? reach_curr[i + 1] : i;
            reach_prev[i] = ok_prev[i] ? reach_prev[i + 1] : i;
            reach_next[i] = ok_next[i] ? reach_next[i + 1] : i;
        }

        vector<string> answers(M);

        for (int i = 0; i < M; i++) {
            const auto& [ages, sum, size, id] = groups[i];
            string cur(size, '0');
            int new_size = size - 1;

            for (int s = 0; s < size; s++) {
                int64_t new_sum = sum - ages[s];

                int L = -1, R = M;
                while (L + 1 < R) {
                    int mid = (L + R) / 2;
                    if (new_size * prof[mid] < new_sum) {
                        L = mid;
                    } else {
                        R = mid;
                    }
                }

                if (R == M) {
                    cur[s] = '0';
                    continue;
                }

                // Conditions:
                // if i=R, then [0...i) is ok and [i+1...M) is ok
                // if i<R, then [0...i) is ok and [R+1...M) is ok and (i..R] can use prev
                // if i>R, then [0...R) is ok and [i+1...M) is ok and [R..i) can use next
                bool ok = true;
                if (i == R)
                    ok = reach_curr[0] >= i && reach_curr[i + 1] >= M;
                else if (i < R)
                    ok = reach_curr[0] >= i && reach_curr[R + 1] >= M &&
                         reach_prev[i + 1] > R;
                else
                    ok = reach_curr[0] >= R && reach_curr[i + 1] >= M &&
                         reach_next[R] >= i;

                cur[s] = ok ? '1' : '0';
            }

            answers[id] = cur;
        }

        string out;
        for (int i = 0; i < M; i++) {
            out += answers[i];
        }
        cout << out << '\n';
    }
    return 0;
}