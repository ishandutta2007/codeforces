#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

char s[100][100];
char d[100][100];
int f[100][100];
int c[100][100];
int n, m;

int u[15][15];

bool check() {
    memset(u, 0, sizeof u);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j] != '.') {
        if (s[i][j] == s[i+1][j]) {
            int a = c[i][j];
            int b = c[i+1][j];
            if (u[a][b]) return false;
            u[a][b] = u[b][a] = 1;
        }
        if (s[i][j] == s[i][j+1]) {
            int a = c[i][j];
            int b = c[i][j+1];
            if (u[a][b]) return false;
            u[a][b] = u[b][a] = 1;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    memcpy(d, s, sizeof s);

    int curA = 0;
    int curB = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (d[i][j] != '.') {
            d[i][j] = d[i+1][j] = d[i][j+1] = d[i+1][j+1] = '.';
            int k = curA;

            if (s[i][j] == s[i+1][j]) curA++;
            if (s[i][j] == s[i][j+1]) curA++;
            if (s[i+1][j] == s[i+1][j+1]) curA++;
            if (s[i][j+1] == s[i+1][j+1]) curA++;

            if (curA != k) {
                f[i][j] = f[i+1][j] = f[i][j+1] = f[i+1][j+1] = -curA;
            } else {
                f[i][j] = f[i+1][j] = f[i][j+1] = f[i+1][j+1] = ++curB;
            }
        }
    }

    for (int i = 0; i < n && false; i++) {
        for (int j = 0; j < m; j++) 
            printf("%3d", f[i][j]);
        printf("\n");
    }
    
    assert(curA <= 7);

    vector<int> v(curB);
    for (int i = 0; i < 7; i++) v[i] = i+1;
    for (int i = 7; i < v.size(); i++) v[i] = 7 - (i-7);
    sort(v.begin(), v.end());

    int res = 0;
    do {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (!f[i][j]) continue;
            if (f[i][j] < 0) c[i][j] = -f[i][j];
            if (f[i][j] > 0) c[i][j] = v[f[i][j]-1];
        }
        res += check();
        if (check()) {
            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (c[i][j]) d[i][j] = '0' + c[i][j] - 1;
        }
    } while (next_permutation(v.begin(), v.end()));
    
    int C[10][10];
    C[0][0] = 1;
    for (int i = 1; i < 10; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = C[i-1][j] + C[i-1][j-1];
    }

    for (int i = 1; i <= curA; i++) res *= i;
    res *= C[7][curA];
    cout << res << endl;
    for (int i = 0; i < n; i++) 
        cout << d[i] << endl;
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();
    return 0;
}