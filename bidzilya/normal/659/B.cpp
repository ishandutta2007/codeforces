#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

bool Check(const vector<pair<int, string>>& a) {
    if (a.size() == 2) {
        return true;
    }
    if (a[0].first == a[1].first && a[1].first != a[2].first) {
        return true;
    }
    if (a[1].first != a[2].first) {
        return true;
    }
    return false;
}

void ShowResult(const vector<pair<int, string>>& a) {
    if (Check(a)) {
        cout << a[0].second << " " << a[1].second << '\n';
    } else {
        cout << "?\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, string>>> a(m);
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        int cmd;
        cin >> cmd;
        --cmd;
        int score;
        cin >> score;
        a[cmd].push_back(make_pair(score, name));
    }

    for (int i = 0; i < m; ++i) {
        sort(a[i].begin(), a[i].end(), greater<pair<int, string>>());
    }

    for (int i = 0; i < m; ++i) {
        ShowResult(a[i]);
    }
    cout.flush();

    return 0;
}