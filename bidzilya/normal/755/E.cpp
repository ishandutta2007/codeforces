#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ShowResult(const vector<pair<int, int>>& a) {
    cout << a.size() << endl;
    for (const auto& x : a) {
        cout << x.first + 1 << " " << x.second + 1 << '\n';
    }
    cout.flush();
}

int n, k;

vector<pair<int, int>> GetLine(int n) {
    vector<pair<int, int>> result(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        result[i].first = i;
        result[i].second = i + 1;
    }
    return result;
}

void Solve() {
    if (n < 4 || (k != 2 && k != 3)) {
        cout << -1 << endl;
        return;
    }
    if (n == 4) {
        if (k == 3) {
            ShowResult(GetLine(n));
        } else {
            cout << -1 << endl;
        }
        return;
    }
    if (k == 2) {
        ShowResult(GetLine(n));
    } else {
        if (n >= 6) {
            auto result = GetLine(n);
            for (int i = 3; i < n; ++i) {
                result.push_back(make_pair(0, i));
            }
            ShowResult(result);
        } else {
            auto result = GetLine(n);
            result.push_back(make_pair(1, 4));
            ShowResult(result);
        }
    }
}

bool Read() {
    if (!(cin >> n >> k)) {
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