#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N + 1);
    vector<array<int, 2>> pairs(M);
    for (auto& [a, b] : pairs) {
        cin >> a >> b;
        cnt[a]++, cnt[b]++;
    }

    vector<int> half;
    for (int n = 1; n <= N; n++) {
        if (cnt[n] >= (M + 1) / 2) {
            half.push_back(n);
        }
    }
    debug(half);
    if (half.empty()) {
        cout << "NO\n";
        return 0;
    }

    for (int n : half) {
        set<int> cands;
        bool busted = false;

        for (int i = 0; i < M; i++) {
            auto [a, b] = pairs[i];
            if (a != n && b != n) {
                if (cands.empty()) {
                    cands = {a, b};
                } else {
                    vector<int> bad;
                    set<int> ab = {a, b};
                    for (int v : cands) {
                        if (!ab.count(v)) {
                            bad.push_back(v);
                        }
                    }
                    for (int v : bad) {
                        cands.erase(v);
                    }
                }
                if (cands.empty()) {
                    busted = true;
                    break;
                }
            }
        }

        if (!busted) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}