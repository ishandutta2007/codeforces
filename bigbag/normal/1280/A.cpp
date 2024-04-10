#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, mod = 1000000007;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int t, x;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        s = read();
        int len = s.length();
        for (int i = 0; i < x; ++i) {
            int cnt = s[i] - '1';
            int add_len = (len + mod - i - 1) % mod;
            len += mul(cnt, add_len);
            len %= mod;
            if (s.length() < x) {
                string add = s.substr(i + 1);
                while (cnt--) {
                    if (s.length() < x) {
                        s += add;
                    }
                }
            }
        }
        printf("%d\n", len);
    }
    return 0;
}