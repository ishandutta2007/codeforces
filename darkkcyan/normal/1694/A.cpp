#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> m >> n;  // I miss read
        if (n >= m) {
            for (int i = 0; i < m; ++i) cout << "10";
            cout << string(n - m, '1');
        } else {
            for (int i = 0; i < n; ++i) cout << "01";
            cout << string(m - n, '0');
        }
        cout << '\n';
    }
    return 0;
}