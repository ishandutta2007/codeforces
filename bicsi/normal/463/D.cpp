#include<bits/stdc++.h>

using namespace std;
typedef int var;

#define MAXN 1005
#define MAXK 7

var n, k;
var Poz[MAXK][MAXN], A[MAXK][MAXN];
var DP[MAXN];

bool lss(var i, var j) {
    for(var t=1; t<=k; t++)
        if(Poz[t][i] >= Poz[t][j])
            return false;
    return true;
}

var Din(var val) {
    if(DP[val]) return DP[val];

    for(var i=1; i<=n; i++) {
        if(lss(val, i))
            DP[val] = max(DP[val], Din(i));
    }

    DP[val] ++;
    return DP[val];
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin>>n>>k;

    for(var i=1; i<=k; i++) {
        for(var j=1; j<=n; j++) {
            cin>>A[i][j];
            Poz[i][A[i][j]] = j;
        }
    }

    var rez = 0;
    for(var i=1; i<=n; i++) {
        rez = max(rez, Din(A[1][i]));
    }
    cout<<rez;


    return 0;
}