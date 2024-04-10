#include <bits/stdc++.h>
using namespace std;
typedef int var;

var A[501], SUM[2][501][501];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, m, b, mod;
    cin>>n>>m>>b>>mod;
    for(var i=1; i<=n; i++)
        cin>>A[i];

    SUM[0][0][0] = 1;
    for(var i=1; i<=n; i++) {
        bool x = i & 1;
        SUM[x][0][0] = 1;
        for(var j=1; j<=m; j++) {
            for(var k=0; k<A[i]; k++)
                SUM[x][j][k] = SUM[x^1][j][k];
            for(var k=A[i]; k<=b; k++) {
                SUM[x][j][k] = SUM[x][j-1][k-A[i]] + SUM[x^1][j][k];
                if(SUM[x][j][k] >= mod) SUM[x][j][k] -= mod;
            }
        }
    }

    var total = 0;
    for(var t=0; t<=b; t++) {
        total += SUM[n & 1][m][t];
        if(total >= mod)
            total -= mod;
    }
    cout<<total;

    return 0;
}