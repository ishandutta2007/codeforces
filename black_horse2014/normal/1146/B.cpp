#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    string s; cin >> s;
    int n = s.length();
    string t;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') t.push_back(s[i]);
        if (i + 1 + t.length() == n) {
            for (int j = i + 1; j < n; j++) {
                if (t[j - i - 1] != s[j]) {
                    return puts(":("), 0;
                }
            }
            for (int j = 0; j <= i; j++) putchar(s[j]);
            puts("");
            return 0;
        }
    }
    return puts(":(");
    return 0;
}