#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> a(2*n, vector<int>(2*n));
        for(int i = 0; i<2*n; ++i)
            for(int j = 0; j<2*n; ++j)
                cin >> a[i][j];
        long long res = 0;
        for(int i = n; i<2*n; ++i)
            for(int j = n; j<2*n; ++j)
                res += a[i][j];
        cout << res+min({a[0][n], a[0][2*n-1], a[n-1][n], a[n-1][2*n-1], a[n][0], a[n][n-1], a[2*n-1][0], a[2*n-1][n-1]}) << '\n';
    }
}