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

auto QUERY(int a, int b) {
    cout << "? " << a + 1 << ' ' << b + 1 << endl;
    int x;
    cin >> x;
    if (x == -1) {
        exit(0);
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int N = 1 << n;
        vector<int> dudes(N);
        iota(begin(dudes), end(dudes), 0);
        while (N >= 4) {
            vector<int> winners;
            for (int i = 0; i < N; i += 4) {
                int a = dudes[i];
                int b = dudes[i + 1];
                int c = dudes[i + 2];
                int d = dudes[i + 3];
                int x = QUERY(a, c);
                if (x == 0) {
                    int y = QUERY(b, d);
                    assert(y == 1 || y == 2);
                    winners.push_back(y == 1 ? b : d);
                } else if (x == 1) {
                    int y = QUERY(a, d);
                    assert(y == 1 || y == 2);
                    winners.push_back(y == 1 ? a : d);
                } else {
                    int y = QUERY(c, b);
                    assert(y == 1 || y == 2);
                    winners.push_back(y == 1 ? c : b);
                }
            }
            swap(winners, dudes);
            N = dudes.size();
        }
        if (N == 2) {
            int a = dudes[0];
            int b = dudes[1];
            int x = QUERY(a, b);
            assert(x == 1 || x == 2);
            dudes = {x == 1 ? a : b};
        }
        cout << "! " << dudes[0] + 1 << endl;
    }
    return 0;
}