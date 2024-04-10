#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> cnt(26);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }

    for (int i = 0; i < k; ++i) {
        int t = n / k;
        int c = 0;
        for (c = 0; c < t && cnt[c]; ++c);
        cout << char(c + 'a');
        for (int x = 0; x < c; ++x) {
            --cnt[x];
        }
    }

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}