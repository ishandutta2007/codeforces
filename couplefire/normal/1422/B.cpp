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
        long long grid[n+1][m+1];
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++) cin >> grid[i+1][j+1];
        }
        long long ans = 0;
        for(int i = 1; i<=n/2; i++){
            for(int j = 1; j<=m/2; j++){
                long long num[4];
                long long sum = 0;
                num[0] = grid[i][j], num[1] = grid[n+1-i][j], num[2] = grid[i][m+1-j], num[3] = grid[n+1-i][m+1-j];
                sort(num, num+4);
                sum = num[1];
                ans += abs(num[0]-sum);
                ans += abs(num[1]-sum);
                ans += abs(num[2]-sum);
                ans += abs(num[3]-sum);
            }
        }
        if(n % 2 == 1){
            int i = (n+1)/2;
            for(int j = 1; j<=m/2; j++){
                long long a = grid[i][j];
                long long b = grid[i][m+1-j];
                long long sum = (a+b)/2;
                ans += abs(a-sum)+abs(b-sum);
            }
        }
        if(m%2 == 1){
            int j = (m+1)/2;
            for(int i = 1; i<=n/2; i++){
                long long a = grid[i][j];
                long long b = grid[n+1-i][j];
                long long sum = (a+b)/2;
                ans += abs(a-sum)+abs(b-sum);
            }
        }
        cout << ans << endl;
    }
}