/**
 *  created: 23/02/2021, 11:11:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_c = 26;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n, m, mn[2][max_n], nxt[max_n][max_c];
string a, b;

void calc(const string &a, const string &b, int res[max_n]) {
    for (int i = 0; i < max_c; ++i) {
        nxt[a.size()][i] = a.size();
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        copy(nxt[i + 1], nxt[i + 1] + max_c, nxt[i]);
        nxt[i][a[i] - 'a'] = i;
    }
    int pos = -1;
    for (int i = 0; i < b.size(); ++i) {
        pos = nxt[pos + 1][b[i] - 'a'];
        res[i] = pos;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    a = read();
    b = read();
    calc(a, b, mn[0]);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    calc(a, b, mn[1]);
    int ans = 0;
    for (int i = 0; i + 1 < m; ++i) {
        ans = max(ans, n - 1 - mn[1][m - 2 - i] - mn[0][i]);
    }
    printf("%d\n", ans);
    return 0;
}