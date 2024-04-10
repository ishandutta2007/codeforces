#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

long long k, a, b;

void Solve() {
    if (a < k && b < k) {
        cout << -1 << endl;
        return;
    }
    if (a < k) {
        if (b % k != 0) {
            cout << -1 << endl;
        } else {
            cout << b / k << endl;
        }
        return;
    }
    if (b < k) {
        if (a % k != 0) {
            cout << -1 << endl;
        } else {
            cout << a / k << endl;
        }
        return;
    }

    long long result = 0;
    result += a / k;
    result += b / k;

    cout << result << endl;
}

bool Read() {
    if (!(cin >> k >> a >> b)) {
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