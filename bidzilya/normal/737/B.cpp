#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, a, b, k;
string s;

vector<pair<int, int>> lens;

void Solve() {
    lens.clear();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            int j = i;
            while (j + 1 < n && s[j + 1] == s[i]) {
                ++j;
            }
            if (j - i + 1 >= b) {
                lens.push_back(make_pair(i + 1, (j - i + 1) / b));
            }
            i = j;
        }
    }
    vector<int> result;
    for (const auto& p : lens) {
        for (int j = 1; j <= p.second; ++j) {
            result.push_back(p.first + b * j - 1);
        }
    }
    result.resize((int) result.size() - a + 1);
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n >> a >> b >> k)) {
        return false;
    }
    cin >> s;
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