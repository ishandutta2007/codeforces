#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int n;
vector<int> a;
map<int, int> pos;

void Solve() {
    vector<int> b = a;
    pos.clear();
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        pos[b[i]] = i;
    }
    vector<bool> used(n, false);
    vector<vector<int>> result;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        result.push_back(vector<int>());
        int j = i;
        while (!used[j]) {
            result.back().push_back(j);
            used[j] = true;
            j = pos[a[j]];
        }
    }
    cout << result.size() << endl;
    for (int i = 0; i < (int) result.size(); ++i) {
        sort(result[i].begin(), result[i].end());
        cout << result[i].size() << " ";
        for (int x : result[i]) {
            cout << x + 1 << " ";
        }
        cout << '\n';
    }
    cout.flush();
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