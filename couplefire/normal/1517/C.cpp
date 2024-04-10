#include <bits/stdc++.h>
using namespace std;
#define MAXN 505

int n;
int grid[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, -1, 0};
int cnt, num;

void dfs(int x, int y){
    if(!cnt) return;
    cnt--;
    grid[x][y] = num;
    for(int i = 0; i<4; i++){
        int tx = x+dx[i], ty = y+dy[i];
        if(!tx || tx > n) continue;
        if(!ty || ty > n) continue;
        if(grid[tx][ty]) continue;
        dfs(tx, ty);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> grid[i][i];
    for(int i = 1; i<=n; i++){
        cnt = num = grid[i][i];
        dfs(i, i);
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++) cout << grid[i][j] << " ";
        cout << endl;
    }
}