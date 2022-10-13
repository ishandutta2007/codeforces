#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

char M[2000][2000];
int Viz[2000][2000], Size[2000000];


int dx[] = {0, 1 , 0, -1},
    dy[] = {1, 0, -1, 0};

void dfs(int i, int j, int cc) {
    Viz[i][j] = cc;
    Size[cc] += 1;

    for(int d=0; d<4; d++) {
        int ni = i + dx[d],
            nj = j + dy[d];
        if(!Viz[ni][nj] && M[ni][nj] == '.')
            dfs(ni, nj, cc);
    }
}

int main() {

    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin >> M[i] + 1;

    int cc = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(!Viz[i][j] && M[i][j] == '.')
                dfs(i, j, ++cc);
        }
    }


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            if(M[i][j] == '.') putchar( '.' );
            else {
                int out = 0;
                unordered_set<int> Take;
                for(int d=0; d<4; d++) {
                    int cc = Viz[i+dx[d]][j+dy[d]];
                    if(Take.find(cc) == Take.end()) out += Size[cc];
                    Take.insert(cc);
                }
                putchar('0' + (out + 1) % 10);
            }
            putchar('\n');
    }

}