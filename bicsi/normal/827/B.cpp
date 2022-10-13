#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, k; cin >> n >> k;

    vector<pair<int, int>> sol;
    for (int i = 1; i <= k; ++i) {
        sol.emplace_back(0, i);
    }

    int now = 0, diam = 2;
    for (int i = k + 1; i < n; ++i) {
        sol.emplace_back(i, i - k);
        if (now <= 1) diam += 1;
        now = (now + 1) % k;
    }

    cout << diam << endl;
    for (auto p : sol) {
        cout << p.first+1 << " " << p.second+1 << '\n';
    }

    return 0;
}