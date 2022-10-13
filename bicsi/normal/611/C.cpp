#include <bits/stdc++.h>

using namespace std;

#define MAXN 5000005

typedef unsigned long long ull;


char A[600][600];
int D[600][600], E[600][600];

int main() {

    //freopen("debug.in", "r", stdin);


    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>A[i] + 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1];
            E[i][j] = E[i-1][j] + E[i][j-1] - E[i-1][j-1];
            if(A[i][j] == '.' && A[i-1][j] == '.') D[i][j] += 1;
            if(A[i][j] == '.' && A[i][j-1] == '.') E[i][j] += 1;
        }
    }

    int q, i1, j1, i2, j2;

    cin >> q;
    while(q--) {
        cin>>i1>>j1>>i2>>j2;
        int r = D[i2][j2] - D[i1][j2] - D[i2][j1-1] + D[i1][j1-1];
            r += E[i2][j2] - E[i1-1][j2] - E[i2][j1] + E[i1-1][j1];
        cout << r << '\n';
    }



    return 0;
}