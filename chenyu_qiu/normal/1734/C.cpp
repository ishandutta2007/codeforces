#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> d[N];

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    vector<bool> used(n + 1);
    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '0') {
            for (auto x : d[i]) {
                if (!used[x]) {
                    ans += x;
                    break;
                }
            }
        } else {
            for (auto x : d[i]) {
                used[x] = 1;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            d[j].emplace_back(i);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}