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
    vector<string> opt(46, "999999999");
    y_combinator([&](auto self, int v, string s, int sum) -> void {
        if (opt[sum].size() > s.size()) {
            opt[sum] = s;
        } else if (opt[sum].size() == s.size() && opt[sum] > s) {
            opt[sum] = s;
        }
        for (int i = v; i < 10; i++) {
            s.push_back('0' + i);
            self(i + 1, s, sum + i);
            s.pop_back();
        }
    })(1, ""s, 0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << opt[N] << '\n';
    }

    return 0;
}