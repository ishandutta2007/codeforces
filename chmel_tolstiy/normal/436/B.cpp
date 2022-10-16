#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> f(n);
    for (int i = 0; i < n; ++i) cin >> f[i];
    
    vector<int> res(m);
    
    for (int i = 1; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (f[i][j] == 'L') {
            int col = j - i;
            if (col >= 0) res[col]++;
        }
        if (f[i][j] == 'R') {
            int col = j + i;
            if (col < m) res[col]++;
        }
        if (f[i][j] == 'U' && i % 2 == 0) res[j]++;
    }
    
    for (int j = 0; j < m; ++j) cout << res[j] << ' ';
    cout << endl;
}

int main() {
    solve();
    return 0;
}