/**
 *  created: 13/06/2021, 18:58:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int n, d[max_n];
set<pair<int, int>> ans;
vector<int> all[2];

void add_edge(int u, int v) {
    if (u > v) {
        swap(u, v);
    }
    ans.insert({u, v});
}

void query(int v) {
    cout << "? " << v + 1 << endl;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (d[i] == 1) {
            add_edge(v, i);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cin >> n;
    query(0);
    for (int i = 1; i < n; ++i) {
        all[d[i] % 2].push_back(i);
    }
    int f = 0;
    if (all[1].size() < all[0].size()) {
        f = 1;
    }
    for (int v : all[f]) {
        query(v);
    }
    assert(ans.size() == n - 1);
    cout << "!" << endl;
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << endl;
    }
    return 0;
}