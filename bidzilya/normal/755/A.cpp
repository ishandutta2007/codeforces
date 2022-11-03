#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MIN_M = 1;
const int MAX_M = 1e3;

bool IsPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int n;

void Solve() {
    for (int m = MIN_M; m <= MAX_M; ++m) {
        if (!IsPrime(n * m + 1)) {
            cout << m << endl;
            break;
        }
    }
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