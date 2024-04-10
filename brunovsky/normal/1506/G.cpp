#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

int make_mask(const string& s, int l, int r) {
    int seen = 0;
    for (int i = l; i < r; i++) {
        seen |= 1 << (s[i] - 'a');
    }
    return seen;
}

bool possible(const string& s, const string& ans, int all) {
    int i = 0, j = 0, S = s.size(), A = ans.size();
    while (i < S && j < A) {
        j += s[i] == ans[j];
        i++;
    }
    if (j < A) {
        return false;
    }
    return (make_mask(s, i, S) | make_mask(ans, 0, A)) == all;
}

auto solve() {
    string s, ans;
    cin >> s;
    s.erase(unique(begin(s), end(s)), end(s));
    int all = make_mask(s, 0, s.size());
    set<char, greater<char>> remaining(begin(s), end(s));
    size_t n = remaining.size();

    while (ans.size() < n) {
        char best = 'a';
        for (char c : remaining) {
            if (possible(s, ans + c, all)) {
                best = c;
                break;
            }
        }
        ans += best;
        remaining.erase(best);
    }
    return ans;
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