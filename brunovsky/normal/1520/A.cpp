#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

auto solve() {
    int N;
    string s;
    cin >> N >> s;
    s.erase(unique(begin(s), end(s)), end(s));
    vector<int> cnt(26);
    for (int i = 0, S = s.size(); i < S; i++) {
        cnt[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 1) {
            return "NO";
        }
    }
    return "YES";
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