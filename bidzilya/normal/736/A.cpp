#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long n;

void Solve() {
    long long result = 1;
    n -= 2;

    vector<long long> fibs;
    fibs.push_back(1);
    fibs.push_back(2);
    while (fibs.back() <= n) {
        fibs.push_back(fibs.back() + fibs[fibs.size() - 2]);
    }

    while (result - 1 < (int) fibs.size()) {
        if (n >= fibs[result - 1]) {
            n -= fibs[result - 1];
            ++result;
        } else {
            break;
        }
    }

    cout << result << endl;
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