#include <bits/stdc++.h>

using namespace std;

#define long int64_t

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

using Set = multiset<int, greater<int>>;

void merge(Set& a, Set& b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    a.merge(b);
}

int main() {
    ios::sync_with_stdio(false);
    constexpr int A = 'z' - 'a' + 1;
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    sort(begin(words), end(words));

    vector<int> wlen(N);
    for (int i = 0; i < N; i++) {
        wlen[i] = words[i].size();
    }

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    auto dfs = y_combinator([&](auto self, int l, int r, int d) -> pair<int, Set> {
        int start[A] = {};
        int finish[A] = {};
        Set depths;
        int dp = 0;

        bool empty = wlen[l] == d;
        for (int c = 0, i = l + empty; c < A; c++) {
            start[c] = i;
            while (i < r && words[i][d] == c + 'a') {
                i++;
            }
            finish[c] = i;
        }

        for (int c = 0; c < A; c++) {
            int i = start[c], j = finish[c];
            if (j - i >= 1) {
                auto [sub_dp, sub_depths] = self(i, j, d + 1);
                dp += sub_dp;
                merge(depths, sub_depths);
            }
        }

        if (empty) {
            depths.insert(d);
            dp += d;
        }

        if (depths.count(d) == 0 && d > 0) {
            dp = dp - *depths.begin() + d;
            depths.erase(depths.begin());
            depths.insert(d);
        }

        return make_pair(dp, move(depths));
    });
    int ans = dfs(0, N, 0).first;
    cout << ans << endl;
    return 0;
}