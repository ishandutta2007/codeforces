#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);

    set<int> ord;
    for (int i = 1; i <= n; ++i) {
        ord.insert(i);
    }

    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : (par[x] = find(par[x]));
    };

    while (!ord.empty()) {
        int y = -1;
        for (auto x : ord) {
            if (y == -1 || d[x] > d[y]) {
                y = x;
            }
        }

        ord.erase(y);
        while (d[y]--) {
            cout << "? " << y << endl;
            int x;
            cin >> x;
            if (ord.count(x)) {
                par[x] = y;
                ord.erase(x);
            } else {
                par[y] = find(x);
                break;
            }
        }
    }

    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << " " << find(i);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}