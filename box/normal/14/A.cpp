#include <iostream>
#include <algorithm>
using namespace std;

char matr[55][55];

int main() {
    int n, m; cin >> n >> m;
    int icu=m-1, xcu=0, iru=n-1, xru=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matr[i][j];
            if(matr[i][j] == '*') {
                icu = min(icu, j);
                xcu = max(xcu, j);
                iru = min(iru, i);
                xru = max(xru, i);
            }
        }
    }
    for(int i=iru;i<=xru; i++) {
        for(int j=icu;j<=xcu;j++) {
            cout << matr[i][j];
        }
        cout << endl;
    }
}