#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    string a, b;
    cin >> N >> a >> b;

    bool eq = true;
    int ones = count(begin(a), end(a), '1');
    int zeros = N - ones;

    for (int i = N - 1; i >= 0; i--) {
        bool same = (a[i] == b[i]) == eq;
        if (!same && ones != zeros) {
            return "NO";
        }
        a[i] == '1' ? ones-- : zeros--;
        eq ^= !same;
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