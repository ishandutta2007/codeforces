#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int n, k;
vector<string> res;

string GetUnique() {
    static int nxt = 0;
    assert(nxt < 26 * 26);
    if (nxt >= 26) {
        string s;
        s.resize(2);
        s[0] = 'A' + (nxt / 26);
        s[1] = 'a' + (nxt % 26);
        ++nxt;
        return s;
    }
    string result;
    result.push_back('A' + (nxt++));
    return result;
}

void Solve() {
    vector<string> result;
    for (int i = 0; i + 1 < k; ++i) {
        result.push_back(GetUnique());
    }
    for (int i = 0; i < (int) res.size(); ++i) {
        if (res[i] == "NO") {
            result.push_back(result[i]);
        } else {
            result.push_back(GetUnique());
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n >> k)) {
        return false;
    }
    res.resize(n - k + 1);
    for (int i = 0; i + k <= n; ++i) {
        cin >> res[i];
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