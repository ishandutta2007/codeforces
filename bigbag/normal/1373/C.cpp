#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        string s = read();
        int bal = 0, mn = 0;
        long long ans = s.length();
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '+') {
                ++bal;
            } else {
                --bal;
            }
            if (bal < mn) {
                mn = bal;
                ans += i + 1;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}