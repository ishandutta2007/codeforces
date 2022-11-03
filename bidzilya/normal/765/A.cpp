#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int n;
string home;
vector<pair<string, string>> a;

map<string, int> counter;

void Solve() {
    for (int i = 0; i < n; ++i) {
        if (a[i].first == home) {
            ++counter[a[i].second];
        } else {
            --counter[a[i].first];
        }
    }

    for (const auto& x : counter) {
        if (x.second != 0 && x.first != home) {
            cout << "contest" << endl;
            return;
        }
    }

    cout << "home" << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    cin >> home;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        a[i].first = temp.substr(0, 3);
        a[i].second = temp.substr(5, 3);
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