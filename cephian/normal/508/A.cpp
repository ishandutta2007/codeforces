#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool g[1005][1005];
int n, m, k;

bool bounds(int i, int j) {
    return i>0 && j>0 && i<=m && j<=k;
}

bool ok(int i, int j) {
    if(!bounds(i, j) || !bounds(i+1, j+1))
        return false;
    return g[i][j] && g[i+1][j] && g[i][j+1] && g[i+1][j+1];
}

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> m >> k >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= k ;++j)
            g[i][j] = 0;
    int ans = 0;
    
    for(int k = 1; k <= n; ++k) {
        int i, j;
        cin >> i >> j;
        g[i][j] = 1;
        
        if(!ans && (ok(i, j) || ok(i-1, j) || ok(i-1, j-1) || ok(i, j-1)))
            ans = k;
    }
    
    cout << ans << "\n";
    
    return 0;
}