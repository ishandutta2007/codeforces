#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

auto merge_xor_vectors(vector<int>& a, const vector<int>& b) {
    for (int i = 0, S = a.size(); i < S; i++) {
        a[i] ^= b[i];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> p(N + 1);
        vector<vector<int>> kids(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> p[i];
            kids[p[i]].push_back(i);
        }
        vector<int> rank(N + 1);
        y_combinator([&](auto self, int u) -> void {
            rank[u] = kids[u].empty() ? 1 : N + 1;
            for (int v : kids[u]) {
                self(v);
                rank[u] = min(rank[u], rank[v] + 1);
            }
        })(0);
        struct Mex {
            vector<int> grundy;
            set<int> seen;
            int M = 0;

            void flush() {
                while (seen.count(M)) {
                    M++;
                }
                assert(grundy.back() == -1);
                grundy.back() = M;
                seen.insert(M);
            }
        };
        auto ans = y_combinator([&](auto self, int u) -> Mex {
            if (int S = kids[u].size(); S == 0) {
                return Mex{{0, 1}, {0, 1}, 2};
            } else if (S == 1) {
                int v = kids[u][0];
                Mex mex = self(v);
                mex.grundy.push_back(-1);
                mex.flush();
                return mex;
            } else {
                vector<int> me(rank[u], 0);
                for (int v : kids[u]) {
                    auto kid = self(v).grundy;
                    kid.erase(begin(kid), end(kid) - rank[u]);
                    merge_xor_vectors(me, kid);
                }
                set<int> seen(begin(me), end(me));
                Mex mex{move(me), move(seen), 0};
                mex.grundy.push_back(-1);
                mex.flush();
                return mex;
            }
        })(0);
        int S = ans.grundy.size();
        cout << (ans.grundy[S - 2] > 0 ? "YES\n" : "NO\n");
    }
    return 0;
}