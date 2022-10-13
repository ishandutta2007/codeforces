#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>

using namespace std;
typedef int var;

char Let[6];
char A[100][100];

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, m;
    cin>>n>>m;

    for(var i=1; i<=n; i++) {
        for(var j=1; j<=m; j++) {
            cin>>A[i][j];
        }
    }

    var cnt = 0;

    for(var i=1; i<n; i++) {
        for(var j=1; j<m; j++) {
            Let[0] = A[i][j];
            Let[1] = A[i+1][j];
            Let[2] = A[i][j+1];
            Let[3] = A[i+1][j+1];

            sort(Let, Let+4);
            if(!strcmp(Let, "acef"))
                cnt++;
        }
    }

    cout<<cnt;


    return 0;
}