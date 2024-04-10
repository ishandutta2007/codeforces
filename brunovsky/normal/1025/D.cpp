#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

bool can_edge[702][702];
bool can_intv[702][702][2];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            can_edge[i][j] = can_edge[j][i] = gcd(arr[i], arr[j]) > 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        can_intv[i][i][0] = i == 1 || can_edge[i][i - 1];
        can_intv[i][i][1] = i == N || can_edge[i][i + 1];
    }
    for (int len = 2; len <= N; len++) {
        for (int l = 1, r = l + len - 1; r <= N; l++, r++) {
            for (int m = l; m <= r; m++) {
                bool down = (l == m || can_intv[l][m - 1][1]) &&
                            (m == r || can_intv[m + 1][r][0]);
                can_intv[l][r][0] |= (l == 1 || can_edge[l - 1][m]) && down;
                can_intv[l][r][1] |= (r == N || can_edge[m][r + 1]) && down;
            }
        }
    }
    assert(can_intv[1][N][0] == can_intv[1][N][1]);
    if (can_intv[1][N][0]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}