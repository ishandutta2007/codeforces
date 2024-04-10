#include <bits/stdc++.h>

using namespace std;
typedef int var;

var V[300000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, k;
    cin>>n>>k;

    var op = 0, m;
    while(k--) {
        cin>>m;
        for(var i=1; i<=m; i++) {
            cin>>V[i];
        }

        var i;
        for(i=1; i<m && V[i+1] == i+1; i++);
        var matr = 0;
        for(;i<=m; i++) { matr++; op++; }
        op--;
        op += matr;
    }

    cout<<op - 1;

    return 0;
}