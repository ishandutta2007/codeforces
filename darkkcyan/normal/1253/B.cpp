#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> ans;
    set<int> cur;
    vector<int> last_enter((int)1e6 + 10, -1);
    int prv = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > 0) {
            if (cur.count(x) or last_enter[x] >= prv) {
                cout << "-1\n";
                return 0;
            }
            cur.insert(x);
            last_enter[x] = i;
        } else {
            x = -x;
            if (!cur.count(x)) {
                cout << "-1\n";
                return 0;
            }
            cur.erase(x);
            if (cur.size() == 0) {
                ans.push_back(i - prv + 1);
                prv = i + 1;
            }
        }
    }
    if (cur.size()) {
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for (auto i: ans) cout << i << ' ';
    return 0;
}