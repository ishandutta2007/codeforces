/**
 *  created: 13/06/2021, 18:35:49
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, m;
string a[max_n], ans[max_n];

bool ok(int x) {
    bool f = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = "RW"[x ^ (i % 2) ^ (j % 2)];
            f &= a[i][j] == '.' || a[i][j] == ans[i][j];
        }
    }
    return f;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            a[i] = read();
            ans[i] = a[i];
        }
        if (ok(0) || ok(1)) {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                puts(ans[i].c_str());
            }
        } else {
            puts("NO");
        }
    }
    return 0;
}