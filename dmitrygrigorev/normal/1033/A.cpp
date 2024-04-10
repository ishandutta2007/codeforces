#include <bits/stdc++.h>
#define int long long
using namespace std;
int ax, ay, bx, by, cx, cy, n;
bool used[1000][1000];
void dfs(int x, int y){
    used[x][y] = true;
    for (int i=-1; i <= 1; i++){
        for (int j=-1; j <= 1; j++){
            int X = x+i, Y = y+j;
            if (X < 0 || X >= n || Y < 0 || Y >= n) continue;
            if (used[X][Y]) continue;
            if (Y==ay) continue;
            if (X == ax) continue;
            int dx = abs(X-ax), dy = abs(Y-ay);
            if (dx==dy) continue;
            dfs(X, Y);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) used[i][j] = false;
    ax--, ay--, bx--, by--, cx--, cy--;
    dfs(bx, by);
    if (used[cx][cy]) cout << "YES";
    else cout << "NO";
}