#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, a;

void Solve() {
    cout << 1LL * (n / a + (n % a != 0)) * (m / a + (m % a != 0)) << endl;
}

bool Read() {
    if (!(cin >> n >> m >> a)) {
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