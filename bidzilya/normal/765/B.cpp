#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int CHARS_COUNT = 26;

string s;

vector<bool> hasChar;

void Solve() {
    hasChar.assign(CHARS_COUNT, false);
    vector<pair<char, int>> poses;
    for (int i = 0; i < (int) s.length(); ++i) {
        const char c = s[i];
        if (!hasChar[c - 'a']) {
            poses.push_back(make_pair(c, i));
        }
        hasChar[c - 'a'] = true;
    }

    for (int i = 1; i < CHARS_COUNT; ++i) {
        if (hasChar[i] && !hasChar[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    sort(poses.begin(), poses.end());
    for (int i = 1; i < (int) poses.size(); ++i) {
        if (poses[i].second < poses[i - 1].second) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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