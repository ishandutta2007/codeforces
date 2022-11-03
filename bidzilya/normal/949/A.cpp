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

string s;

void Solve() {
    int zeros = count(s.begin(), s.end(), '0');
    int ones = count(s.begin(), s.end(), '1');
    const int n = s.size();
    if (zeros <= ones) {
        cout << -1 << endl;
        return;
    }
    const int k = zeros - ones;
    vector<vector<int>> res(k);
    set<int> lastOne;
    set<int> lastZero;
    for (int i = 0; i < k; ++i) {
        lastOne.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (lastOne.empty()) {
                cout << -1 << endl;
                return;
            }
            auto itr = lastOne.begin();
            int idx = *itr;
            lastOne.erase(itr);
            lastZero.insert(idx);
            res[idx].push_back(i);
        } else {
            if (lastZero.empty()) {
                cout << -1 << endl;
                return;
            }
            auto itr = lastZero.begin();
            int idx = *itr;
            lastZero.erase(itr);
            lastOne.insert(idx);
            res[idx].push_back(i);
        }
    }
    cout << k << '\n';
    for (const auto& v : res) {
        cout << v.size();
        for (int x : v) {
            cout << " " << x + 1;
        }
        cout << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> s)) {
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