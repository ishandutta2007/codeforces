#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n;
string a, b;

int solve() {
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            return -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 20; ++i) {
        char c = 'a' + i;
        int mn = inf, mx = -inf;
        for (int j = 0; j < n; ++j) {
            if (a[j] == c && b[j] != c) {
                mn = min(mn, (int) b[j]);
                mx = max(mx, (int) b[j]);
            }
        }
        if (mn == inf) {
            continue;
        }
        ++ans;
        char to = mn;
        if (mn == mx) {
            to = mn;
        }
        for (int j = 0; j < n; ++j) {
            if (a[j] == c && b[j] != c) {
                a[j] = to;
            }
        }
        //cout << a << endl;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        a = read();
        b = read();
        printf("%d\n", solve());
    }
    return 0;
}