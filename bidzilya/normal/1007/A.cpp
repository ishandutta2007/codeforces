#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int n;
vector<int> a;

void Solve() {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    auto b = a;
    int result = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (b[j] > a[i]) {
            ++result;
            ++j;
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
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}