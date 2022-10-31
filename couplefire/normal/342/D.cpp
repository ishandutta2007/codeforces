// https://codeforces.com/problemset/problem/342/D
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define MOD 1000000007
char grid[3][MAXN];
int n;

long long solve(){
    long long dp[MAXN][8] = {0};
    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int mask = 0; mask<8; mask++){
            if(((mask & (1)) && grid[0][i] == 'X') || ((mask & (2)) && grid[1][i] == 'X') || ((mask & (4)) && grid[2][i] == 'X')) continue;
            int newmask = mask;
            if(grid[0][i] == 'X') newmask |= 1;
            if(grid[1][i] == 'X') newmask |= 2;
            if(grid[2][i] == 'X') newmask |= 4;
            if(newmask == 0) dp[i][mask] += dp[i-1][1] + dp[i-1][4] + dp[i-1][7];
            else if(newmask == 1) dp[i][mask] += dp[i-1][6]+dp[i-1][0];
            else if(newmask == 2) dp[i][mask] += dp[i-1][5];
            else if(newmask == 3) dp[i][mask] += dp[i-1][4];
            else if(newmask == 4) dp[i][mask] += dp[i-1][3] + dp[i-1][0];
            else if(newmask == 5) dp[i][mask] += dp[i-1][2];
            else if(newmask == 6) dp[i][mask] += dp[i-1][1];
            else dp[i][mask] += dp[i-1][0];
            dp[i][mask] %= MOD;
        }
    }
    //cout << dp[n][0] << endl;
    return dp[n][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    pair<int, int> pos;
    for(int i = 0; i < 3; i++){
        string s; cin >> s;
        for(int j = 0; j<s.length(); j++){
            grid[i][j+1] = s[j];
            if(s[j] == 'O') pos = {i, j+1};
        }
    }
    grid[pos.first][pos.second]='X';
    long long ans = solve();
    if(pos.first == 1 && pos.second != 1 && pos.second != n){
        grid[0][pos.second] = 'X';
        grid[2][pos.second] = 'X';
        grid[0][pos.second-1] = 'X';
        grid[2][pos.second-1] = 'X';
        grid[0][pos.second+1] = 'X';
        grid[2][pos.second+1] = 'X';
        grid[1][pos.second-1] = 'X';
        grid[1][pos.second+1] = 'X';
        ans -= 2*solve();
        if(ans < 0) ans += MOD;
        if(ans < 0) ans += MOD;
    }
    cout << ans << endl;
}