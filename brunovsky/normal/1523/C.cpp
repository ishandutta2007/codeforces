#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    assert(a[0] == 1);

    vector<vector<int>> ans;
    ans.push_back({1});

    for (int i = 1; i < N; i++) {
        vector<int> nxt = ans.back();
        if (a[i] == 1) {
            nxt.push_back(1);
        } else {
            while (nxt.back() != a[i] - 1) {
                nxt.pop_back();
            }
            nxt.back() = a[i];
        }
        ans.push_back(move(nxt));
    }

    for (int i = 0; i < N; i++) {
        string s;
        for (int n : ans[i]) {
            s += to_string(n) + ".";
        }
        s.pop_back();
        cout << s << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}