#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> a;

void Solve() {
    sort(a.begin(), a.end());
    for (int i = 2; i < n; ++i) {
        if (a[i] < a[i - 1] + a[i - 2]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
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