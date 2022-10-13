#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    int n; cin >> n;
    vector<pair<int, int>> Sort;
    set<int> S;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (S.find(A[i]) != S.end()) {
            cout << -1 << endl;
            return 0;
        }
        S.insert(A[i]);
        Sort.emplace_back(A[i], i);
    }

    sort(Sort.begin(), Sort.end());
    vector<int> perm(n);

    for (int i = 0; i < n; ++i) {
        perm[Sort[i].second] = Sort[(i + 1) % n].second;
    }

    for (auto x : perm) {
        cout << A[x] << " ";
    }
    cout << endl;

    return 0;
}