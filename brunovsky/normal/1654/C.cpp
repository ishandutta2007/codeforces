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
        sort(begin(a), end(a));

        int64_t W = accumulate(begin(a), end(a), 0LL);
        multiset<int64_t> available(begin(a), end(a));

        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> targets;
        targets.push(W);

        while (!targets.empty()) {
            int64_t w = targets.top();
            targets.pop();

            if (auto pos = available.find(w); pos != available.end()) {
                available.erase(pos);
            } else if (w >= 2) {
                int64_t a = w / 2, b = (w + 1) / 2;
                targets.push(a);
                targets.push(b);
            } else {
                break;
            }
        }

        cout << (available.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}