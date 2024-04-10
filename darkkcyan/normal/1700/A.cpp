#include <bits/stdc++.h>
using namespace std;

int main() {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int64_t n, m;
        cin >> n >> m;
        
        int64_t ans = m * (m - 1) / 2 + n * (m + n * m) / 2;
        cout << ans << '\n';
    }
}