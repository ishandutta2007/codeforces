#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> a;
vector<int> b;

void Solve() {
    int result = 0;
    {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += b[i];
        }
        if (!(count & 1)) {
            ++result;
        }
    }
    {
        int count = 0;
        vector<bool> used(n, false);
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            int x = i;
            ++count;
            while (!used[x]) {
                used[x] = true;
                x = a[x];
            }
        }
        if (count > 1) {
            result += count;
        }
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
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