#include <bits/stdc++.h>

using namespace std;
typedef int var;
typedef pair<var, var> Pair;

#define MAXN 600

Pair Parent[MAXN][30][30];
var DP[MAXN][30][30];
var Cost[MAXN][2][30];

#define FOR(a) for((a)=0; (a)<='z'-'a'; (a)++)

void afis(Pair p, var n, var m) {
    if(n > 1) afis(Parent[n][p.first][p.second], n-1, m);

    for(var i=0; i<m; i++) {
        cout<<( (i & 1) ? char(p.second+'a') : char(p.first+'a') );
    }
    cout<<'\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    var n, m;
    char val;
    var a, b, c, d;
    cin>>n>>m;
    for(var i=1; i<=n; i++) {
        for(var j=0; j<m; j++) {
            cin>>val;
            FOR(c)
                if(c+'a' != val)
                    Cost[i][j & 1][c] ++;
        }
    }

    FOR(a) FOR(b) {
        if(a == b) DP[1][a][b] = 1000000;
        else DP[1][a][b] = Cost[1][0][a] + Cost[1][1][b];
    }

    for(var i=2; i<=n; i++) {
        FOR(a) FOR(b) {

            DP[i][a][b] = 1000000;
            if(a == b) continue;

            FOR(c) FOR(d) {
                if(a == c || b == d || c == d) continue;
                if(DP[i][a][b] > DP[i-1][c][d]) {
                    DP[i][a][b] = DP[i-1][c][d];
                    Parent[i][a][b] = {c, d};
                }
            }
            DP[i][a][b] += Cost[i][0][a] + Cost[i][1][b];
        }
    }

    Pair pp;
    var best = 1000000;

    FOR(a) FOR(b) {
        if(DP[n][a][b] < best) {
            best = DP[n][a][b];
            pp = {a, b};
        }
    }

    cout<<best<<'\n';

    afis(pp, n, m);
    return 0;
}