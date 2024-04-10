#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


string s, t;

void Solve() {
    if (s == t) {
        cout << -1 << endl;
    } else {
        cout << max(s.length(), t.length()) << endl;
    }
}

bool Read() {
    if (!(cin >> s >> t)) {
        return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}