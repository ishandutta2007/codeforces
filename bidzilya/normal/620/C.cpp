#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> result;

    set<int> s;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (s.find(a[i]) == s.end()) {
            s.insert(a[i]);
        } else {
            result.push_back(make_pair(start + 1, i + 1));
            s.clear();
            start = i + 1;
        }
    }

    if (start != n) {
        if (result.empty()) {
            cout << -1 << endl;
            return 0;
        }
        result.back().second = n;
    }

    cout << result.size() << endl;
    for (int i = 0; i < (int) result.size(); ++i) {
        cout << result[i].first << " " << result[i].second << '\n';
    }
    cout.flush();

    return 0;
}