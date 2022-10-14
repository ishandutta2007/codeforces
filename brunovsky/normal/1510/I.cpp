#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

mt19937 mt(random_device{}());

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    constexpr int B = 50;
    vector<int64_t> power(B + 1);
    for (int b = 0; b <= B; b++) {
        power[b] = b ? 2 * power[b - 1] : 1;
    }
    reverse(begin(power), end(power));

    vector<int> mistakes(N);
    for (int contest = 0; contest < M; contest++) {
        string guess;
        cin >> guess;
        int A = *min_element(begin(mistakes), end(mistakes));
        vector<int64_t> likely(N);
        for (int i = 0; i < N; i++) {
            likely[i] = power[min(B, mistakes[i] - A)];
        }
        discrete_distribution<int> accept(begin(likely), end(likely));
        int g = guess[accept(mt)] - '0';
        cout << g << endl;
        cin >> g;
        for (int i = 0; i < N; i++) {
            mistakes[i] += guess[i] - '0' != g;
        }
    }
    return 0;
}