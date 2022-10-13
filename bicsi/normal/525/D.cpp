#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstdio>

using namespace std;
typedef int var;

#define fin cin
#define fout cout

var dx[] = {0, 1, 0, -1, 1, -1, 1, -1},
    dy[] = {-1, 0, 1, 0, 1, 1, -1, -1};
var m, n;

    #define MAXN 2050
    #define mp make_pair
    bool A[MAXN][MAXN];
    bool INST[MAXN][MAXN];

stack<pair<var, var> > ST;

bool check(var i, var j) {
    if(A[i][j-1] == 1 && A[i+1][j-1] == 1 && A[i+1][j] == 1)
        return true;
    if(A[i+1][j] == 1 && A[i+1][j+1] == 1 && A[i][j+1] == 1)
        return true;
    if(A[i][j+1] == 1 && A[i-1][j+1] == 1 && A[i-1][j] == 1)
        return true;
    if(A[i-1][j] == 1 && A[i-1][j-1] == 1 && A[i][j-1] == 1)
        return true;
    return false;
}

void solve() {

    while(!ST.empty()) {

        auto top = ST.top();
        ST.pop();

        var i=top.first, j=top.second;
        INST[i][j] = 0;

        if(!i || !j) continue;
        if(i>m||j>n) continue;

        if(check(i, j)) {
            A[i][j] = 1;
            for(var d=0; d<8; d++) {
                if(!A[i+dx[d]][j+dy[d]] && !INST[i+dx[d]][j+dy[d]]) {
                    ST.push(mp(i+dx[d], j+dy[d]));
                    INST[i+dx[d]][j+dy[d]] = 1;
                }
            }
        }
    }
}

char st[5000];

int main() {

    //freopen("4.in", "r", stdin);
    //freopen("4.out", "w", stdout);


    char a;
    scanf("%d %d", &m, &n);

    for(var i=1; i<=m; i++) {
        scanf("%s", &st);
        for(var j=1; j<=n; j++) {
            char a=st[j-1];
            if(a == '.')
                A[i][j] = 1;
        }
    }

    for(var i=1; i<=m; i++) {
        for(var j=1; j<=n; j++) {
            if(!A[i][j]) {
                ST.push(mp(i, j));
                INST[i][j] = 1;
            }
        }
    }

    solve();

    for(var i=1; i<=m; i++) {
        for(var j=1; j<=n; j++) {
            if(A[i][j]) printf(".");
            else printf("*");
        }
        printf("\n");
    }

    return 0;
}