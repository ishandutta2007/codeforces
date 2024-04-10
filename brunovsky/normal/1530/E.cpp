#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
    constexpr int A = 26;
    while (T--) {
        string s;
        cin >> s;
        int N = s.size();
        array<int, A> freq = {};
        for (int c : s) {
            freq[c - 'a']++;
        }
        string chars;
        for (int c = 0; c < A; c++) {
            if (freq[c] > 0) {
                chars.push_back('a' + c);
            }
        }

        if (chars.size() == 1u) {
            cout << s << '\n';
            continue;
        }

        int perfect = -1;
        for (int c = 0; c < A; c++) {
            if (freq[c] == 1) {
                perfect = c;
                break;
            }
        }
        if (perfect != -1) {
            string ans(1, 'a' + perfect);
            freq[perfect]--;
            for (int c = 0; c < A; c++) {
                while (freq[c]-- > 0) {
                    ans.push_back('a' + c);
                }
            }
            cout << ans << '\n';
            continue;
        }

        // try aa where a is the smallest letter
        // otherwise ab should work

        // can we do aa?
        int C = chars.size();
        char a = chars[0], b = chars[1];

        if (freq[a - 'a'] - 2 <= (N - 2) / 2) {
            // we can do aa
            string ans = "xx";
            ans[0] = ans[1] = a;
            freq[a - 'a'] -= 2;

            string available;
            for (int c = 1; c < C; c++) {
                while (freq[chars[c] - 'a']-- > 0) {
                    available += chars[c];
                }
            }
            int V = available.size();
            assert(freq[a - 'a'] <= V);

            for (int i = 0; i < freq[a - 'a']; i++) {
                ans += available[i];
                ans += a;
            }
            ans += available.substr(freq[a - 'a']);
            cout << ans << '\n';
        } else {
            // we can do ab
            string ans = "xx";
            ans[0] = a, ans[1] = b;
            freq[a - 'a'] -= 1;
            freq[b - 'a'] -= 1;

            string available;
            for (int c = 2; c < C; c++) {
                while (freq[chars[c] - 'a']-- > 0) {
                    available += chars[c];
                }
            }
            int V = available.size();

            if (V > 0) {
                ans += string(freq[a - 'a'], a);
                ans += available[0];
                ans += string(freq[b - 'a'], b);
                ans += available.substr(1);
            } else {
                ans += string(freq[b - 'a'], b);
                ans += string(freq[a - 'a'], a);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}