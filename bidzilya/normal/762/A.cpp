#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long n;
int k;

void Solve() {
    long long x;
    for (x = 1; x * x <= n; ++x) {
        if (n % x == 0) {
            --k;
            if (k == 0) {
                cout << x << endl;
                return;
            }
        }
    }
    --x;
    if (x * x == n) {
        --x;
    }
    for (; x >= 1; --x) {
        if (n % x == 0) {
            --k;
            if (k == 0) {
                cout << n / x << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

bool Read() {
    if (!(cin >> n >> k)) {
        return false;
    } else {
        return true;
    }
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