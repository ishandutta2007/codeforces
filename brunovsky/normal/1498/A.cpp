#include <bits/stdc++.h>

using namespace std;

// *****

auto sum(const string& s) {
    int n = 0;
    for (char c : s)
        n += c - '0';
    return n;
}

auto solve() {
    long long n;
    cin >> n;
    string s = to_string(n);
    while (gcd(n, sum(s)) == 1)
        n++, s = to_string(n);
    return n;
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