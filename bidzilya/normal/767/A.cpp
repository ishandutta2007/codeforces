#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> a;

set<int> values;

void Solve() {
    int last = n + 1;
    values.clear();
    for (int i = 0; i < n; ++i) {
        values.insert(a[i]);

        while (values.find(last - 1) != values.end()) {
            cout << last - 1 << " ";
            values.erase(last - 1);
            --last;
        }
        cout << '\n';
    }
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
    cout.flush();

    return 0;
}