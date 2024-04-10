/**
 *  created: 25/01/2021, 17:19:32
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, a[max_n][max_n], row[max_n], col[max_n];
string A[max_n], B[max_n];

bool check() {
    for (int it = 0; it < 2; ++it) {
        col[0] = it;
        for (int i = 0; i < n; ++i) {
            row[i] = col[0] ^ a[i][0];
        }
        for (int i = 1; i < n; ++i) {
            col[i] = row[0] ^ a[0][i];
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = col[j] ^ row[i];
                ok &= x == a[i][j];
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            A[i] = read();
        }
        for (int i = 0; i < n; ++i) {
            B[i] = read();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = A[i][j] - '0';
                int y = B[i][j] - '0';
                a[i][j] = x ^ y;
            }
        }
        if (check()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}