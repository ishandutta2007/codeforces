#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >>n >> m;
    string grid[n];
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            string str = "";
            str += grid[i][j];
            str += grid[i-1][j];
            str += grid[i][j-1];
            str += grid[i-1][j-1];
            sort(str.begin(), str.end());
            ans += str == "acef";
        }
    }
    cout << ans << "\n";

    return 0;
}