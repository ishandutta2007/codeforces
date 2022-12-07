#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> x, y; // x[color] --> x coords of elements with that colour
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int c;
            cin >> c;
            x[c].push_back(i);
            y[c].push_back(j);
        }
    }
    for(int i = 1; i <= 100000; i++) {
        if(x.find(i) != x.end()) {
            sort(x[i].begin(), x[i].end());
            sort(y[i].begin(), y[i].end());
        }
    }
    int ans = 0;
    for(int i = 1; i <= 100000; i++) {
        if(x.find(i) != x.end()) {
            vector <int> p;
            int z = x[i].size();
            p.push_back(x[i][0]);
            for(int j = 1; j < z; j++) {
                p.push_back(p[j - 1] + x[i][j]);
            }
            for(int j = 0; j < z; j++) {
                // Until index j, subtract sum. After that, add.
                ans += ((j + 1) * x[i][j] - p[j]) + (p[z - 1] - p[j]) - (z - j - 1) * x[i][j];
            }
            p.clear();
            z = y[i].size();
            p.push_back(y[i][0]);
            for(int j = 1; j < z; j++) {
                p.push_back(p[j - 1] + y[i][j]);
            }
            for(int j = 0; j < z; j++) {
                // Until index j, subtract sum. After that, add.
                ans += ((j + 1) * y[i][j] - p[j]) + (p[z - 1] - p[j]) - (z - j - 1) * y[i][j];
            }
        }
    }
    cout << ans/2;

    
    return 0;
}