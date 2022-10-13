#include<bits/stdc++.h>
using namespace std;
typedef int64_t var;

const var MOD = 1e9 + 7;
var Comb[1005][1005];
var C[1006];

var Sol(var k, var n) {
    if(k == 0) return 1;
    int64_t rez = 1LL * Comb[n-1][C[k]-1] * Sol(k-1, n-C[k]);
    rez %= MOD;
    return rez;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    Comb[0][0] = 1;
    for(var i=1; i<=1000; i++) {
        Comb[i][0] = 1;
        for(var j=1; j<=i; j++) {
            Comb[i][j] = Comb[i-1][j] + Comb[i-1][j-1];
            if(Comb[i][j] >= MOD) Comb[i][j] -= MOD;
        }
    }

    var n, k;
    var sum = 0;
    cin>>k;
    for(var i=1; i<=k; i++) {
        cin>>C[i];
        sum += C[i];
    }

    cout<<Sol(k, sum);
    return 0;
}