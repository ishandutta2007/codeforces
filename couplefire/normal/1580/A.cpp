#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int n, m, grid[N][N], psum[N], vpsum[N][N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i<=n; ++i){
        string s; cin >> s;
        for(int j = 0; j<m; ++j)
            if(s[j]=='1') grid[i][j+1] = 1;
            else grid[i][j+1] = 0;
    }
    for(int i = 1; i<=m; ++i)
        for(int j = 1; j<=n; ++j)
            vpsum[i][j] = grid[j][i]+vpsum[i][j-1];
    int ans = 1e9;
    for(int i = 1; i<=n; ++i)
        for(int j = i+4; j<=n; ++j){
            psum[0] = 0;
            for(int a = 1; a<=m; ++a)
                psum[a] = psum[a-1]+(vpsum[a][j-1]-vpsum[a][i])+(!grid[i][a])+(!grid[j][a]);
            int cur = 1e9;
            for(int a = 4; a<=m; ++a){
                cur = min(cur, -psum[a-3]+(j-i-1-(vpsum[a-3][j-1]-vpsum[a-3][i])));
                ans = min(ans, cur+psum[a-1]+(j-i-1-(vpsum[a][j-1]-vpsum[a][i])));
            }
        }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}