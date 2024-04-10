#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 200011, max_k = 111, inf = 1000111222;

int n, k, l[max_n], r[max_n];
int dp[2][max_n][2];
vector<int> add[max_n][2], er[max_n][2];

void update(int a, int b, int c, int x) {
    if (dp[a][b][c] == -1) {
        dp[a][b][c] = x;
    } else {
        dp[a][b][c] = min(dp[a][b][c], x);
    }
}

void update_segment(int l, int r, int c, int x) {
    add[l][c].push_back(x);
    er[r + 1][c].push_back(x);
}

int q1 = 0, q2 = 1;

void upd() {
    multiset<int> q[2];
    for (int time = 0; time < max_n; ++time) {
        for (int last = 0; last < 2; ++last) {
            for (int x : add[time][last]) {
                q[last].insert(x);
            }
            for (int x : er[time][last]) {
                q[last].erase(q[last].find(x));
            }
            if (q[last].size()) {
                update(q1, time, last, *q[last].begin());
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> l[i] >> r[i];
    }
    l[k] = 2 * n;
    r[k] = 2 * n;
    memset(dp, -1, sizeof(dp));
    dp[q1][l[0]][0] = 0;
    for (int i = 0; i < k; ++i) {
        upd();
        memset(dp[q2], -1, sizeof(dp[q2]));
        for (int time = 0; time < max_n; ++time) {
            for (int last = 0; last < 2; ++last) {
                add[time][last].clear();
                er[time][last].clear();
            }
        }
        for (int time = 0; time < max_n; ++time) {
            for (int last = 0; last < 2; ++last) {
                if (dp[q1][time][last] == -1) {
                    continue;
                }
                update(q2, time + (l[i + 1] - l[i]) * (last == 0), last, dp[q1][time][last]);
                update_segment(time + (l[i + 1] - r[i]) * (last == 1), time + (l[i + 1] - r[i]) * (last == 1) + r[i] - l[i],
                       last ^ 1, dp[q1][time][last] + 1);
                update_segment(time + (l[i + 1] - r[i]) * (last == 0), time + (l[i + 1] - r[i]) * (last == 0) + r[i] - l[i],
                       last, dp[q1][time][last] + 2);
            }
        }
        swap(q1, q2);
    }
    upd();
    int ans = inf;
    for (int last = 0; last < 2; ++last) {
        if (dp[q1][n][last] != -1) {
            ans = min(ans, dp[q1][n][last]);
        }
    }
    if (ans == inf) {
        cout << "Hungry" << endl;
    } else {
        cout << "Full" << endl << ans << endl;
    }
    return 0;
}