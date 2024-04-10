/**
 *  created: 04/04/2021, 22:22:07
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n;
string a, b;

string func(const string &s) {
    string res;
    int cnt = 0, tot0 = 0, tot1 = 0;
    for (char c : s) {
        tot0 += c == '0';
        tot1 += c == '1';
    }
    for (int i = n - 1; i >= 0; --i) {
        int x = s[i] - '0';
        if (x ^ cnt) {
            if (tot0 == tot1) {
                cnt ^= 1;
            }
        }
        res += '0' + (x ^ cnt);
        tot0 -= s[i] == '0';
        tot1 -= s[i] == '1';
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        a = read();
        b = read();
        if (func(a) == func(b)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}