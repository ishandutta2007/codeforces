#include <stdio.h>
#include <vector>
using namespace std;
char d[55][55];
int N, M;
vector <int> conn[2550];
int chk[2550];
bool DFS(int node, int lvl) {
    chk[node] = lvl;
    int t;
    for(int i = 0; i < conn[node].size(); i++) {
        t = conn[node][i];
        if(chk[t] != 0) {
            if(chk[t] <= lvl-3) return true;
            continue;
        }
        if(DFS(t, lvl+1)) return true;
    }
    return false;
}       
int main() {
    int i, j, t;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++) scanf("%s", d[i]);
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            t = M*i+j;
            if(i != 0) {
                if(d[i-1][j] == d[i][j]) conn[t].push_back(t-M);
            }
            if(j != 0) {
                if(d[i][j-1] == d[i][j]) conn[t].push_back(t-1);
            }
            if(j != M-1) {
                if(d[i][j+1] == d[i][j]) conn[t].push_back(t+1);
            }
            if(i != N-1) {
                if(d[i+1][j] == d[i][j]) conn[t].push_back(t+M);
            }
        }
    }
    for(i = 0; i < N*M; i++) {
        if(chk[i] == -1) continue;
        if(DFS(i, 1)) {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}