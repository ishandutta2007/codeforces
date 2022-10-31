#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s; cin >> s;
    int n = s.length();
    auto check = [&](string t) {
        int n = t.length();
        for (int j = 0; j < t.length(); j++) if (t[j] != t[n-1-j]) return 0;
        return 1;
    };
    for (int i = 0; i < n; i++) {
        string t; t.resize(n);
        for (int j = 0; j < n; j++) t[j] = s[(i+j)%n];
        if (s == t || !check(t)) continue;
        return puts("1"), 0;
    }
    for (int i = 0; i < n/2; i++) {
        string t; t.resize(i+1);
        for (int j = 0; j <= i; j++) t[j] = s[j];
        if (!check(t)) return puts("2"), 0;
    }
    puts("Impossible");
    return 0;
}