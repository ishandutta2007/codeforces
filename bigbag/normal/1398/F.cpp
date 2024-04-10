#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, nxt[max_n][2], ans[max_n];
char s[max_n];
vector<int> all[max_n];
int to[max_n];

int get_to(int pos) {
    if (pos == to[pos]) {
        return pos;
    }
    return to[pos] = get_to(to[pos]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        n = 1000000;
        for (int i = 0; i < n; ++i) {
            s[i] = '?';
        }
    } else {
        scanf("%d%s", &n, s);
    }
    nxt[n][0] = nxt[n][1] = n;
    for (int i = n - 1; i >= 0; --i) {
        nxt[i][0] = nxt[i][1] = i;
        if (s[i] == '0' || s[i] == '?') {
            nxt[i][0] = nxt[i + 1][0];
        }
        if (s[i] == '1' || s[i] == '?') {
            nxt[i][1] = nxt[i + 1][1];
        }
        int mx = max(nxt[i][0], nxt[i][1]) - i;
        all[mx].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        to[i] = i;
    }
    to[n] = n;
    for (int x = 1; x <= n; ++x) {
        int pos = 0;
        while (pos < n) {
            pos = get_to(pos);
            if (pos == n) {
                break;
            }
            pos += x;
            ++ans[x];
        }
        for (int pos : all[x]) {
            to[pos] = pos + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}