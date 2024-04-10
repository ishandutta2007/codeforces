#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int D[1000], G[1000][1000], Viz[1000];
queue<int> Q;
int n;

int bfs(int wh) {
    Viz[1] = 1;
    Q.push(1);
    D[1] = 1;

    while(!Q.empty()) {
        int top = Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
            if(G[top][i] == wh && !Viz[i]) {
                D[i] = D[top] + 1;
                Viz[i] = 1;
                Q.push(i);
            }

    }

    return D[n] - 1;

}

int main() {
    #ifndef ONLINE_JUDGE
    //freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int m, a, b;
    cin>>n>>m;

    while(m--) {
        cin>>a>>b;
        G[a][b] = G[b][a] = 1;
    }

    if(G[1][n] == 1) {
        cout << bfs(0);
    } else {
        cout << bfs(1);
    }



    return 0;
}