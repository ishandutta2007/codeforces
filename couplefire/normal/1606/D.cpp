#include <bits/stdc++.h>
using namespace std;

int ckmin(int &a, int b){return a>b?a=b:a;}
int ckmax(int &a, int b){return a<b?a=b:a;}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j)
            cin >> grid[i][j];
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int a, int b){return grid[a][0]<grid[b][0];});
    vector<vector<int>> pre[2][2];
    for(int i = 0; i<2; ++i)
        for(int j = 0; j<2; ++j)
            pre[i][j] = vector<vector<int>>(n, vector<int>(m));
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j){
            pre[0][0][i][j] = grid[id[i]][j];
            if(i>0) ckmax(pre[0][0][i][j], pre[0][0][i-1][j]);
            if(j>0) ckmax(pre[0][0][i][j], pre[0][0][i][j-1]);
        }
    for(int i = n-1; i>=0; --i)
        for(int j = 0; j<m; ++j){
            pre[1][0][i][j] = grid[id[i]][j];
            if(i<n-1) ckmin(pre[1][0][i][j], pre[1][0][i+1][j]);
            if(j>0) ckmin(pre[1][0][i][j], pre[1][0][i][j-1]);
        }
    for(int i = 0; i<n; ++i)
        for(int j = m-1; j>=0; --j){
            pre[0][1][i][j] = grid[id[i]][j];
            if(i>0) ckmin(pre[0][1][i][j], pre[0][1][i-1][j]);
            if(j<m-1) ckmin(pre[0][1][i][j], pre[0][1][i][j+1]);
        }
    for(int i = n-1; i>=0; --i)
        for(int j = m-1; j>=0; --j){
            pre[1][1][i][j] = grid[id[i]][j];
            if(i<n-1) ckmax(pre[1][1][i][j], pre[1][1][i+1][j]);
            if(j<m-1) ckmax(pre[1][1][i][j], pre[1][1][i][j+1]);
        }
    for(int i = 0; i<n-1; ++i)
        for(int j = 0; j<m-1; ++j)
            if(pre[0][0][i][j]<pre[1][0][i+1][j] && pre[1][1][i+1][j+1]<pre[0][1][i][j+1]){
                cout << "YES" << '\n';
                vector<int> bruh(n);
                for(int a = 0; a<n; ++a)
                    if(a<=i) bruh[id[a]] = 1;
                    else bruh[id[a]] = 0;
                for(int a = 0; a<n; ++a)
                    if(bruh[a]) cout << 'B';
                    else cout << 'R';
                cout << ' ' << j+1 << '\n';
                return;
            }
    cout << "NO" << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}