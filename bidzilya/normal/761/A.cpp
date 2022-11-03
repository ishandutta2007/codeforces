#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a, b;

void Solve() {
    if (a == 0 && b == 0) {
        cout << "NO" << endl;
        return;
    }
    if (abs(a - b) <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

bool Read() {
    if (!(cin >> a >> b)) {
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