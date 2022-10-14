#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<array<int, 2>> where(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int age;
            cin >> age, age--;
            where[age] = {i, j};
        }
    }
    vector<int> row(N), col(N);
    int64_t ans = 0;
    for (int a = 0; a < N * N; a++) {
        auto [i, j] = where[a];
        int ry = row[i]++;
        int cy = col[j]++;
        int ro = N - ry - 1;
        int co = N - cy - 1;
        ans += ry * co + ro * cy;
    }
    cout << ans / 2 << '\n';
    return 0;
}