#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int n;
    cin >> n;
    vector<int> u(n), s(n);
    vector<vector<int>> students(n);
    vector<int> num_students(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i], u[i]--;
        num_students[u[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        students[u[i]].push_back(s[i]);
    }
    for (int i = 0; i < n; i++) {
        sort(begin(students[i]), end(students[i]), greater<int>{});
    }
    vector<long> ans(n + 1);
    for (int i = 0; i < n; i++) {
        vector<long> prefix(num_students[i] + 1);
        for (int j = 0; j < num_students[i]; j++) {
            prefix[j + 1] = prefix[j] + students[i][j];
        }
        for (int k = 1; k <= num_students[i]; k++) {
            // mk <= num_students[i] < (m+1)k <=> m <= num_students[i]/k < m + 1
            int m = num_students[i] / k;
            ans[k] += prefix[m * k];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (i > 1 ? " " : "") << ans[i];
    }
    cout << endl;
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