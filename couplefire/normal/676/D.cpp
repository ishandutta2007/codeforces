#include <bits/stdc++.h>
using namespace std;

int r1, c1, r2, c2;

int add(int i, int j){return ((i+j)%4+4)%4;}

struct node{
    int r, c, ro;
    int dir[4] = {0};
    node(){}
    node(int rr, int cc, int rro, char ccc){
        r = rr;
        c = cc;
        ro = rro;
        if(ccc == '+'){
            dir[add(rro, 0)] = 1;
            dir[add(rro, 1)] = 1;
            dir[add(rro, 2)] = 1;
            dir[add(rro, 3)] = 1;
        }
        else if(ccc == '-'){
            dir[add(rro, 0)] = 1;
            dir[add(rro, 2)] = 1;
        }
        else if(ccc == '|'){
            dir[add(rro, 1)] = 1;
            dir[add(rro, 3)] = 1;
        }
        else if(ccc == '^'){
            dir[add(rro, 1)] = 1;
        }
        else if(ccc == '>'){
            dir[add(rro, 0)] = 1;
        }
        else if(ccc == '<'){
            dir[add(rro, 2)] = 1;
        }
        else if(ccc == 'v'){
            dir[add(rro, 3)] = 1;
        }
        else if(ccc == 'L'){
            dir[add(rro, 0)] = 1;
            dir[add(rro, 1)] = 1;
            dir[add(rro, 3)] = 1;
        }
        else if(ccc == 'R'){
            dir[add(rro, 2)] = 1;
            dir[add(rro, 1)] = 1;
            dir[add(rro, 3)] = 1;
        }
        else if(ccc == 'U'){
            dir[add(rro, 0)] = 1;
            dir[add(rro, 2)] = 1;
            dir[add(rro, 3)] = 1;
        }
        else if(ccc == 'D'){
            dir[add(rro, 0)] = 1;
            dir[add(rro, 1)] = 1;
            dir[add(rro, 2)] = 1;
        }
    }
};

int main(){
    //freopen("a.in", "r", stdin);
    int n, m; cin >> n >> m;
    node grid[n][m][4];
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<m; j++){
            char cc = s[j];
            for(int k = 0; k<4; k++){
                grid[i][j][k] = node(i, j, k, cc);
            }
        }
    }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         for(int k = 0; k<4; k++){
    //             cout << i << " " << j << " " << k << endl;
    //             for(auto a: adj[i][j][k]){
    //                 cout << a.r << " " << a.c << " " << a.ro << endl;
    //             }
    //             cout << endl;
    //         }
    //     }
    // }

    cin >> r1 >> c1 >> r2 >> c2;
    --r1; --c1; --r2; --c2;

    int dist[n][m][4];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            for(int k = 0; k<4; k++){
                dist[i][j][k] = INT_MAX;
            }
        }
    }
    dist[r1][c1][0] = 0;
    queue<node> q;
    q.push(grid[r1][c1][0]);
    while(q.size()){
        node nn = q.front();
        int i = nn.r;
        int j = nn.c;
        int k = nn.ro;
        q.pop();
        vector<node> ttt;
        ttt.push_back(grid[i][j][add(k,-1)]);
        if(i+1 < n){
            if(grid[i][j][k].dir[3] && grid[i+1][j][k].dir[1]) ttt.push_back(grid[i+1][j][k]);
        }
        if(i-1 >= 0){
            if(grid[i][j][k].dir[1] && grid[i-1][j][k].dir[3]) ttt.push_back(grid[i-1][j][k]);
        }
        if(j+1 < m){
            if(grid[i][j][k].dir[0] && grid[i][j+1][k].dir[2]) ttt.push_back(grid[i][j+1][k]);
        }
        if(j-1 >= 0){
            if(grid[i][j][k].dir[2] && grid[i][j-1][k].dir[0]) ttt.push_back(grid[i][j-1][k]);
        }
        for(int i = 0; i<ttt.size(); i++){
            node tt = ttt[i];
            if(dist[tt.r][tt.c][tt.ro]<INT_MAX) continue;
            dist[tt.r][tt.c][tt.ro] = dist[nn.r][nn.c][nn.ro]+1;
            q.push(tt);
        }
    }
    int ans = min({dist[r2][c2][0], dist[r2][c2][1], dist[r2][c2][2], dist[r2][c2][3]});
    if(ans == INT_MAX){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}