#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<int> parts;
    set<int> elms;
    for (int i = 1; i <= n; ++i) {
        int u; cin >> u;
        if (!elms.count(u)) {
            elms.insert(u);
            continue;
        }
        parts.push_back(i);
        elms.clear();
    }
    
    if (!parts.size()) {
        cout << -1;
        return 0;
    }
    parts.back() = n;
    cout << parts.size() << '\n';
    int last = 1;
    for (auto i: parts) {
        cout << last << ' ' << i << '\n';
        last = i + 1;
    }
    return 0;
}