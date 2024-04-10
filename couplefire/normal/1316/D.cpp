#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
int n;
pair<int, int> grid[MAXN][MAXN];
bool processed[MAXN][MAXN] = {0};
char gg[MAXN][MAXN];

void dfs(int x, int y, int px, int py){
    if(grid[x][y] != make_pair(px, py)) return;
    processed[x][y] = 1;
    if(x + 1 < n && grid[x+1][y] == make_pair(px, py) && !processed[x+1][y]){
        gg[x+1][y] = 'U';
        dfs(x+1, y, px, py);
    }
    if(y + 1 < n && grid[x][y+1] == make_pair(px, py) && !processed[x][y+1]){
        gg[x][y+1] = 'L';
        dfs(x, y+1, px, py);
    }
    if(x - 1 >= 0 && grid[x-1][y] == make_pair(px, py) && !processed[x-1][y]){
        gg[x-1][y] = 'D';
        dfs(x-1, y, px, py);
    }
    if(y - 1 >= 0 && grid[x][y-1] == make_pair(px, py) && !processed[x][y-1]){
        gg[x][y-1] = 'R';
        dfs(x, y-1, px, py);
    }
}

bool single(int x, int y){
    if(x + 1 < n && grid[x+1][y] == make_pair(-2, -2)){
        gg[x][y] = 'D';
        return false;
    }
    if(y + 1 < n && grid[x][y+1] == make_pair(-2, -2)){
        gg[x][y] = 'R';
        return false;
    }
    if(x - 1 >= 0 && grid[x-1][y] == make_pair(-2, -2)){
        gg[x][y] = 'U';
        return false;
    }
    if(y - 1 >= 0 && grid[x][y-1] == make_pair(-2, -2)){
        gg[x][y] = 'L';
        return false;
    }
    return true;
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            int a, b; cin >> a >> b;
            --a; --b;
            grid[i][j] = {a, b};
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(processed[i][j]) continue;
            if(grid[i][j] != make_pair(-2, -2)){
                gg[grid[i][j].first][grid[i][j].second]='X';
                dfs(grid[i][j].first, grid[i][j].second, grid[i][j].first, grid[i][j].second);
            }
            else{
                if(!single(i, j)) dfs(i, j, grid[i][j].first, grid[i][j].second);
            }
            if(!processed[i][j]){
                cout << "INVALID" << endl;
                exit(0);
            }
        }
    }
    cout << "VALID" << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << gg[i][j];
        }
        cout << endl;
    }
}