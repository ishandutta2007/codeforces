#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] < a[i]) {
            cout << "NO\n";
            return;
        }
        if (b[i] > a[i]) {
            int j = i == n ? 1 : (i + 1);
            if (b[j] < b[i] - 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}