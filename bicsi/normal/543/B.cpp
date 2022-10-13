#include <bits/stdc++.h>
using namespace std;
typedef int var;

#define MAXN 3005
bool Viz[MAXN];

var D[MAXN][MAXN];
vector<var> G[MAXN];

queue<var> Q;
var bfs(var start, var To[]) {
    memset(Viz, 0, sizeof(Viz));

    Viz[start] = 1; Q.push(start);
    while(!Q.empty()) {
        var node = Q.front();
        Q.pop();
        for(auto vec : G[node]) {
            if(!Viz[vec]) {
                Viz[vec] = 1;
                To[vec] = To[node] + 1;
                Q.push(vec);
            }
        }
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, m, s1, d1, l1, s2, d2, l2, a, b;
    cin>>n>>m;

    for(var i=0; i<m; i++) {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cin>>s1>>d1>>l1>>s2>>d2>>l2;
    for(var i=1; i<=n; i++)
        bfs(i, D[i]);

    var mind = 10000;

    if(D[s1][d1] <= l1 && D[s2][d2] <= l2)
        mind = min(m, D[s1][d1] + D[s2][d2]);

    for(var i=1; i<=n; i++)
    for(var j=1; j<=n; j++) {
        if(D[s1][i] + D[i][j] + D[j][d1] <= l1 &&
           D[s2][i] + D[i][j] + D[j][d2] <= l2) {
                mind = min(mind, D[s1][i] + D[s2][i] + D[i][j] + D[j][d1] + D[j][d2]);
           }
        if(D[s1][i] + D[i][j] + D[j][d1] <= l1 &&
           D[s2][j] + D[j][i] + D[i][d2] <= l2) {
                mind = min(mind, D[s1][i] + D[s2][j] + D[i][j] + D[j][d1] + D[i][d2]);
           }
    }

    cout<<max(-1, m - mind);

    return 0;
}