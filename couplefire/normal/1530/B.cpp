#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        grid[0][0] = grid[0][m-1] = grid[n-1][0] = grid[n-1][m-1] = 1;
        for(int i = 2; i<m-2; i+=2)
            grid[0][i] = 1, grid[n-1][i] = 1;
        for(int i  = 2; i<n-2; i+=2)
            grid[i][0] = 1, grid[i][m-1] = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++)
                cout << grid[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
}