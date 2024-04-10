#include <bits/stdc++.h>
using namespace std;
#define BLOCK 320
int n, m, q;
char arr[100005][12];
bool visited[100005][12] = {{0}};
pair<int, int> dest[100005][12];

void dfs(int x, int y){
    if(visited[x][y]) return;
    visited[x][y] = 1;
    if(y == m-1 && arr[x][y] == '>'){
        dest[x][y] = {x, y+1};
        return;
    }
    if(y == 0 && arr[x][y] == '<'){
        dest[x][y] = {x, y-1};
        return;
    }
    if((x % BLOCK == 0) && arr[x][y] == '^'){
        dest[x][y] = {x-1, y};
        return;
    }
    if(arr[x][y] == '>' && arr[x][y+1] == '<'){
        dest[x][y] = {-2, -2};
        return;
    }
    if(arr[x][y] == '<' && arr[x][y-1] == '>'){
        dest[x][y] = {-2, -2};
        return;
    }

    if(arr[x][y] == '>') {dfs(x, y+1);dest[x][y] = dest[x][y+1];}
    if(arr[x][y] == '<') {dfs(x, y-1);dest[x][y] = dest[x][y-1];}
    if(arr[x][y] == '^') {dfs(x-1, y);dest[x][y] = dest[x-1][y];}
}

int main(){
    cin >> n >> m >> q;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<m; j++) arr[i][j]=s[j];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dfs(i, j);
        }
    }
    while(q--){
        // cout << dest[1][0].first << " " << dest[1][0].second << endl;
        char type; cin >> type;
        if(type == 'A'){
            int x, y; cin >> x >> y;
            --x; --y;
            int curx = x, cury = y;
            while(!(curx >= n || curx < 0 || cury >= m || cury < 0)){
                int tx = curx, ty = cury;
                curx = dest[tx][ty].first;
                cury = dest[tx][ty].second;
            }
            cout << curx+1 << " " << cury+1 << endl;
        }
        else{
            int x, y; char c; cin >> x >> y >> c;
            --x; --y;
            int lvl = x/BLOCK;
            arr[x][y] = c;
            for(int i = lvl*BLOCK; i<min(lvl*BLOCK+BLOCK, n); i++){
                for(int j = 0; j<m; j++) visited[i][j] = 0;
            } 
            for(int i = lvl*BLOCK; i<min(lvl*BLOCK+BLOCK, n); i++){
                for(int j = 0; j<m; j++) dfs(i, j);
            }
        }
    }
}