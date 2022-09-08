#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, max_c = 26, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n, mx[2][max_c];
string s;

void get(const string &s, int mx[]) {
    for (int i = 0; i < max_c; ++i) {
        mx[i] = 0;
    }
    for (int i = 0; i < s.length(); ++i) {
        int cnt = 1;
        while (i + 1 < s.length() && s[i] == s[i + 1]) {
            ++i;
            ++cnt;
        }
        mx[s[i] - 'a'] = max(mx[s[i] - 'a'], cnt);
    }
}

void write(int tp) {
    for (int i = 0; i < max_c; ++i) {
        if (mx[tp][i]) {
            printf("(%c %d) ", i + 'a', mx[tp][i]);
        }
    }
    printf("\n");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    s = read();
    get(s, mx[0]);
    //write(0);
    --n;
    while (n--) {
        s = read();
        get(s, mx[1]);
        for (char c = 0; c < max_c; ++c) {
            if (mx[1][c] == s.length()) {
                mx[0][c] = min(1LL * inf, 1LL * s.length() * (mx[0][c] + 1) + mx[0][c]);
            } else if (mx[0][c] == 0) {
                mx[0][c] = mx[1][c];
            } else {
                int pr = 0, suf = 0;
                while (s[pr] == c + 'a') {
                    ++pr;
                }
                while (s[s.length() - suf - 1] == c + 'a') {
                    ++suf;
                }
                mx[0][c] = max(mx[1][c], pr + suf + 1);
            }
        }
        //write(0);
    }
    int ans = 0;
    for (int i = 0; i < max_c; ++i) {
        ans = max(ans, mx[0][i]);
    }
    printf("%d\n", ans);
    return 0;
}