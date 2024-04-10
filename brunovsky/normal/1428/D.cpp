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
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> ones, other, match(N, -1);
    for (int i = N - 1; i >= 0; i--) {
        if (a[i] == 1) {
            ones.push_back(i);
        } else if (a[i] == 2) {
            if (!ones.empty()) {
                match[i] = ones.back();
                ones.pop_back();
                other.push_back(i);
            } else {
                cout << -1 << '\n';
                return 0;
            }
        } else if (a[i] == 3) {
            if (!other.empty()) {
                match[i] = other.back();
                other.pop_back();
                other.push_back(i);
            } else if (!ones.empty()) {
                match[i] = ones.back();
                ones.pop_back();
                other.push_back(i);
            } else {
                cout << -1 << '\n';
                return 0;
            }
        } else {
            assert(a[i] == 0);
        }
    }
    int r = 0;
    vector<array<int, 2>> pos;
    vector<int> assigned(N);
    auto assign = y_combinator([&](auto self, int i) -> void {
        assigned[i] = true;
        if (a[i] == 1) {
            pos.push_back({r++, i});
        } else if (a[i] == 2) {
            pos.push_back({r, i});
            self(match[i]);
        } else {
            pos.push_back({r, i});
            pos.push_back({r++, match[i]});
            self(match[i]);
        }
    });
    for (int i = 0; i < N; i++) {
        if (a[i] >= 1 && !assigned[i]) {
            assign(i);
        }
    }
    assert(r <= N);
    cout << pos.size() << '\n';
    for (auto [r, c] : pos) {
        cout << r + 1 << ' ' << c + 1 << '\n';
    }
    return 0;
}

// 2 --> 1
// 3 --> anything ok