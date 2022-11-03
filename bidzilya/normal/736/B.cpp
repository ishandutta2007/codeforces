#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;

bool IsPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void Solve() {
    if (IsPrime(n)) {
        cout << 1 << endl;
        return;
    }
    if ((n & 1) == 0) {
        cout << 2 << endl;
        return;
    }
    if (IsPrime(n - 2)) {
        cout << 2 << endl;
        return;
    }
    cout << 3 << endl;
}

bool Read() {
    if (!(cin >> n)) {
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