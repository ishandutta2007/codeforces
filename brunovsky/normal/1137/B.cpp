#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

/**
 * Compute the z function of string s.
 * z[i] := longest common prefix of s[0..] and s[i..]; z[0]=0.
 *
 * Complexity: O(N)
 * Reference: https://cp-algorithms.com/string/z-function.html
 */
template <typename Vec>
auto build_z_function(const Vec& s) {
    int N = s.size();
    vector<int> z(N);
    for (int i = 1, l = 0, r = 0; i < N; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < N && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r + 1)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

const int inf = INT_MAX / 3;
int quo(int a, int b) { return b == 0 ? inf : a / b; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int N = t.size();
    int O = count(begin(s), end(s), '1');
    int Z = count(begin(s), end(s), '0');
    debug(s, t);

    vector<int> ones(N + 1), zers(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        ones[i] = ones[i + 1] + (t[i] == '1');
        zers[i] = zers[i + 1] + (t[i] == '0');
    }
    if (ones[0] > O || zers[0] > Z) {
        cout << s << '\n';
        return 0;
    }

    auto ans = make_pair(min(quo(O, ones[0]), quo(Z, zers[0])), 0);

    auto z = build_z_function(t);
    for (int i = 1; i < N; i++) {
        if (int j = N - i; N == j + z[j]) {
            // 1s: ones[i] * k + ones[N]
            // 0s: zers[i] * k + zers[N]
            // ones[i] * k + ones[N] <= O and zers[i] * k + zers[N] <= Z
            int a = quo(O - ones[0], ones[i]);
            int b = quo(Z - zers[0], zers[i]);
            ans = max(ans, make_pair(1 + min(a, b), i));
        }
    }

    string opt;
    if (auto [cnt, i] = ans; i == 0) {
        while (cnt-- > 0) {
            opt += t;
            O -= ones[0];
            Z -= zers[0];
        }
    } else {
        string block = t.substr(i);
        opt += t;
        O -= ones[0];
        Z -= zers[0];
        while (cnt-- > 1) {
            opt += block;
            O -= ones[i];
            Z -= zers[i];
        }
    }
    debug(O, Z);
    assert(O >= 0 && Z >= 0);
    while (O--) {
        opt.push_back('1');
    }
    while (Z--) {
        opt.push_back('0');
    }
    cout << opt << '\n';
    return 0;
}