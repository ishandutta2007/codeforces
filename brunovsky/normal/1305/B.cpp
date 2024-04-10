#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    int N = s.size();
    int O = 0, C = 0;
    for (char c : s) {
        O += c == '(';
        C += c == ')';
    }
    // N<=1000
    vector<vector<int>> ops;
    while (true) {
        vector<int> op, os, cs;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                os.push_back(i);
            } else {
                cs.push_back(i);
            }
        }
        pair<int, int> best = {-1, -1};
        for (int i = 0, j = 0; i < O; i++) {
            while (j < C && cs[j] < os[i]) {
                j++;
            }
            if (C - j >= i + 1) {
                best = {i, j};
            }
        }
        debug(N, O, C, best);
        if (best.first == -1) {
            break;
        }
        int S = best.first + 1;
        for (int i = 0; i < S; i++) {
            op.push_back(os[i]);
        }
        for (int j = C - S; j <= C - 1; j++) {
            op.push_back(cs[j]);
        }
        string t;
        for (int i = 0, j = 0; i < N; i++) {
            if (j < 2 * S && i == op[j]) {
                j++;
            } else {
                t.push_back(s[i]);
            }
        }
        O -= S, C -= S, N -= 2 * S, swap(s, t);
        ops.push_back(move(op));
    }

    cout << ops.size() << '\n';
    for (const auto& op : ops) {
        int S = op.size();
        cout << S << '\n';
        for (int i = 0; i < S; i++) {
            cout << op[i] + 1 << " \n"[i + 1 == S];
        }
    }
    return 0;
}