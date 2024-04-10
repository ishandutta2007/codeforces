#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

const int LOSE = 1, WIN = 2, LOOP = 0;

auto solve(int N, const array<set<int>, 2>& is) {
    vector<array<int, 2>> bfs;
    vector<array<int, 2>> dp(N, {LOOP, LOOP});
    vector<array<int, 2>> mov(N, {0, 0});
    for (int s : {0, 1}) {
        for (int x : is[s]) {
            dp[N - x][s] = WIN;
            bfs.push_back({s, N - x});
        }
    }
    for (int i = 1; i < N; i++) {
        for (int s : {0, 1}) {
            if (dp[i][s] == LOOP) {
                mov[i][s] = is[s].size();
            }
        }
    }
    for (int j = 0, B = bfs.size(); j < B; j++) {
        auto [s, k] = bfs[j];
        if (dp[k][s] == WIN) {
            for (int y : is[!s]) {
                int i = (k - y + N) % N;
                if (1 <= i && i < N && dp[i][!s] == LOOP && --mov[i][!s] == 0) {
                    dp[i][!s] = LOSE;
                    bfs.push_back({!s, i}), B++;
                }
            }
        } else {
            for (int y : is[!s]) {
                int i = (k - y + N) % N;
                if (1 <= i && i < N && dp[i][!s] == LOOP) {
                    dp[i][!s] = WIN;
                    bfs.push_back({!s, i}), B++;
                }
            }
        }
    }
    // Black hole at N
    return dp;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    int A;
    cin >> A;
    set<int> a;
    for (int i = 0; i < A; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int B;
    cin >> B;
    set<int> b;
    for (int i = 0; i < B; i++) {
        int y;
        cin >> y;
        b.insert(y);
    }

    auto dp = solve(N, {a, b});
    vector<string> names = {"Loop", "Lose", "Win"};
    for (int i = 1; i < N; i++) {
        cout << names[dp[i][0]] << " \n"[i + 1 == N];
    }
    for (int i = 1; i < N; i++) {
        cout << names[dp[i][1]] << " \n"[i + 1 == N];
    }
    return 0;
}