#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include <cassert>
using namespace std;

int n;
vector<int> f;

int m;
vector<int> points;

vector<int> g;
vector<int> h;

void Solve() {
    points.clear();
    points.reserve(n);
    {
        vector<bool> used(n + 1, false);
        for (int i = 0; i < n; ++i) {
            used[f[i]] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (used[i]) {
                if (f[i - 1] != i) {
                    cout << -1 << endl;
                    return;
                }
                points.push_back(i);
            }
        }
        m = points.size();
    }

    g.assign(n, -1);
    h.resize(m);
    unordered_map<int, int> mp;
    for (int i = 0; i < m; ++i) {
        h[i] = points[i];
        g[points[i] - 1] = i + 1;
        mp[points[i]] = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        if (g[i] == -1) {
            auto itr = mp.find(f[i]);
            assert(itr != mp.end());
            g[i] = itr->second;
        }
    }

    cout << m << endl;
    for (int i = 0; i < n; ++i) {
        cout << g[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        cout << h[i] << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    f.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
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