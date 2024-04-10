#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

/**
 * Compute the longest palindrome lp[i] around position i for string s.
 * lp[0][i]: number of palindromes around s[i-1|i]; lp[0][0]=0, lp[0][i]>=0.
 *           biggest starts at s[i-lp[0][i]], ends at s[i-1+lp[0][i]].
 * lp[1][i]: number of palindromes around s[i]; lp[1][i]>=1.
 *           biggest starts at s[i+1-lp[1][i]], ends at s[i-1+lp[1][i]].
 */
template <typename Vec>
auto build_manachers(const Vec& s) {
    int N = s.size();
    array<vector<int>, 2> lp{vector<int>(N + 1), vector<int>(N)};
    for (int b : {0, 1}) {
        for (int i = 0, l = 0, r = -1; i < N; i++) {
            int k = (i > r) ? b : min(lp[b][l + r - i + !b], r - i + 1);
            while (0 <= i - k - !b && i + k < N && s[i - k - !b] == s[i + k]) {
                k++;
            }
            lp[b][i] = k--;
            if (i + k > r) {
                l = i - k - !b;
                r = i + k;
            }
        }
    }
    return lp;
}

auto solve() {
    string s;
    cin >> s;
    int S = s.size();
    auto lp = build_manachers(s);
    vector<int> b(S, 0); // longest <= S-2i.
    vector<int> c(S, 0); // longest <= 2i+2-S.
    int left = S - 1;
    for (int i = S - 1; i >= 0; i--) {
        while (left >= i + 1 - lp[1][i] && 2 * (i - left) + 1 <= S - 2 * left) {
            b[left] = 2 * (i - left) + 1, left--;
        }
        while (left >= i - lp[0][i] && 2 * (i - left) <= S - 2 * left) {
            b[left] = 2 * (i - left), left--;
        }
    }
    int right = 0;
    for (int i = 0; i < S; i++) {
        while (right <= i - 1 + lp[0][i] && 2 * (right - i) + 2 <= 2 * right + 2 - S) {
            c[right] = 2 * (right - i) + 2, right++;
        }
        while (right <= i - 1 + lp[1][i] && 2 * (right - i) + 1 <= 2 * right + 2 - S) {
            c[right] = 2 * (right - i) + 1, right++;
        }
    }
    int length = max(b[0], c[S - 1]);
    array<int, 2> each;
    if (b[0] >= c[S - 1]) {
        each = {b[0], 0};
    } else {
        each = {0, c[S - 1]};
    }
    for (int l = 1, r = S - 2; l <= r && s[l - 1] == s[r + 1]; l++, r--) {
        if (length < 2 * l + max(b[l], c[r])) {
            length = 2 * l + max(b[l], c[r]);
            if (b[l] >= c[r]) {
                each = {l + b[l], S - (r + 1)};
            } else {
                each = {l, S - (r + 1) + c[r]};
            }
        }
    }
    return s.substr(0, each[0]) + s.substr(S - each[1], each[1]);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}