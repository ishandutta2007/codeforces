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
    vector<int> s(N), t(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    sort(begin(t), end(t));
    int64_t S = accumulate(begin(s), end(s), 0LL);
    int64_t T = accumulate(begin(t), end(t), 0LL);
    if (S != T) {
        cout << "NO\n";
        return 0;
    }
    vector<int> index(N);
    iota(begin(index), end(index), 0);
    sort(begin(index), end(index),
         [&](int i, int j) { return make_pair(s[i], i) < make_pair(s[j], j); });
    vector<int> cuts = {0};
    int64_t P = 0;
    for (int i = 0; i < N; i++) {
        P += s[index[i]] - t[i];
        if (P == 0) {
            cuts.push_back(i + 1);
        }
    }
    assert(P == 0 && cuts.back() == N);
    int C = cuts.size();
    debug(index);
    debug(cuts);
    vector<array<int, 3>> ops;
    for (int i = 0; i + 1 < C; i++) {
        int L = cuts[i], R = cuts[i + 1];
        set<int> addi, remi = {R};
        for (int j = L; j < R; j++) {
            if (s[index[j]] < t[j]) {
                addi.insert(j);
            } else if (t[j] < s[index[j]]) {
                remi.insert(j);
            }
        }
        while (!addi.empty()) {
            int l = *addi.begin();
            int r = *remi.lower_bound(l);
            if (r == R) {
                cout << "NO\n";
                return 0;
            }
            int a = t[l] - s[index[l]];
            int b = s[index[r]] - t[r];
            int d = min(a, b);
            ops.push_back({index[l], index[r], d});
            s[index[l]] += d;
            s[index[r]] -= d;
            if (s[index[l]] == t[l]) {
                addi.erase(l);
            }
            if (s[index[r]] == t[r]) {
                remi.erase(r);
            }
        }
    }
    int O = ops.size();
    cout << "YES\n";
    cout << O << '\n';
    for (int i = 0; i < O; i++) {
        auto [x, y, d] = ops[i];
        cout << x + 1 << ' ' << y + 1 << ' ' << d << '\n';
    }
    return 0;
}