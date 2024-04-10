#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<int> v;
    for (int x = 1; x <= 9; ++x) {
        int y = 0;
        for (int i = 0; i < 9; ++i) {
            y = y * 10 + x;
            v.push_back(y);
        }
    }
    sort(v.begin(), v.end());
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << upper_bound(v.begin(), v.end(), n) - v.begin() << "\n";
    }
    return 0;
}