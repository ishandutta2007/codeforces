#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = 1e18;
int32_t main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    int dx, dy;
    cin >> x >> y >> dx >> dy;
    char matrix[n][m];
    for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> matrix[i][j];
    int cost[n][m];
    for (int i=0; i < n; i++) for (int j=0; j < m; j++) cost[i][j] = INF;
    cost[x-1][y-1] = 0;
    queue<pair<int, int> > a, b;
    a.push({x-1, y-1});
    int ctr = 0;
    while (a.size()){
        while (a.size()){
            pair<int, int> p = a.front();
            a.pop();
            for (int sx = -1; sx <= 1; sx++){
                for (int sy=-1; sy <= 1; sy++){
                    if (abs(sx) + abs(sy) == 2) continue;
                    if (cost[p.first][p.second] < ctr) continue;
                    int X = p.first+sx, Y = p.second+sy;
                    if (X < 0 || X >= n || Y < 0 || Y >= m) continue;
                    if (matrix[X][Y] == '*') continue;
                    int cc = 0;
                    if (sx == 0 && sy==-1) cc = 1;
                    if (cost[X][Y] <= ctr+cc) continue;
                    //if (X == 2 && Y==0) cout << cc << endl;
                    if (cc == 0){
                        cost[X][Y] = cost[p.first][p.second];
                        a.push({X, Y});
                    }
                    else{
                        cost[X][Y] = cost[p.first][p.second]+1;
                        b.push({X, Y});
                    }
                }
            }
        }
        ctr++;
        a = b;
        b = {};
    }
    int ans = 0;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            int kek = cost[i][j];
            int coord = (y-1) - kek;
            int sas = abs(coord-(j));
            //cout << i << " " << j << " " << kek << " " << sas << endl;
            if (kek <= dx && sas <= dy) ans++;
            //if (kek <= dx && sas <= dy) cout << "!!!" << i << " " << j << endl;
        }
    }
    cout << ans;
}