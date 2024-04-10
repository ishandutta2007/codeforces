#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

vector<int> bestArea(vector<vector<int>> &grid, int n){
    vector<int> ans(10, 0);
    vector<vector<int>> small(10, vector<int>(n, INF));
    vector<vector<int>> large(10, vector<int>(n, -INF));
    vector<int> top(10, INF);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            small[grid[i][j]][i] = min(small[grid[i][j]][i], j);
            large[grid[i][j]][i] = max(large[grid[i][j]][i], j);
            top[grid[i][j]] = min(top[grid[i][j]], i);
        }
    }
    for(int d = 0; d<10; d++){
        if(top[d] == INF) continue;
        for(int i = top[d]; i<n; i++){
            if(small[d][i] == INF) continue;
            ans[d] = max(ans[d], (n-1-small[d][i])*(i-top[d]));
            ans[d] = max(ans[d], (large[d][i])*(i-top[d]));
            ans[d] = max(ans[d], (large[d][i]-small[d][i])*(i));
            
        }
    }
    return ans;
}

void rot(vector<vector<int>>& grid, int n){
    vector<vector<int>> tmp = grid;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) grid[i][j] = tmp[j][n-1-i];
    }
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<n; j++) grid[i][j] = s[j]-'0';
    }
    vector<int> ans(10, 0);
    for(int i = 0; i<4; i++){
        vector<int> tmp = bestArea(grid, n);
        for(int j = 0; j<10; j++) ans[j] = max(ans[j], tmp[j]);
        rot(grid, n);
    }
    for(int i = 0; i<10; i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}