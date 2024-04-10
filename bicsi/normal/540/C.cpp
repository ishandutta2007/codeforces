#include <iostream>
#include <cstdio>

using namespace std;
typedef int var;

bool CAN[2000][2000];
char A[2000][2000];

var di[] = {1, 0, -1, 0},
    dj[] = {0, 1, 0, -1};

void dfs(var i, var j) {
    CAN[i][j] = 1;
    for(var d=0; d<4; d++) {
        var ni = i + di[d],
            nj = j + dj[d];

        if(!CAN[ni][nj] && A[ni][nj] == '.')
            dfs(ni, nj);
    }
}

bool check(var i, var j) {
    var vec = 0;
    for(var d=0; d<4; d++) {
        if(CAN[i+di[d]][j+dj[d]])
            vec ++;
        }
    if(A[i][j] == '.') {
        return vec >= 2;
    } else {
        return vec >= 1;
    }
}

int main()
{

    // freopen("debug.in", "r", stdin);
    // freopen("debug.out", "w", stdout);

    var n, m, bi, bj, ei, ej;

    cin>>n>>m;
    for(var i=1; i<=n; i++) {
        cin>>A[i] + 1;
    }

    cin>>bi>>bj;

    dfs(bi, bj);

    cin>>ei>>ej;

    cout << ( check(ei, ej) ? "YES" : "NO");


}