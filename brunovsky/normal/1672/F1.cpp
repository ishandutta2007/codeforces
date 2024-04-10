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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        vector<vector<int>> pos(N + 1);
        for (int i = 0; i < N; i++) {
            pos[a[i]].push_back(i);
        }

        set<int> values;
        for (int i = 0; i < N; i++) {
            values.insert(a[i]);
        }

        vector<int> b(N);

        while (!values.empty()) {
            vector<int> vals, indices;
            for (int v : values) {
                vals.push_back(v);
                indices.push_back(pos[v].back());
                pos[v].pop_back();
            }
            int S = vals.size();
            for (int i = 0; i < S; i++) {
                b[indices[(i + 1) % S]] = vals[i];
            }
            auto it = values.begin();
            while (it != values.end()) {
                if (pos[*it].empty()) {
                    it = values.erase(it);
                } else {
                    ++it;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            cout << b[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}

// If all the numbers are different sadness is n-1