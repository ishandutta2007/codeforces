#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> II;

int main() {
    int N;
    cin >> N;
    vector<bool> taken(2 * N, false);
    vector<int> ans(2 * N);
    vector<II> pairs;
    vector<vector<int>> strength(2 * N);
    for(int n = 0; n < 2 * N; ++n) {
        for(int i = 0; i < n; ++i) {
            pairs.emplace_back(n, i);
            int s;
            cin >> s;
            strength[n].push_back(s);
        }
    }
    sort(pairs.begin(), pairs.end(), [&](II& a, II& b) {
        return strength[a.first][a.second] < strength[b.first][b.second];
    });
    while(pairs.size()) {
        int i, j;
        tie(i, j) = pairs.back();
        pairs.pop_back();
        if(!taken[i] && !taken[j]) {
            taken[i] = taken[j] = true;
            ans[i] = j + 1;
            ans[j] = i + 1;
        }
    }
    for(int n = 0; n < 2 * N; ++n) {
        cout << ans[n] << ' ';
    }
    cout << '\n';
}