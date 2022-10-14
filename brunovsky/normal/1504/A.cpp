#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    string s;
    cin >> s;
    int S = s.size();
    int n = count(begin(s), end(s), 'a');
    if (n == S)
        return "NO"s;

    int k = find_if(begin(s), end(s), [](char c) { return c != 'a'; }) - begin(s);
    s.insert(end(s) - k, 'a');
    return "YES\n" + s;
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