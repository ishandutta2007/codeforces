#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int grid[n+1][m+1];
        for(int i = 0; i<n; i++){
            string s; cin >> s;
            for(int j = 0; j<m; j++) grid[i+1][j+1] = (s[j] == '*')?1:0;
        }
        int prefix[n+1][m+1];
        for(int i = 1; i<=n; i++){
            prefix[i][0] = 0;
            for(int j = 1; j<=m; j++) prefix[i][j] = prefix[i][j-1]+grid[i][j];
        }
        // cout << prefix[3][4] << endl;
        int ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                int sz = 0;
                for(int k = i; k<=n; k++){
                    if(j+sz <= m && j-sz-1 >= 0 && prefix[k][j+sz]-prefix[k][j-sz-1] == 2*sz+1) sz++;
                    else break;
                }
                // cout << i << " " << j << " " << sz << endl;
                ans += sz;
            }
        }
        cout << ans << endl;
    }
}