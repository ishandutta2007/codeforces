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
        vector<int> houses(M);
        for (int i = 0; i < M; i++) {
            cin >> houses[i];
        }
        sort(begin(houses), end(houses));
        multiset<int, greater<int>> gaps;
        for (int i = 0; i + 1 < M; i++) {
            int g = houses[i + 1] - houses[i] - 1;
            if (g > 0) {
                gaps.insert(g);
            }
        }
        {
            int g = N - 1 + (houses[0] - houses[M - 1]);
            if (g > 0) {
                gaps.insert(g);
            }
        }
        int time = 0;
        int64_t saved = 0;
        while (gaps.size()) {
            int g = *gaps.begin() - 2 * time;
            gaps.erase(gaps.begin());
            if (g <= 0) {
                break;
            } else if (g <= 2) {
                saved++;
                time++;
            } else {
                saved += g - 1;
                time += 2;
            }
        }
        cout << N - saved << '\n';
    }
    return 0;
}