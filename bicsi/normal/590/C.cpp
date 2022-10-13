#include <bits/stdc++.h>

using namespace std;


int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};

queue<pair<int, int>> Q[4];
int D[4][1005][1005], Viz[4][1005][1005];
int Good[1005][1005], Land[1005][1005], State[1005][1005];

void bfs(int t) {
    while(!Q[t].empty()) {
        auto top = Q[t].front();
        Q[t].pop();

        for(int d=0; d<4; d++) {
            int newx = top.first + dx[d];
            int newy = top.second + dy[d];

            if(!Viz[t][newx][newy] && Good[newx][newy]) {
                Q[t].push({newx, newy});
                D[t][newx][newy] = D[t][top.first][top.second] + Land[newx][newy];
                Viz[t][newx][newy] = 1;
            }
        }
    }
}

int main() {

    int n, m;
    char ch;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) {
        cin>>ch;

        Good[i][j] = 1;
        if(ch == '1') { Q[1].push({i, j}); Viz[1][i][j] = 1; State[i][j] = 1;}
        if(ch == '2') { Q[2].push({i, j}); Viz[2][i][j] = 1; State[i][j] = 2;}
        if(ch == '3') { Q[3].push({i, j}); Viz[3][i][j] = 1; State[i][j] = 3;}
        if(ch == '#') { Good[i][j] = 0; }
        if(ch == '.') { Land[i][j] = 1; }
    }

    for(int i=1; i<=3; i++)
        bfs(i);

    int Best[4][4];

    for(int k=1; k<=3; k++)
    for(int l=1; l<=3; l++) Best[k][l] = 500000000;

    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) {
        for(int k=1; k<=3; k++) {
            if(State[i][j] == k) {
                for(int l=1; l<=3; l++) {
                    if(Viz[l][i][j])
                    Best[k][l] = min(Best[k][l], D[l][i][j]);
                }
            }
        }
    }

    int best = 500000000;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) {
        if(Viz[1][i][j] == 1 && Viz[2][i][j] == 1 && Viz[3][i][j] == 1) {
            best = min(best, D[1][i][j] + D[2][i][j] + D[3][i][j] - 2*Land[i][j]);
        }
    }

    int I[4];
    I[1] = 1; I[2] = 2; I[3] = 3;

    do {
        best = min(best, Best[I[1]][I[2]] + Best[I[2]][I[3]]);
    } while(next_permutation(I+1, I+4));

    if(best == 500000000) best = -1;
    cout<<best;



    return 0;
}