#include <bits/stdc++.h>

using namespace std;

void print(long ans) {
    if (ans / 10 != 0) print(ans / 10);
    ans %= 10;
    for (int i = 0; i < ans; ++i) cout << '+'; cout << '.';
    for (int i = 0; i < ans; ++i) cout << '-';
}

int main() {
    string s; cin >> s;
    string t;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (isdigit(s[i])) t += s[i];
        else t += string(" ") + s[i] + " ";
    }
    long ans = 0;
    stringstream x; x << t;
    long num;
    int cursg = 1;
    while (x >> num) {
        ans += cursg * num;
        if (x >> s) {
            if (s == "+") cursg = 1;
            else cursg = -1;
        }
    }
    for (int i = '0'; i--; )cout << '+';
    print(ans);

    return 0;
}