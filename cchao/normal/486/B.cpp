#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a[110][110], b[110][110];
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[i][j] = 1;
        }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) if(a[i][j] == 0) {
            for(int k = 0; k < n; ++k) b[k][j] = 0;
            for(int k = 0; k < m; ++k) b[i][k] = 0;
        }
    int c[110][110];
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        c[i][j] = 0;
        for(int k = 0; k < n; ++k) c[i][j] |= b[k][j];
        for(int k = 0; k < m; ++k) c[i][j] |= b[i][k];
        if(c[i][j] != a[i][j]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cout << b[i][j] << ' ';
        cout << endl;
    }
    return 0;
}