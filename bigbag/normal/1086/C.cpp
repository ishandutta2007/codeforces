#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;
const int max_k = 133;

int t, k, n;
char s[max_n], a[max_n], b[max_n];
char p[max_k], rp[max_k];

void proc() {
    for (char c = 'a'; c < 'a' + k; ++c) {
        if (!p[c]) {
            for (char c2 = 'a'; c2 < 'a' + k; ++c2) {
                if (!rp[c2]) {
                    p[c] = c2;
                    rp[c2] = c;
                    break;
                }
            }
        }
    }
}

bool solve() {
    memset(p, 0, sizeof(p));
    memset(rp, 0, sizeof(rp));
    int last = -1;
    for (int i = 0; i <= n; ++i) {
        if (i == n) {
            last = n;
            break;
        }
        if (p[s[i]] == 0) {
            for (char c = a[i] + 1; c < 'a' + k; ++c) {
                if (rp[c] == 0) {
                    last = i;
                }
            }
        } else if (p[s[i]] < a[i]) {
            break;
        } else if (p[s[i]] > a[i]) {
            last = i;
            break;
        }
        if (p[s[i]] == 0 && rp[a[i]] == 0) {
            p[s[i]] = a[i];
            rp[a[i]] = s[i];
        } else if (p[s[i]] != a[i]) {
            break;
        }
    }
    if (last == -1) {
        return false;
    }
    memset(p, 0, sizeof(p));
    memset(rp, 0, sizeof(rp));
    //cout << "$" << last << endl;
    for (int i = 0; i < last; ++i) {
        if (p[s[i]] == 0 && rp[a[i]] == 0) {
            p[s[i]] = a[i];
            rp[a[i]] = s[i];
        }
    }
    if (last == n) {
        return true;
    }
    if (p[s[last]] == 0) {
        for (char c = a[last] + 1; c < 'a' + k; ++c) {
            if (rp[c] == 0) {
                p[s[last]] = c;
                rp[c] = s[last];
                break;
            }
        }
    }
    for (int i = last + 1; i < n; ++i) {
        if (!p[s[i]]) {
            for (char c = 'a'; c < 'a' + k; ++c) {
                if (!rp[c]) {
                    p[s[i]] = c;
                    rp[c] = s[i];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        s[i] = p[s[i]];
    }
    if (strcmp(s, b) <= 0) {
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s%s%s", &k, s, a, b);
        n = strlen(s);
        if (solve()) {
            proc();
            puts("YES");
            for (char c = 'a'; c < 'a' + k; ++c) {
                printf("%c", p[c]);
            }
            puts("");
        } else {
            puts("NO");
        }
    }
    return 0;
}