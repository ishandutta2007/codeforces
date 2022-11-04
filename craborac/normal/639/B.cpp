#include <bits/stdc++.h>

using namespace std;

int n, d, h;
vector<pair<int, int> > e;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> h;
    if (d < h) {
        cout << "-1\n";
        return 0;
    }
    if (d > 2 * h) {
        cout << "-1\n";
        return 0;
    }
    if (d == h) {
        if (n >= h + 1) {
            if (n > h + 1 && h == 1) {
                cout << "-1\n";
                return 0;
            }
            for (int i = 0; i < h; i++) {
                cout << i + 1 << " " << i + 2 << "\n";
            }
            for (int i = 0; i < n - h - 1; i++) {
                cout << "2 " << h + 2 + i << "\n";
            }
            return 0;
        }
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < h; i++) {
        e.push_back({i + 1, i + 2});
    }
    int ind = h;
    e.push_back({1, h + 2});
    for (int i = 0; i < d - h - 1; i++) {
        e.push_back({h + 2 + i, h + 3 + i});
    }
    if (e.size() + 1 > n) {
        cout << "-1\n";
        return 0;
    }
    while (e.size() + 1 < n) {
        e.push_back({1, e.size() + 2});
    }
    for (int i = 0; i < n - 1; i++) {
        cout << e[i].first << " " << e[i].second << "\n";
    }
}