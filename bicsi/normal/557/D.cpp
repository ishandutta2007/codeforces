#include <bits/stdc++.h>

using namespace std;
typedef int var;
typedef pair<var, var> Pair;

#define MAXN 100005

bool Viz[MAXN], Color[MAXN];
vector<var> G[MAXN];
var No[2];
var D[MAXN];

bool dfs(var node, var color) {
    Viz[node] = 1;
    Color[node] = color;

    bool rez = 1;
    No[color]++;
    for(auto vec : G[node]) {
        if(!Viz[vec])
            rez &= dfs(vec, color^1);
        else if(Color[vec] == Color[node])
            return 0;
    }
    return rez;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, m;
    cin>>n>>m;

    if(m == 0) {
        cout<<"3 "<<1LL * n*(n-1)*(n-2) / 6;
    } else {
        bool no = 0;
        var a, b;
        for(var i=1; i<=m; i++) {
            cin>>a>>b;
            D[a]++;
            D[b]++;
            G[a].push_back(b);
            G[b].push_back(a);

            if(D[a] > 1 || D[b] > 1) no = 1;
        }

        if(no == 0) {
            cout<<"2 "<< 1LL * m * (n - 2);
            return 0;
        }


        int64_t total = 0;
        for(var i=1; i<=n; i++) {
            if(!Viz[i]) {
                No[0] = No[1] = 0;
                if(!dfs(i, 0)) {
                    cout<<"0 1";
                    return 0;
                }

                total += ((1LL * No[0] * (No[0] - 1)) + (1LL * No[1] * (No[1] - 1)))/2;
            }
        }

        cout<<"1 "<<total;
    }

    return 0;
}