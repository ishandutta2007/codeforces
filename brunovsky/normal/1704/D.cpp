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
        vector<pair<int64_t, int>> score(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int64_t c;
                cin >> c;
                score[i].first += j * c;
            }
            score[i].second = i;
        }
        sort(begin(score), end(score));
        int x = score[N - 1].second + 1;
        int64_t ops = score[N - 1].first - score[0].first;
        cout << x << ' ' << ops << '\n';
    }
    return 0;
}